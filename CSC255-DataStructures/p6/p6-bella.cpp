/* Team 4
Bella Goodman, Kandice Coop
Dr. Wheat
CSC 255 Data Structures
Program 6 - Priority Queue
This is a program that uses the queue properties and a heap data structure to
set up a queue where all the biggest, most important numbers go on top and then
the peasant numbers go all the way at the bottom.
*/

#include <string>
#include <iostream>

#include "p6.h"

using namespace std;

//******************************************************************************

/*Bella
 set up a lil queue, which is just a fancy array, and initialize all the stuff*/


iPQ::iPQ(int n) {
    qCapacity = n;
    qCount = 0;
    a = new int[n];
}

//******************************************************************************

/*Bella
This is meant to delete the entire array to prevent memory leakage*/

iPQ::~iPQ() {
    delete[]a;
}

//******************************************************************************

/*Bella - so our index has children. don't know what other indexes it was 
gettin' around with, but its got two kids now. whats the height of the parent? 
depends on the height of the children. calculate it and give it back.
*/

int iPQ::parent(int index) const {
    return ((index - 1) / 2);
}

//******************************************************************************

/*Bella - the index has a left child so figure out the height of that one too!
it's not too hard, all you gotta do is multiply the index by two and add one. 
it ain't nothin but a thang.
*/

int iPQ::left(int index) const {
    return (index * 2) + 1;
}

//******************************************************************************

/*Bella
find the height of the right child too, its kinda useful to know it so we can
do our other calculations later. this height is just gonna be the index plus one
times two, which accounts for all the previous children and the left child so
we're sure we made it back to the right thing. */

int iPQ::right(int index) const {
    return ((index + 1) * 2);
}

//******************************************************************************

/*Bella - print everything out and organize it by level so its a little
easier on the eyes. going through each number to figure out what goes where is
no fun.
*/

void iPQ::printIt(int ind, int count) const {
    int level = ind;
    int ind2 = (1 << level) - 1;
    printIt(level + 1, count << 1);
    for (int i = ind2; (count > 0) && (i < qCount); (i++) && (count--)) {
	cout << a[i];
    }
    cout << endl;
}

//******************************************************************************

/*Bella
bUP the little index. is it greater than its parent?? send it up! if not, take
the L and stay there. */
 
void iPQ::bubbleUp(int index) {
    int par = parent(index);
    while ((index != 0) && (a[par] < a [index])) {
	swap(&a[par], &a[index]);
	index = par;
	par = parent(index);
    }
}

//******************************************************************************

/*Kandice
 If there is space in the priority queue it places the new value at the end of 
 the array and bubbles up the element. */
 
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

//******************************************************************************

/*Bella
heapify baby if the children are greater than the parent, we have a problem so 
push the parent down the list until it works (i absolutely snatched the code
from the algorithms book lol)*/

void iPQ::heapify(int index) {
    int lC = left(index);
    int rC = right(index);
    int largest = index;
    if ((lC < qCount) && (a[lC] > a[largest])) {
        largest = lC;
    }
    if ((rC < qCount) && (a[rC] > a[largest])) {
        largest = rC;
    }
    if (largest != index) {
        swap(&a[index], &a[largest]);
        heapify(largest);
    }

}

//******************************************************************************

/*Kandice
 This function removes the top element from the priority queue and returns it 
 in v
 */
 
bool iPQ::deq(int &v) {
   bool rc = false;
   if (qCount) {
        qCount--;
        v = a[0];
        a[0] = a[qCount];
        heapify(0);
        rc = true;
   }
   return rc;
}

//******************************************************************************
/*Bella - swap them!! without losing anything!!*/
void iPQ::swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

//******************************************************************************

/*Bella
this literally just sets the size to 0. it essentially tells the system that we 
have nothing in our list and we're good to write over it all.
*/

void iPQ::clear() {
    qCount = 0;
}

//******************************************************************************

/*Bella - call printit recursively starting from the tip top of the tree
*/

void iPQ::printIt() const {
    printIt(0, qCount);
}

//******************************************************************************

/*Bella
tell em what the qCount is so we know how many items there are in our priority
queue
*/

int iPQ::count() const {
    return qCount;
}

