/* Team 4
Bella Goodman, Kandice Coop
Dr. Wheat
CSC 255 Data Structures
Program 8 -
Comments
*/

#include <string>
#include <iostream>

#include "p8.h"

using namespace std;

//******************************************************************************

intList::intList(int listCapacity) {
    this -> listCapacity = listCapacity;
    listSize = 0;
    a = new int[listCapacity];
}

//******************************************************************************

/*Bella
This is meant to delte the entire array to prevent memory leakage*/

intList::~intList() {
    delete[]a;
}

//******************************************************************************

/*Bella
 this returns a value that's either true or false based on the availability in the list. it keeps the user from losing any data if they forget how many empty slots they have. it also gives us the handy-dandy feature of adding things to the top of the list for ~organization~*/
bool intList::insert(int key) {
    bool rc = false;
    if (listSize < listCapacity) {
        for (int i = listSize - 1; i >= 0; i--) {
            a[i + 1] = a[i];
        }
        a[0] = key;
        rc = true;
    }
    return rc;
}

//******************************************************************************

/*Bella
This is like the opposite of the above function; it adds (appends) things to the end of the list so we don't have to shuffle things around. It's the kind of thing you'd do if you were making a list of tasks and you totally forgot to add all your Calculus Homework.
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
so it inserts a thing. maybe you don't want the thing to be at the beginning OR the end for ~organizational~ purposes. This gives you the choice to put it absolutely a n y w h e r e in the list. cool beans.
*/
bool intList::insertAt(int index, int &key){
    bool rc = false;
    if (listSize < listCapacity) {
        for (int i = listSize - 1; i >= index; i--) {
            a[i + 1] = a[i];
        }
        a[index] = key;
        rc = true;
    }
    return rc;
}

//******************************************************************************

/*Bella
this is a stubbed lil guy so we are leaving it here and  it'll just give us the placeholder value until we fix it later.
*/

bool intList::deleteAt(int index, int key){
    return false;
}

//******************************************************************************

/*Bella
this literally just sets the size to 0. it essentially tells the system that we have nothing in our list and we're good to write over it all.
*/

void intList::clear(){
    listSize = 0;
}

//******************************************************************************

/*Kandice
prints each element
*/

void intList::printIt(int n) const {
    cout << "printIt with list size: " << listSize << " capacity = " << listCapacity << endl;
    for (int i = 0; i < listSize; i++) {   //the one with a print statement
        cout << "At pos " << i << " there is " << a[i] << endl;
    }
}

//******************************************************************************
//Bella
//woop woop its the sound of tha police just kidding this searches the list for a specific text. If the text is found awesome it returns the index it was found at but if not, oopsie dasies you get a -1 because you're wrong

int intList::getIndex(int key) const {
    int rc = -1;
    for (int index = 0; index < listSize; index++) {
        if (a[index] == key) {
            rc = index + 1;
        }
    }
    return rc;
}

//******************************************************************************

/*Bella
this tells us what the value is at the given index. if you forget whats in the list its great because it will just tell you.
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
this is super basic. it fetches the listSize so we know how many full slots there are and how many empty slots there are. very useful if you have a set number of things to get in and you might be under or over.
*/

int intList::count() const{
    return listSize;
}

//******************************************************************************

void intList::bubbleSort() {
    for (int i = 0; i < listSize - 1; i++) {
        for (int j = 0; j < listSize - 1 - i; j++) {
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                }
            }
        }
}

//******************************************************************************

/* Kandice
 This function sorts through the array comparing each element with the current minimum. The index is stored in minIndex. Swaps the element at i with the minimum in found in the unsorted. */
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
 This function sorts the array going through each element comparing it with its previous and swapping them if necessary arranging them from smaller. */
void intList::insertionSort() {
    for (int i = 0; i < listSize; i++) {
        for (int j = i + 1; j > 0; j--) {
            if (a[j-1] > a[j]) {
                swap(a[j-1], a[j]);
            }
            else {
                break;
            }
        }
    }
}

//******************************************************************************


int intList::capacity() const {
    return listCapacity;
}

//******************************************************************************

/* */
bool intList::isSorted() const {
    bool sorted = true;
    for (int index = 0; index < listSize - 1; index++) {
        if (a[index] > a[index + 1]) {
            cout << "List is not sorted" << index << endl;
            sorted = false;
        }
    }
    return sorted;
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

/*Kandice
 This function swaps two ints by using pointers*/

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

void intList::buildHeap() {
    for (int i = listSize / 2 - 1; i >= 0; i--) {
        heapify(i);
    }
}

void intList::heapSort() {
    heapSize = listSize;
    buildHeap();
    while (--heapSize) {
        swap(a[0], a[heapSize]);
        heapify(0);
    }
}
