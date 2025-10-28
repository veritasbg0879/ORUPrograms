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
	for (c = 0; c < n; c++) {
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

    // do your code here

    return(dp);
}

//******************************************************************************

void mm(double **A, double **B, double **C, int rowCount) {
    int i, j, k;
    double sum;

    if (do_transpose) {
        // do your code here using forward transpose of B
      	// followed by the matrix mulitiplication using dotProduct
        // followed by using backward transpose B again to restore its original
	// configuration
    } else {
        // do your code here to calculate C = A x B
    }

}

//********************************************************************************

int main(int argc, char** argv) {
    int nid;
    int nCount;
    int myRowCount, smallRowCount, largeRowCount, rem;
    size_t sizeofArrays;

    double **A, **B, **C;
    int i, j;
    struct timespec tStart, tStop;
    int nomatch;

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

    sscanf(argv[1], "%d", &n);
    sscanf(argv[2], "%d", &do_transpose);

    if (nid == 0) {
	fprintf(stdout, "n = %d\n", n);
	fprintf(stdout, "nCount = %d\n", nCount);
    }

    // calculate row counts


    // allocate memory for arrays A, B, C


    if (nid == 0) {
        // calculate the random A for each node and send it to them
        
        // calculate the B array (identity matrix)
        // and broadcast B to every node.
    } else {
        // receive my A matrix

        // Broadcast receive my B matrix
    }

    if (nid == 0) {
	clock_gettime(CLOCK_MONOTONIC, &tStart);
    }

    // do the matrix multiplication
    mm(....);


    if (nid == 0) {
        // determine if my part of the multiplication was correct

        // host an MPI max reduction to determine if any node reports a bad C
        // They will send a 1 for good and 2 for bad
    } else {
        // determine if my part of the multiplication was correct
	
        // Send a 1 for good in a MPI reduction
        // Send a 2 for bad in a MPI reduction
    }

    if (nid == 0) {
	clock_gettime(CLOCK_MONOTONIC, &tStop);
    }

    if (nid == 0) {
	char hostname[HOST_NAME_MAX];

	gethostname(hostname, HOST_NAME_MAX);
	fprintf(stdout, "Base %s with %d nodes for matrix size %d, Time to do mm: %6.5f minutes\n", hostname, nCount, n, msDiffTime(tStart, tStop)/60000.0);

        // print whether the matrix calculation was correct
    }

    MPI_Finalize();
}
