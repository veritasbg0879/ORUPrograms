/*
Bella Goodman, Kandice Coop
CSC 255 Data Structures, Wheat
P7.cpp - QuadSort
sort all the numbers the right way with three different sorting algorithms. 
check which ones are faster and which ones are slower. time complexity is 
a real thing!
*/

#include <iostream>

#include "P7.h"

using namespace std;

//swap em around like a little dance or something
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

//******************************************************************************

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
bool intList::insertAt(int index, int &key){
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
*/

bool intList::deleteAt(int index, int key){
    return false;
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

/*Bella
go through the array and pick the smallest value then bring it to the front and
push the larger values to the end. by the end its all good and sorted
*/

void intList::selectionSort() {
	for (int i = 0; i < listSize; i++) {
		int minI = i;
		for (int j = i + 1; j < listSize; j++) {
			if (a[j] < a[minI]) {
				minI = j;
			}
		}
		swap(a[i], a[minI]);
	}
}

//******************************************************************************

/*Bella
imagine you have n amount of cards in your hand. look through the cards and 
move higher stuff to the top of the hand. insert it wherever it fits and go
through the whole loop like that
*/

void intList::insertionSort() {
	for (int i = 0; i < listSize; i++) {
		for (int j = i + 1; j > 0; j--) {
			if (a[j - 1] > a[j]) {
				swap (a[j], a[j - 1]);
			} else {
				break;
			}
		}
	}
}

//******************************************************************************

/*Bella
is it sorted? check to see if each number at an index is greater than the number 
at the previous index and if it is all the way through list! if not oopsies hehe
return false
*/

bool intList::isSorted() const {
	bool rc = false;
	for (int i = 0; i < listSize; i++) {
		for (int j = i + 1; j < listSize; j++) {
			if (a[j] > a[i]) {
				rc = true;
			} else {
				rc = false;
			}
		}
	}
	return rc;
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
		cout << "printIt with listSize: " << count() << " capacity = " << capacity()
		<< endl;
	    for (int i = 0; i < n; i++) {   //the one with a print statement
	    	std::cout <<"At pos " << i << " there is " << a[i] << std::endl;
	    }
		cout << "at the end we have " <<a[listSize - 1] << endl;
	} else {
		cout << "printIt with listSize: " << count() << " capacity = " << capacity()
		<< endl;
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

int intList::getIndex(int key){
	int rc = -1;
	for (int index = 0; index < listSize; index++){
		if (a[index] == key) {
			rc = index + 1;
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
this is super basic. it fetches the listSize so we know how many full slots 
there are and how many empty slots there are. very useful if you have a set 
number of things to get in and you might be under or over.
*/

int intList::capacity()const{
    return listCapacity;
}