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

/*Bella
its a pain to have to type out a whole formula every time you need the actual 
location of the index instead of whatever silliness the user has cooked up. 
replace that thing with a function that changes the logical to the physical
index in the array.
*/ 
int cStringList::lToP(int log) {
    return ((first + log) % listCapacity);
}

//*****************************************************************************

/*Bella
similar to, but not the same as, the above function. this converts the 
physical location to the logical (aka the user's whatever it is) and 
boom no more crazy complex coding.
*/

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

//Bella - its an insert (wow amazing!! such cool) that checks all kinds of
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

/*Bella
I was actually falling asleep while writing my last comments, sorry they were
pretty funky (outside of my norm). add just appends stuff to the end of the 
list and adjusts the dateline accordingly. woop woop
*/

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

//Kandice - this function is like a librarian rearranging elements

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

//Kandice - this function removes a element at a given index

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

/*Bella
sometimes we just want to know what the array says at a specific index.
we can pass in the index value and then its all good and this function finds it
for us and tells us what it says! no more forgetting things (as long as you
remember the index)
*/

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

/*Bella
delete the first thing in the list, regardless of where it's actually at. if
the user says its at 27 okay its at 27. we call the handee dandee delete at
because recursion is the coolest thing ever
*/

bool cStringList::deleteFirst(std::string &text){
    return deleteAt(first, text);
}

//*****************************************************************************

/*Bella
recursive functions are the best thing (second to Jesus) that's ever happened
to me. its beautiful how you can call the deleteAt and it just works and 
nobody has to define each individual thing.
*/

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

/*Bella
get the index of the text. if you try to call readAt because you forgot the
thing and you also forgot the index, you're kinda out of luck. however!
if you know the thing you're searching for, you can use this to find the 
index of it.
*/

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