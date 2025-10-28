/*
Bella Goodman, Kandice Coop
CSC 255 Data Structures, Wheat
P1A.cpp - List
This file works with the header to define the functions named in the header. It gives the user the ability to make a list, add items to the list, read the list, and check different variables associated with the 
list
*/

#include "P1.h"
#include <string>
#include <iostream>



//******************************************************************************

/*Bella
make a new array using the listCapacity integer that gets passed in. also set the value of listCapacity and tell the computer that there's nothing in the list (a lie) but we can now work with listSize.*/

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

/*Bella
this returns a value that's either true or false based on the availability in the list. it keeps the user from losing any data if they forget how many empty slots they have. it also gives us the handy-dandy feature of adding things to the top of the list for ~organization~*/

bool stringList::insert(std::string text) {
	bool rc = false;
	if (listSize < listCapacity) {
		for (int i = listSize - 1; i >= 0; i--) {
			a[i + 1] = a[i];					
		}
		a[0] = text;
		rc = true;
	} 
	return rc;
}

//******************************************************************************

/*Bella
This is like the opposite of the above function; it adds (appends) things to the end of the list so we don't have to shuffle things around. It's the kind of thing you'd do if you were making a list of tasks and you totally forgot to add all your Calculus Homework.
*/

bool stringList::add(std::string text){
	bool rc = false;
	if (listSize < listCapacity) {
		a[listSize] = text;
		rc = true;
		listSize++;
	}
	return rc;
}

//******************************************************************************

/*Bella
so it inserts a thing. maybe you don't want the thing to be at the beginning OR the end for ~organizational~ purposes. This gives you the choice to put it absolutely a n y w h e r e in the list. cool beans.
*/
bool stringList::insertAt(int index, std::string &text){
	bool rc = false;
	if (listSize < listCapacity) {
		for (int i = listSize - 1; i >= index; i--) {
			a[i + 1] = a[i];
		}
		a[index] = text;
		rc = true;
	} 
	return rc;
}

//******************************************************************************

/*Bella
this is a stubbed lil guy so we are leaving it here and  it'll just give us the placeholder value until we fix it later.
*/

bool stringList::deleteAt(int index, std::string text){
    return false;
}

//******************************************************************************

/*Bella
this literally just sets the size to 0. it essentially tells the system that we have nothing in our list and we're good to write over it all.
*/

void stringList::clear(){
	listSize = 0;
}

//******************************************************************************

/*Kandice
prints each element
*/

void stringList::printIt()const{
	for (int i = 0; i < listSize; i++) {   //the one with a print statement
		std::cout <<"At pos " << i << " there is " << a[i] << std::endl;
	}
}

//******************************************************************************

/*Bella
this baby is stubbed so we aren't doing anything with it yet. hehe
*/

int stringList::getIndex(std::string text){
    return -1;
}

//******************************************************************************

/*Bella
this tells us what the value is at the given index. if you forget whats in the list its great because it will just tell you.
*/

bool stringList::readAt(int index, std::string &text) const {
	bool rc = false;
	
	if ((index >= 0) && (index < listSize)) {
		rc = true;
		text = a[index];
	}
	return rc;
	
}

//******************************************************************************

/*Bella
this is super basic. it fetches the listSize so we know how many full slots there are and how many empty slots there are. very useful if you have a set number of things to get in and you might be under or over.
*/

int stringList::count()const{
    return listSize;
}