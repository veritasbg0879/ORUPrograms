/*Bella Goodman, Kandice Coop
Team 4
Dr. Wheat
CSC 255 Data Structures
P13 HuffPQ Final - Huffman Encoding
This is a program that implements the greedy algorithm, Huffman Encoding.
*/

#include <iostream>
#include "p13.h"

//******************************************************************************

//Bella - set up the PQ with the constructor

huffPQ::huffPQ(int n) {
	this -> pqSize = n;
	entries = new huffNode*[pqSize];
	qCount = 0;
}

//******************************************************************************

//Bella - set up the deconstructor

huffPQ::~huffPQ() {
	this -> pqSize = 0;
	delete []*entries;
	qCount = 0;
}

//******************************************************************************

//Bella - create the parent calculation for the indexes

int huffPQ::parent(int index) const {
    int rc = 0;
    if (index < 0) {
        rc = (index - 1) / 2;
    }
    return rc;
}

//******************************************************************************

//Bella - create the left child calculation!!

int huffPQ::left(int index) const {
    return (index * 2) + 1;	
}

//******************************************************************************

//Bella - maybe its got a right child

int huffPQ::right(int index) const {
    return ((index + 1) * 2);	
}

//******************************************************************************

//Bella - swappp function

void huffPQ::swap(huffNode *&x, huffNode *&y) {
	huffNode temp = *y;
	*y = *x;
	*x = temp;
}

//******************************************************************************

//Bella - bubbleUp but make it min heap

void huffPQ::bubbleUp(int index) {
    int par = parent(index);
    while ((index != 0) && (entries[par]->key > entries[index]->key)) {
		swap(entries[par], entries[index]);
		index = par;
		par = parent(index);
    }	
}

//******************************************************************************

//Bella - heapify for a minheap too

void huffPQ::heapify(int index) {
	int lC = left(index);
    int rC = right(index);
    int minimum = index;
    if (lC < qCount && entries[lC]->key < entries[minimum]->key) {
        minimum = lC;
    }
    if (rC < qCount && entries[rC]->key < entries[minimum]->key) {
        minimum = rC;
    }
    if (minimum != index) {
        swap(entries[index], entries[minimum]);
        heapify(minimum);
    }
}

//******************************************************************************

//Bella - enq the thingy, pop it into the array

bool huffPQ::enq(huffNode *v) {
    if (qCount < pqSize) {
        entries[qCount] = v;
        bubbleUp(qCount);
        qCount++;
    }
    return qCount < pqSize;
}

//******************************************************************************

//Bella - return the value at the end


bool huffPQ::deq(huffNode *&v) {
	bool rc = false;
    if (qCount > 0) {
        v = entries[0];
        qCount--;
        entries[0] = entries[qCount];
        heapify(0);
        rc = true;
    }
    return rc;
}


//******************************************************************************

//Bella - clear the queue

void huffPQ::clear() {
	qCount = 0;
}

int huffPQ::count() const {
	return qCount;
}
