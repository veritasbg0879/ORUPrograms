#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <time.h>
#include <malloc.h>
#include <omp.h>
#include <mpi.h>

//******************************************************************************

int do_transpose;
int n;

//******************************************************************************

double
msDiffTime(struct timespec start, struct timespec finish) {
    long seconds = finish.tv_sec - start.tv_sec; 
    long ns = finish.tv_nsec - start.tv_nsec; 
	    
    if (start.tv_nsec > finish.tv_nsec) { // clock underflow 
	--seconds; 
	ns += 1000000000; 
    } 
    return(1000.0*((double)seconds + (double)ns/(double)(1000000000)));
}

//******************************************************************************
//had some indenting things that didnt stay the same????

double **allocArray(int r, int c) {
    double **rc, *b;
    size_t sizeofArray = (size_t)r * (size_t)c * (size_t)sizeof(double);

    //fprintf(stderr, "sizeofArray is %ld\n", sizeofArray);
    b = (double *)malloc(sizeofArray);

    rc = (double **)malloc(r * sizeof(double *));

    rc[0] = b;
    for (int i = 1; i < r; i++) {
	    rc[i] = rc[i-1] + c;
    }
    

    return rc;
    
}

//******************************************************************************

void transpose(double **x) {
    int r, c;

    double t;

    for (r = 0; r < n; r++) {
    	for (c = r; c < n; c++) {
    	    t = x[c][r];
    	    x[c][r] = x[r][c];
    	    x[r][c] = t;
    	}
    }
    
}

//******************************************************************************

double dotProduct(double *a, double *b) {
    int i;
    double dp = 0;
    
    // Length of array is the size of the array in bytes
    // divided by the size of one member
    # pragma omp parallel for
    for (i = 0; i < n; i++) {
        dp += a[i] * b[i];
    }
    
    return(dp);
}

//******************************************************************************

void mm(double **A, double **B, double **C, int rowCount) {
    int i, j, k;
    double sum;
    sum = 0;

    if (do_transpose) {
        // do your code here using forward transpose of B
        transpose(B);
      	// followed by the matrix multiplication using dotProduct
        for (i = 0; i < rowCount; i++) {
            for (j = 0; j < n; j++) {
                C[i][j] = dotProduct(A[i], B[j]);
            }
        }
        // followed by using backward transpose B again to restore its original
        transpose(B);
	    // configuration
    } else {
        // do your code here to calculate C = A x B
        for (i = 0; i < rowCount; i++) {
            for (j = 0; j < n; j++) {
                for (k = 0; k < n; k++) {
                    sum += A[i][j] * B[k][j];
                }
                C[i][j] = sum;
                sum = 0;
            }
        }
    }

}

//********************************************************************************

int main(int argc, char** argv) {
    int nid;
    int nCount;
    int myRowCount, smallRowCount, largeRowCount, rem;
    int startPoint;
    int extra;

    size_t sizeofArrays;

    double **A, **B, **C;
    int i, j;
    struct timespec tStart, tStop;
    int nomatch,mmbroken;
    int AOffset, aLen;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &nid);
    MPI_Comm_size(MPI_COMM_WORLD, &nCount);

    if (argc < 3) {
	if (nid == 0) {
	    fprintf(stderr, "Usage: mm n t -- where n is the size of the matrix\n");
	    fprintf(stderr, "   and t is 0 for no-transpose and 1 for transpose\n");
	}
	exit(-1);
    }


    // Creates var n which is the size of the matrix, presumably
    sscanf(argv[1], "%d", &n);

    // Creates int do transpose which is whether or not we transpose
    sscanf(argv[2], "%d", &do_transpose);

    if (nid == 0) {
	fprintf(stdout, "n = %d\n", n);
	fprintf(stdout, "nCount = %d\n", nCount);
    }

    // calculate row counts
    myRowCount = n / nCount;
    extra = n % nCount;
    if (nid < extra) {
        myRowCount++;
    }
    startPoint = nid * myRowCount;
    
    if (nid >= extra) {
        startPoint += extra;
    } 


    // allocate memory for arrays A, B, C
    // different for node 0 vs all other nodes
    if (nid == 0) {
        A = allocArray(n, n);
        B = allocArray(n, n);
        C = allocArray(n, n);
        // initialize arrays
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                A[i][j] = 4.0;
                C[i][j] = -1;
                if (i == j) {
                    B[i][j] = 1;
                } 
                else {
                    B[i][j] = 0;
                }
            }
        }

                // calculate the random A for each node and send it to them

        for (i = 1; i < nCount; i++) {
            // Starting at 1, because that is the first node we broadcast to
            // Find Aoffset and aLen
            // Which is the startpoint and myrowcount of each node
            aLen = n / nCount;
            
            //extra doesnt change, so we can reuse it
            if (i < extra) {
                aLen++;
            }
            
            AOffset = aLen * i;

            if (i >= extra) {
                AOffset += extra;
            }

            MPI_Send(A[AOffset], aLen*n, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
        }       
    } else {
        // Allocate smaller Arrays, except B which is still the identity.
        A = allocArray(myRowCount, n);
        B = allocArray(n, n);
        C = allocArray(myRowCount, n);

        // receive my A matrix
        MPI_Recv(A[0], myRowCount*n, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    if ((n*n) > 2000000000) {
        int Bportion;
        int Bextra;
        int Bnum;
        // Bportion*n must be smaller than 2b
        // given col size, we need to find largest Bportion where Bportion*n is less than 2b
        // Bportion is the amount of rows we are sending
        Bportion = 2000000000 / n;
        // How many Bportions are in our matrix?
        Bnum = n / Bportion;
        Bextra = n % Bportion;
        // Bextra is the leftover rows 
        for (i = 0; i < Bnum; i++) {
            MPI_Bcast(B[i*Bnum], Bportion*n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
        }
        MPI_Bcast(B[(i+1)*Bnum], Bextra*n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    } else {
        MPI_Bcast(B[0], n*n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    }
    if (nid == 0) {
	clock_gettime(CLOCK_MONOTONIC, &tStart);
    }

    // do the matrix multiplication
    mm(A,B,C,myRowCount);

    // determine if my part of the multiplication was correct
    // host an MPI max reduction to determine if any node reports a bad C
    // They will send a 0 for good and a 1 for bad
    // if the max reduction is 1, we beefed it :(
    nomatch = 0;
    for (i = startPoint; i < myRowCount; i++) {
        for (j = 0; j < n; j++) {
            if (A[i-startPoint][j] != C[i][j]) {
                // The arrays do not match, mm was botched
                nomatch = 1;
                break;
            }
        }
        if (nomatch) {
            break;
        }
    }
    MPI_Reduce(&nomatch, &mmbroken, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    if (nid == 0) {
	clock_gettime(CLOCK_MONOTONIC, &tStop);
    }

    if (nid == 0) {
	char hostname[HOST_NAME_MAX];

	gethostname(hostname, HOST_NAME_MAX);
	fprintf(stdout, "Base %s with %d nodes for matrix size %d, Time to do mm: %6.5f minutes\n", hostname, nCount, n, msDiffTime(tStart, tStop)/60000.0);
        if (mmbroken) {
            printf("Matrix Multiplication failed\n");
        } else {
            printf("Correct Matrix Multiplication was a success!\n");
        }
    }

    MPI_Finalize();
    return(0);
}
