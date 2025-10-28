#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

#include "p8.h"

//******************************************************************************

int const OneMillion = 1000000;

using namespace std;

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

void
doWork1(intList *list, int sortMethod) {
    // sortMethod = 0 for bubble, 1 for selection, 2 for insertion

    int i, v;
    bool rc;

    struct timespec tStart, tStop;

    // empty the list
    list->clear();

    srand(1); // seed so we get the same random numbers for each iteration of j
    for (i = 0; i < list->capacity(); i++) {
	v = rand() % OneMillion;
	rc = list->add(v);
	if (!rc) {
	    cerr << "add failed\n";
	}
    }

    cout << "***********************************************************\n";

    clock_gettime(CLOCK_MONOTONIC, &tStart);

    switch(sortMethod) {
	case 0:
	    list->bubbleSort();
	    break;

	case 1:
	    list->selectionSort();
	    break;

	case 2:
	    list->insertionSort();
	    break;

	case 3:
	    list->heapSort();
	    break;

	default:
	    cerr << "ERROR: bad sort index\n";
	    exit(-1);
    }

    clock_gettime(CLOCK_MONOTONIC, &tStop);

    cout << "The time to do the ";
    if (sortMethod == 0) {
	cout << "bubbleSort was: ";
    } else if (sortMethod == 1) {
	cout << "selectionSort was: ";
    } else if (sortMethod == 2) {
	cout << "insertionSort was: ";
    } else {
	cout << "heapSort was: ";
    }
    cout << setw(5) << msDiffTime(tStart, tStop) << "ms" << endl;

    if (list->isSorted()) {
	cout << "The list is sorted\n";
    } else {
	cout << "The list is NOT sorted\n";
    }

    list->printIt(20);
}

//******************************************************************************

int
main(int argc, char *argv[]) {
    intList *myL;
    int n;

    if (argc < 2) {
	cerr << "Usage: p7 n  -- where n is the size of the list\n";
	exit(-1);
    }
    sscanf(argv[1], "%d", &n);

    cout << "n = " << n << endl;

    myL = new intList(n);

    doWork1(myL, 0);
    doWork1(myL, 1);
    doWork1(myL, 2);
    doWork1(myL, 3);
}
