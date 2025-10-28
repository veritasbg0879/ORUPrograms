/*
Bella Goodman, Kandice Coop
CSC 255 Data Structures, Wheat
P6A.cpp - Priority Queue
*/


#include <string>
#include <iostream>

#include "P6.h"

//******************************************************************************

/*Bella
set up a lil queue, which is just a fancy array, and initialize all the stuff*/

iPQ::iPQ(int n) {
	this -> qCapacity = n;
	qCount = 0;
	a = new int[qCapacity];
}

//******************************************************************************

//Bella
//this is meant to delete the entire array to prevent memory leakage 

iPQ::~iPQ() {
    delete[]a;
}

int iPQ::parent(int index) const {
	int rc = 0;
	if (index < 0) {
		rc = ((index - 1) / 2);
	}
	return rc;
}

int iPQ::left(int index) const {
	int rc = 0;
	if (index < qCount) {
		rc = (index * 2) + 1;
	}
	return rc;
}

int iPQ::right(int index) const {
	int rc = 0;
	if (index < qCount) {
		rc = ((index + 1) * 2);
	}
	return rc;
}

void iPQ::swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void iPQ::bubbleUp(int index) {
	int par = parent(index);
	while ((index != 0) && (a[par] , a[index])) {
		swap(&a[par], &a[index]);
		index = par;
		par = parent(index);
	}
}

void iPQ::heapify(int index) {
	int lC = left(index);
	int rC = right(index);
	int largest = index;
	if ((lC <= qCount) && (a[lC] > a[index])) {
		largest = lC;
	}
	if ((rC <= qCount) && (a[rC] > a[largest])) {
		largest = rC;
	}
	if (largest != index) {
		swap (&a[index], &a[largest]);
		heapify(largest);
	} 
}

bool iPQ::enq(int v) {
	bool rc = false;
	
	if (qCount < qCapacity) {
		a[qCount] = v;
		bubbleUp(qCount);
		qCount++;
		rc = true;
	}
	return rc;
}

bool iPQ::deq(int &v) {
	bool rc = false;
	if (qCount > 0) {
		v = a[0];
		a[0] = a[qCount];
		qCount--;
		heapify(0);
		rc = true;
	}
	return rc;
}

//******************************************************************************

/*Bella
this literally just sets the size to 0. it essentially tells the system that 
we have nothing in our list and we're good to write over it all.
*/

void iPQ::clear(){
	qCount = 0;
}

//******************************************************************************

/*Kandice
prints each element
*/

void iPQ::printIt()const{
	
}

//******************************************************************************

/*Bella
this is super basic. it fetches the qCount so we know how many full slots 
there are and how many empty slots there are. very useful if you have a set 
number of things to get in and you might be under or over.
*/

int iPQ::count()const{
    return qCount;
}