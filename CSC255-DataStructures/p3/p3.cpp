/*
Bella Goodman, Kandice Coop
CSC 255 Data Structures, Wheat
p3a.cpp - 
Comments
*/

#include <string>
#include <iostream>

#include "p3.h"

//******************************************************************************

cStringList::cStringList(int capacity) {
    listCapacity = capacity;
    a = new std::string[capacity];
    listCount = 0;
    first = 0;
    last = 0;
}

//******************************************************************************

cStringList::~cStringList() {
    delete[] a;
}

//******************************************************************************

void cStringList::incVal(int &value) const {
    value = (value +1) % listCapacity;
}

//******************************************************************************

void cStringList::decVal(int &value) const {
    if (value == 0) {
        value = listCapacity - 1;
    } else {
        value--;
    }
}

//******************************************************************************

bool cStringList::insert(std::string text) {
	bool rc = false;
    if (listCount < listCapacity) {
        rc = true;
        decVal(first);
        a[first] = text;
        listCount++;
    }
	return rc;
}

//******************************************************************************

bool cStringList::add(std::string text) {
    bool rc = false;
    if (listCount < listCapacity) {
        a[last] = text;
		incVal(last);
		listCount++;
        rc = true;
	}
	return rc;
}

//******************************************************************************

bool cStringList::insertAt(int index, std::string text) {
    bool rc = false;
	if (index >= 0 && index <= listCount && listCount < listCapacity) {
		for (int i = listCount; i >= index; i--) {
			a[(first + i) % listCapacity] = a[(first + i - 1) % listCapacity];
		}
		a[(first + index) % listCapacity] = text;
		listCount++;
        incVal(last);
        rc = true;
	} 
	return rc;
}

//******************************************************************************

bool cStringList::deleteAt(int index, std::string &text) {
    bool rc = false;
    if (index >= 0 && index < listCount) {
        text = a[(first + index) % listCapacity];
        for (int i = index; i < listCount - 1; i++) {
            a[(first + i) % listCapacity] = a[(first + i + 1) % listCapacity];
        }
        listCount--;
        decVal(last);
        rc = true;
    }
    return rc;
}

//******************************************************************************

bool cStringList::readAt(int index, std::string &text) {
    bool rc = false;
	if (index >= 0 && index < listCount) {
		rc = true;
		text = a[(first + index) % listCapacity];
	}
	return rc;
}

//******************************************************************************

bool cStringList::deleteFirst(std::string &text) {
    return deleteAt(0, text);
}

//******************************************************************************

bool cStringList::deleteLast(std::string &text) {
    return deleteAt(listCount -1, text);
}

//******************************************************************************

void cStringList::clear() {
    listCount = 0;
    first = 0;
    last = 0;
}

//******************************************************************************

int cStringList::count() const {
    return listCount;
}

//******************************************************************************

int cStringList::getIndex(std::string text) {
    
}

//******************************************************************************

void cStringList::printIt() const{
    for (int i = 0; i < listCount; i++) {
        int index = (first + i) % listCapacity;
        std::cout << a[index] << std::endl;
    }
}