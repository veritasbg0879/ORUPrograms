/*
Bella Goodman
CSC 255 Data Structures, Wheat
P1A.cpp - List
This file works with the header to define the functions named in the header.
blah blah blah
*/

#include "P1.h"
#include <string>
#include <iostream>

//(bella)declare the variables you'll use at some point
std::string *a;
int listCapacity;
int listSize;

//******************************************************************************

//Bella
//make a new array using the listCapacity integer that gets passed in. also set
//the value of listCapacity and tell the computer that there's nothing in the
//list (a lie) but we can now work with listSize.

stringList::stringList(int listCapacity) {
	this -> listCapacity = listCapacity;
	listSize = 0;
	a = new std::string[listCapacity];
}

//******************************************************************************

//Bella
//this is meant to delete the entire array to prevent memory leakage 

stringList::~stringList() {
	delete[]a;
}

//******************************************************************************

//Bella
//this returns a value that's either true or false based on the availability 
//in the list

bool stringList::insert(std::string text) {
	bool rc = false;
	if (listSize < listCapacity) {
		for (int i = listSize; i > 0; i--) {
			a[i] = a[i + 1];					
		}
		a[0] = text;
		rc = true;
	} 
	return rc;
}

//******************************************************************************

//blah blah blah probably something about the new code

bool stringList::add(std::string text){
	bool rc = false;
	if (listSize < listCapacity) {
		a[listSize + 1] = text;
		rc = true;
		listSize += 1;
	}
	return rc;
}

//******************************************************************************

//blah blah blah probably something about the new code

bool stringList::insertAt(int index, std::string &text){
	bool rc = false;
	if (listSize < listCapacity) && (index >=0 && index <= listSize) {
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

bool stringList::deleteAt(int index, std::string text){
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
	for (int i = 0; i < listSize - 1; i++) {   //the one with a print statement
		std::cout <<"&a[" << i << "]" << a[i];
	}
}

//******************************************************************************

//blah blah blah probably something about the new code

int stringList::getIndex(std::string text){
    return -1;
}

//******************************************************************************

//blah blah blah probably something about the new code

bool stringList::readAt(int index, std::string &text) const {
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