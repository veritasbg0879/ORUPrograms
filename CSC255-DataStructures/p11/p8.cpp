/*
Bella Goodman, Kandice Coop
Team 4
CSC 255 Data Structures, Wheat
P8.cpp - HeapSort
woop woop paste all of p7 in and make your edits so deleteAt actually exists.
then add in heapsort so we can compare the time it takes to all our other
sorts. I looked at the time for heapSort as compared to the others and my jaw
DROPPED. everything makes sense now :O
*/

#include <iostream>

#include "P8.h"

using namespace std;


/*Bella
make a new array using the listCapacity integer that gets passed in. also set 
the key of listCapacity and tell the computer that there's nothing in the list
(a lie) but we can now work with listSize.*/

intList::intList(int listCapacity) {
    this -> listCapacity = listCapacity;
    listSize = 0;
    a = new int[listCapacity];
}

//******************************************************************************

//Bella
//this is meant to delete the entire array to prevent memory leakage 

intList::~intList() {
    delete[]a;
}

//******************************************************************************

/*Bella
its a heheheap sort! set hS to lS and then call buildheap because uh its useful
to actually have a heap for heapSort? then like swap em around and stuff and
heapify and shrink hS so that the values are in ascending order! its actually
quite cool
*/

void intList::heapSort() {
    heapSize = listSize;
    buildHeap();
    while (--heapSize) {
        swap(a[0], a[heapSize]);
        heapify(0);
    }

}

//******************************************************************************

/*Kandice
set up the heap with the passed in values
*/

void intList::buildHeap() {
    heapSize = listSize;
    for (int i = listSize / 2 - 1; i >= 0; i--) {
        heapify(i);
    }
}

//******************************************************************************

/*Bella
heapify baby if the children are greater than the parent, we have a problem so
push the parent down the list until it works (i absolutely snatched the code
from the algorithms book lol)*/

void intList::heapify(int index) {
    int lC = left(index);
    int rC = right(index);
    int largest = index;
    if (lC < heapSize && a[lC] >a[largest]) {
        largest = lC;
    }
    if (rC < heapSize && a[rC] > a[largest]) {
        largest = rC;
    }
    if (largest != index) {
        swap(a[index], a[largest]);
        heapify(largest);
    }
}

//******************************************************************************

//Bella
//swap em around like a little dance or something

void intList::swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

//******************************************************************************

/*Bella - the index has a left child so figure out the height of that one too!
it's not too hard, all you gotta do is multiply the index by two and add one.
it ain't nothin but a thang.
*/

int intList::left(int index) const {
    return (index * 2) + 1;
}

//******************************************************************************

/*Bella
find the height of the right child too, its kinda useful to know it so we can
do our other calculations later. this height is just gonna be the index plus one
times two, which accounts for all the previous children and the left child so
we're sure we made it back to the right thing. */

int intList::right(int index) const {
    return ((index + 1) * 2);
}

//******************************************************************************

/*Bella
this returns a bool that's either true or false based on the availability in 
the list. it keeps the user from losing any data if they forget how many empty 
slots they have. it also gives us the handy-dandy feature of adding things to 
the top of the list for ~organization~ */

bool intList::insert(int key) {
    bool rc = false;
    if (listSize < listCapacity) {
	for (int i = listSize - 1; i >= 0; i--) {
	    a[i + 1] = a[i];					
	}
	a[0] = key;
	rc = true;
	listSize++;
    } 
    return rc;
}

//******************************************************************************

/*Bella
This is like the opposite of the above function; it adds (appends) things to 
the end of the list so we don't have to shuffle things around. It's the kind 
of thing you'd do if you were making a list of tasks and you totally forgot 
to add all your Calculus Homework.
*/

bool intList::add(int key){
    bool rc = false;
    if (listSize < listCapacity) {
        a[listSize] = key;
        rc = true;
        listSize++;
    }
    return rc;
}

//******************************************************************************

/*Bella
so it inserts a thing. maybe you don't want the thing to be at the beginning OR
the end for ~organizational~ purposes. This gives you the choice to put it 
absolutely a n y w h e r e in the list. cool beans
*/
bool intList::insertAt(int index, int key){
    bool rc = false;
    if ((listSize < listCapacity) && (index >= 0) && (index <= listSize)){
		for (int i = listSize - 1; i >= index; i--) {
			a[i + 1] = a[i];
		}
		a[index] = key;
		listSize++;
		rc = true;
    } 
    return rc;
}

