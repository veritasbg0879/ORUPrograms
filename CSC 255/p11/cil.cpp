/*Team 4
Bella Goodman, Kandice Coop
Dr. Wheat
CSC 255 Data Structures
Program 3(full) - Circular Lists
This is the cpp file for the Circular Lists program. The goal is to create
an array that functions similar to a decoding disk where a user can turn
the list around to find what they need. This is handy in a way that we can 
turn an array around and around however it must be turned.
*/


#include <iostream>

#include "cil.h"

using namespace std;

//*****************************************************************************

//Bella - this is just the basic constructor. Everything gets set to 0 at the
//beginning because otherwise it would be a hot mess with numbers flying around
//and it wouldn't run.

cIntList::cIntList(int listCapacity) {
    this -> listCapacity = listCapacity;
    a = new int[listCapacity];
    listCount = 0;
    first = 0;
    last = 0;
}

//*****************************************************************************

//Bella - delete that bad boy to prevent memory leakage, like we have done each
//of the previous programs.

cIntList::~cIntList() {
    delete[]a;
}

//*****************************************************************************

/*Bella
its a pain to have to type out a whole formula every time you need the actual 
location of the index instead of whatever silliness the user has cooked up. 
replace that thing with a function that changes the logical to the physical
index in the array.
*/ 
int cIntList::lToP(int log) {
    return ((first + log) % listCapacity);
}

//*****************************************************************************

/*Bella
similar to, but not the same as, the above function. this converts the 
physical location to the logical (aka the user's whatever it is) and 
boom no more crazy complex coding.
*/

int cIntList::pToL(int phy) {
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

void cIntList::incVal(int &value) const{
    if (value == listCapacity) {
	value = 0;
    } else {
	value ++;
    }
}

//*****************************************************************************

//Bella - Decrement it, if you want. This function makes it so that we can
//control the value and where it's at in the list.

void cIntList::decVal(int &value) const{
    if (value == 0) {
	value = listCapacity - 1;
    } else {
	value --;
    }
}	

//*****************************************************************************

//Bella - its an insert (wow amazing!! such cool) that checks all kinds of
//things. it manages the dateline and moves everything around and whatever
//we need. it also adds the val that the user passes in to the first array 
//of our Circular list.

bool cIntList::insert(int val) {
    bool rc = false;
    if (listCount < listCapacity) {
	if (listCount > 0) {
            decVal(first);
	    a[first] = val;
	    rc = true;
	} else if (listCount == 0){
	    a[first] = val;
	    rc = true;
	}
        listCount++;
    }
    return rc;	
}

//*****************************************************************************

/*Bella
I was actually falling asleep while writing my last comments, sorry they were
pretty funky (outside of my norm). add just appends stuff to the end of the 
list and adjusts the dateline accordingly. woop woop
*/

bool cIntList::add(int val){
    bool rc = false;
	if (listCount == 0) {
		a[0] = val;
		incVal(last);
		rc = true;
		listCount++;
	} else if (listCount < listCapacity) {
        a[last] = val;
	    incVal(last);
	    rc = true;
	    listCount++;
	}
    return rc;	
}

//*****************************************************************************

//Kandice - this function is like a librarian rearranging elements

bool cIntList::insertAt(int index, int &val){
    bool rc = false;
    if (index >= 0 && index < listCount && listCount < listCapacity) {
        int phy = (first + index) % listCapacity;
        for (int i = listCount; i > index; i --) {
            phy = (first + i - 1) % listCapacity;
            a[(phy + 1) % listCapacity] = a[phy];
        }
        a[phy] = val;
        listCount++;
        incVal(last);
        rc = true;
    }
    return rc;
}

//*****************************************************************************

//Kandice - this function removes a element at a given index

bool cIntList::deleteAt(int index, int &val){
    bool rc = false;
	val = -1;
    if(index >= 0 && index < listCount) {
        int phy = (first + index) % listCapacity;
        val = a[phy];
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

/*Bella
sometimes we just want to know what the array says at a specific index.
we can pass in the index value and then its all good and this function finds it
for us and tells us what it says! no more forgetting things (as long as you
remember the index)
*/

bool cIntList::readAt(int index, int &val){
    bool rc = ((index >= 0) && (index < listCount));
	
	if (rc) {
		val = a[lToP(index)];
    }
	
    return rc;
}

//*****************************************************************************

/*Bella
delete the first thing in the list, regardless of where it's actually at. if
the user says its at 27 okay its at 27. we call the handee dandee delete at
because recursion is the coolest thing ever
*/

bool cIntList::deleteFirst(int &val){
    return deleteAt(first, val);
}

//*****************************************************************************

/*Bella
recursive functions are the best thing (second to Jesus) that's ever happened
to me. its beautiful how you can call the deleteAt and it just works and 
nobody has to define each individual thing.
*/

bool cIntList::deleteLast(int &val){
    return deleteAt(last, val);
}

//*****************************************************************************

//Bella - this sets all the values to 0 so the computer knows we're allowed
//to use them

void cIntList::clear(){
    listCount = 0;
    first = 0;
    last = 0;
}

//*****************************************************************************

//Bella - this is pretty self-explanatory, it tells the user how many things
//are in the list

int cIntList::count() const{
    return listCount;
}

//*****************************************************************************

/*Bella
get the index of the val. if you try to call readAt because you forgot the
thing and you also forgot the index, you're kinda out of luck. however!
if you know the thing you're searching for, you can use this to find the 
index of it.
*/

int cIntList::getIndex(int val) {
    int rc = -1;
    for (int index = 0; index < listCount; index++){
	if (a[index] == val) {
	    rc = (pToL(index));
	}
    } 
    return rc;
}

//*****************************************************************************

//Bella - it prints!! its aLiVe!! print out the indexes (relatively) and 
//what's located at each index.

void cIntList::printIt() {
    int log;
    for (log = 0; log < listCount; log++) {
	int phy = (first + log) % listCount;
	cout << "Queue item " << log << " = " << a[phy] << endl;
    }
}