/* Team 4
Bella Goodman, Kandice Coop
Dr. Wheat
CSC 255 Data Structures
Program 6a - Priority Queue
This is a program that uses the queue properties and a heap data structure to
set up a queue where all the biggest, most important numbers go on top and then
the peasant numbers go all the way at the bottom.
*/

#include <string>
#include <iostream>
#include <cmath>

#include "iQ.h"
#include "cil.h"

using namespace std;

//******************************************************************************

/*Bella
 set up a lil queue, which is just a fancy array, and initialize all the stuff*/

iQ::iQ(int n) {
	theList = new cIntList(n);
}

//******************************************************************************

/*Bella
This is meant to delete the entire array to prevent memory leakage*/

iQ::~iQ() {
    delete theList;
}

//******************************************************************************

/*Kandice
 This function removes the top element from the priority queue and returns it
 in v
 */
 
bool iQ::deq(int &v) {
	return theList->deleteFirst(v);
}

//******************************************************************************

/*Kandice
 If there is space in the priority queue it places the new value at the end of
 the array and bubbles up the element. */
 
bool iQ::enq(int v) {
	return theList->add(v);
}

//******************************************************************************
/*Kandice
 This function swaps two ints by using pointers*/
void iQ::swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

//******************************************************************************

/*Kandice
*/

void iQ::printIt() {
	theList->printIt();
}

//******************************************************************************

/*Bella
this literally just sets the size to 0. it essentially tells the system that we
have nothing in our list and we're good to write over it all.
*/

void iQ::clear(){
    theList->clear();
}

//******************************************************************************

/*Bella
tell em what the qCount is so we know how many items there are in our priority
queue
*/

int iQ::count()const{
    return theList->count();
}