//******************************************************************************

/*Kandice
delete the value at the passed in index and return it with the key variable
*/

bool intList::deleteAt(int index, int &key){
    bool rc = false;
    if (index >= 0 && index < listCapacity){
	key = a[index];
        for (int i = index; i < listSize - 2; i++) {
            a[i] = a[i + 1];
        }
        rc = true;
        listSize--;
    }
    return rc; 
}

//******************************************************************************

/*Bella
bubble bubble guppies bubble bubble guppies in all seriousness its a bubbleSort
it bubbles stuff around to get it to the right order. that means it just takes
the value at j and looks down the list to find something larger then it swaps
em if it is
*/

void intList::bubbleSort() {
    for (int i = 0; i < listSize; i++) {
	for (int j = listSize - 1; j > i; j--) {
	    if (a[j] < a[j - 1]) {
		swap(a[j], a[j - 1]);
	    }
	}
    }
}

//******************************************************************************

/* Kandice
This function sorts through the array comparing each element with the current 
minimum. The index is stored in minIndex. Swaps the element at i with the minimum
in found in the unsorted. 
*/

void intList::selectionSort() {
    for (int i = 0; i < listSize; i++) {
        int minIndex = i;
        for (int j = i + 1; j < listSize; j++) {
            if (a[j] < a [minIndex]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

//******************************************************************************

/* Kandice
This function sorts the array going through each element comparing it with its 
previous and swapping them if necessary arranging them from smaller. 
*/

void intList::insertionSort() {
    for (int i = 0; i < listSize - 1; i++) {
        for (int j = i + 1; j > 0; j--) {
            if (a[j - 1] > a[j]) {
                swap(a[j], a[j - 1]);
            } else {
                break;
            }
        }
    }
}

//******************************************************************************

/*Kandice
see if the list is sorted using a boolean value
*/

bool intList::isSorted() const {
    bool sorted = true;
    for (int index = 0; index < listSize - 1; index++) {
        if (a[index] > a[index + 1]) {
            sorted = false;
        }
    }
    return sorted;
}

//******************************************************************************

/*Bella
this literally just sets the size to 0. it essentially tells the system that 
we have nothing in our list and we're good to write over it all.
*/

void intList::clear(){
    listSize = 0;
}

//******************************************************************************

/*Bella
print it!! if we get too many numbers passed in ignore that sucker and print lS.
if they just want so many numbers out of the list then only print those numbers. 
include lS and lC and the last number if we don't print the whole list
*/

void intList::printIt(int n)const{
    if (n < listSize) {
	cout << "printIt with list size: " << count() << " capacity = " << 
        capacity() << endl;
	for (int i = 0; i < n; i++) {   //the one with a print statement
	    std::cout << "At pos " << i << " there is " << a[i] << std::endl;
	}
	cout << "At pos " << listSize - 1 << " there is " << a[listSize - 1] <<
        endl;
    } else {
	cout << "printIt with list size: " << count() << " capacity = " << 
        capacity() << endl;
	for (int i = 0; i < listSize; i++) {   //the one with a print statement
	    std::cout <<"At pos " << i << " there is " << a[i] << std::endl;
	}		
    }
}

//******************************************************************************

/*Bella
woop woop its the sound of tha police just kidding this searches the list for a 
specific key. if the key is found awesome it returns the index it was found at
but if not, oopsie dasies you get a -1 because you're wrong
*/

int intList::getIndex(int key) const {
    int rc = -1;
    for (int index = 0; index < listSize; index++){
		if (a[index] == key) {
			rc = index;
		}
    } 
    return rc;
}

//******************************************************************************

/*Bella
this tells us what the key is at the given index. if you forget whats in the 
list its great because it will just tell you.
*/

bool intList::readAt(int index, int &key) const {
    bool rc = false;	
    if ((index >= 0) && (index < listSize)) {
	rc = true;
	key = a[index];
    }
    return rc;
}

//******************************************************************************

/*Bella
this is super basic. it fetches the listSize so we know how many full slots 
there are and how many empty slots there are. very useful if you have a set 
number of things to get in and you might be under or over.
*/

int intList::count()const{
    return listSize;
}

//******************************************************************************

/*Bella
tell us how many things we can put in so we dont overflow or something. that
would not be a baller thing to do
*/

int intList::capacity()const{
    return listCapacity;
}