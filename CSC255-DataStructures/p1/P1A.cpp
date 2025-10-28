/*
Bella Goodman
CSC 255 Data Structures, Wheat
P1A.cpp - List
This file works with the header to define the functions named in the header.
blah blah blah
*/

#include P1a.h
#include <string> //wont work

//declare the variables you'll use at some point
string *a;
int listCapacity;
int listSize;

//******************************************************************************

//make a new array using the listCapacity integer that gets passed in. also set
//the value of listCapacity and tell the computer that there's nothing in the
//list (a lie) but we can now work with listSize.

stringList::stringList(int listCapacity) {
	this -> listCapacity = listCapacity;
	listSize = 0;
	a = new string[listCapacity];
}

//******************************************************************************

//blah blah blah probably something about the new code

stringList::~stringList() {
	delete[]a;
}

//******************************************************************************

//blah blah blah probably something about the new code

bool stringList::insert(string text) {
	bool rc = false;
	if (listSize < listCapacity) {
		for (int i = listSize; i >= 0; i--) {//confused here <-
			a[i + 1] = a[i];					//what pt2
		}
		a[0] = text;
		rc = true;
	} 
	return rc;
}

//******************************************************************************

//blah blah blah probably something about the new code

bool stringList::add(string text){
	bool rc = false;
	if (listSize < listCapacity) {
		a[listSize + 1] = text;
		rc = true;
	}
}

//******************************************************************************

//blah blah blah probably something about the new code

bool stringList::insertAt(int index, string text){
	bool rc = false;
	if (listSize < listCapacity) && (int index < listSize) {
		for (int i = listSize; i > index; i--) {
			a[i + 1] = a[i];
		}
		a[index] = text;
		rc = true;
	} 
	return rc;
}

//******************************************************************************

//blah blah blah probably something about the new code

bool stringList::deleteAt(int index, string text){
    return false;
}

//******************************************************************************

//blah blah blah probably something about the new code

void stringList::clear(){
	listSize = 0;
}

//******************************************************************************

//blah blah blah probably something about the new code

void stringList::printIt()const{
	for (i = 0; i <= listSize; i++) {
		std::cout<<"&a[i] a[i]";
	}
}

//******************************************************************************

//blah blah blah probably something about the new code

int stringList::getIndex(string text){
    return -1;
}

//******************************************************************************

//blah blah blah probably something about the new code

bool stringList::readAt(int index, string &text) const {
	bool rc = false;
	
	if ((index >= 0) && (index < listSize)) {
		rc = true;
		text = a[index];
	}
	return rc;
	
}

//******************************************************************************

//blah blah blah probably something about the new code

int stringList::count()const{
	return listSize;
}