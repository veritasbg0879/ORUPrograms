/*Bella Goodman, Kandice Coop
Dr. Wheat
CSC 255 Data Structures
Program 3a - Circular Lists
This is the cpp file for the Circular Lists program. The goal is to create
an array that functions similar to a decoding disk where a user can turn
the list around to find what they need. This is handy in a similar way.
*/
#include <string>
#include <iostream>

#include "p3.h"

using namespace std;

//*****************************************************************************

//Bella - this is just the basic constructor. Everything gets set to 0 at the
//beginning because otherwise it would be a hot mess with numbers flying around
//and it wouldn't run.
cStringList::cStringList(int listCapacity) {
	this -> listCapacity = listCapacity;
	a = new std::string[listCapacity];
	listCount = 0;
	first = 0;
	last = 0;
}

//*****************************************************************************

//Bella - delete that bad boy to prevent memory leakage, like we have done each
//of the previous programs.

cStringList::~cStringList() {
    delete[]a;
}

//*****************************************************************************

//Bella 

int cStringList::lToP(int log) {
	return ((first + log) % listCapacity);
}

//*****************************************************************************

//Bella 

int cStringList::pToL(int phy) {
	int rc = (phy - first);
	if (rc < 0) {
		rc += listCapacity;
	}
	return rc;
}

//*****************************************************************************

//Bella - increment whatever value is passed through! normally we'd just use 
//value++ but since we have a dateline to manage we have to be much more
//thoughtful.

void cStringList::incVal(int &value) const{
	if (value >= listCount) {
		value = 0;
	} else {
		value ++;
	}
}

//*****************************************************************************

//Bella - Decrement it, if you want. This function makes it so that we can
//control the value and where it's at in the list.

void cStringList::decVal(int &value) const{
	if (value <= 0) {
		value = listCapacity - 1;
	} else {
		value --;
	}
}	

//*****************************************************************************

//Bella - ita an insert (wow amazing!! such cool) that checks all kinds of
//things. it manages the dateline and moves everything around and whatever
//we need. it also adds the text that the user passes in to the first array 
//of our Circular list.

bool cStringList::insert(std::string text) {
	bool rc = false;
	if (listCount < listCapacity) {
		if (listCount > 0) {
			decVal(first);
			a[first] = text;
			rc = true;
		} else if (listCount == 0){
			a[first] = text;
			rc = true;
		}
		listCount++;
	}
	return rc;	
}

//*****************************************************************************

//Bella - the add IS the insert but backwards. it adds the value to the end of
//the list and works on it from there.

bool cStringList::add(std::string text){
	bool rc = false;
    if (listCount < listCapacity) {
		incVal(last);
        a[last] = text;
		rc = true;
		listCount++;
	}
	return rc;	
}

//*****************************************************************************

//Bella - stub it out so we can do it later woop woop

bool cStringList::insertAt(int index, std::string &text){
    bool rc = false;
    if (index >= 0 && index < listCount && listCount < listCapacity) {
        int phy = (first + index) % listCapacity;
        for (int i = listCount; i > index; i --) {
            phy = (first + i - 1) % listCapacity;
            a[(phy + 1) % listCapacity] = a[phy];
        }
        a[phy] = text;
        listCount++;
        incVal(last);
        rc = true;
    }
    return rc;
}

//*****************************************************************************

//Bella - stub it out so we can't use it but also don't leave it blank
//because then the program doesnt run

bool cStringList::deleteAt(int index, std::string &text){
    bool rc = false;
    if(index >= 0 && index < listCount) {
        int phy = (first + index) % listCapacity;
        text = a[phy];
        for(int i = index; i < listCount - 1; i++) {
            phy = (first + i + 1) % listCapacity;
            a[(first + i) % listCapacity] = a[phy];
        }
        listCount--;
        decVal(last);
        rc = true;
    }
    return rc;
}

//*****************************************************************************

//Bella - stubbed baby number whatever it is. It's useless to us till Friday
//September 15th.

bool cStringList::readAt(int index, std::string &text){
	bool rc = false;
	index = (lToP(index));
	if ((index > first) && (index <= last)) {
		text = a[index];
	rc = true;
	}
	return rc;
}

//*****************************************************************************

//Bella

bool cStringList::deleteFirst(std::string &text){
	return deleteAt(first, text);
}

//*****************************************************************************

//Bella

bool cStringList::deleteLast(std::string &text){
	return deleteAt(last, text);
}

//*****************************************************************************

//Bella - this sets all the values to 0 so the computer knows we're allowed
//to use them

void cStringList::clear(){
	listCount = 0;
	first = 0;
	last = 0;
}

//*****************************************************************************

//Bella - this is pretty self-explanatory, it tells the user how many things
//are in the list

int cStringList::count() const{
	return listCount;
}

//*****************************************************************************

//Bella - this one is stubbed for now. we'll clean it up later.

int cStringList::getIndex(std::string text){
	int rc = -1;
	for (int index = 0; index < listCount; index++){
		if (a[index] == text) {
			rc = (pToL(index));
		}
	} 
	return rc;
}

//*****************************************************************************

//Bella - it prints!! its aLiVe!! print out the indexes (relatively) and 
//what's located at each index.

void cStringList::printIt() const{
	int log;
	for (log = 0; log < listCount; log++) {
		int phy = (first + log) % listCount;
		cout << "At pos " << log << " there is " << a[phy] << endl;
	}
}