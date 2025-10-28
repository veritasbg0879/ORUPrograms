/*Bella Goodman, Kandice Coop
Dr. Wheat
CSC 255 Data Structures
P2a.cpp - Linked Lists
This is the .cpp file for Program 2a, which sets up constructors, destructors,
and functions for the new classes. The point of a linked list is to make it
easier to add and delete items from the list without having to shift all kinds
of things around. this cpp includes all the basic functions you'd need to
do most of what you'd ever need to do unless you're a little extra.
*/


#include <string>
#include <iostream>

#include "p2.h"

using namespace std;

node::node(string text, node *pn){
    this->text = text;
    next = pn;
}

//******************************************************************************

/*Bella
ok we're gonna set up our constructor and the count is 0 (because there's nothing
in the list) and first and last are both set to the unreadable unwriteable NULL.
*/

stringLinkedList::stringLinkedList() {
    first = NULL;
    last = NULL;
    listCount = 0;
}

//******************************************************************************

/*Bella
call the clear function to deconstruct the linked list to avoid the nasty
bug that is memory leakage
*/

stringLinkedList::~stringLinkedList() {
    clear (first);
}


//******************************************************************************

/*Bella
say they're private so people can't steal your code or something. we pass in a
string, node, and integer and then the function goes through everything to look
for our specific text. if it's not there return -1, if it is there say what the
index is. boom shakalaka
*/

int stringLinkedList::getIndex(std::string text, node *pn, int index) const {
    int rc = -1;
    if (pn) {
        if (pn->text == text) {
            rc = index;
        } else {
            rc = getIndex(text, pn->next, index + 1);
        }
    }
    return rc;
}

//******************************************************************************

/*Bella
now we set up a function so we can print the thing. if it doesn't print, how
will we know what's going on? what if it's all wrong? print it and tell me,
little function.
*/
void stringLinkedList::printIt(node *pn, int index) const {
    if (pn) {
        std::cout << "At pos " << index << " there is " << pn->text << endl;
        printIt(pn->next, index + 1);
    }
}

//******************************************************************************

/*Bella
woop woop here's a clear that we'll call sometime and it just deletes everything
to prevent ~memory leakage~
*/
void stringLinkedList::clear(node *pn) {
    if (pn) {
        clear(pn->next);
        delete pn;
        pn = NULL;
    }
}

//******************************************************************************

/*Kandice
Inserts a new node. If new node isn't in memory it will return false. Increments listCount which keeps track of number of nodes*/
bool stringLinkedList::insert(std::string text) {
    first = new node(text, first);
    if (!last) {
        last = first;
    }
    listCount++;
    return true;
}

//******************************************************************************

//Kandice
//Creates a new node that is at the end of the linked list.
bool stringLinkedList::add(std::string text) {
    node *pn = new node(text);
    if(listCount) {
        last->next = pn;
        last = pn;
    } else {
        first = pn;
        last = pn;
    }
    listCount++;
return true;
}

//******************************************************************************

//Kandice
bool stringLinkedList::insertAt(int index, std::string text) {
    bool rc = false;
    if (index >= 0 && index <= listCount) {
        rc = true;
        if (index == 0) {
            first = new node(text, first);
            listCount++;
            if (!last) {
                last = first;
            } else {
                node* pn = first;
                for (int i = 0; i < index - 1; i++) {
                    pn = pn->next;
                }
                node* nn = new node(text, pn->next);
                pn->next = nn;
                if (index == listCount) {
                    last = nn;
                }
                listCount++;
            }
        }
    }
	return rc;
}
//******************************************************************************

/*Bella
not gonna lie i totally started working on this before i realized it's stubbed out
so yeah it does nothing for now*/
bool stringLinkedList::deleteAt(int index, std::string &text) {
    node *pn = first;
    bool rc = false;
    if ((index >= 0) && (index < listCount - 1)) {
        for (int i = 0; i < index; i++) {
            pn = pn->next;
        }
        text = pn->text;
        clear(pn);
        rc = true;
    }
    return rc;
}
//******************************************************************************
/*Kandice
This function reads into the array and if the index is not the last one or the */
bool stringLinkedList::readAt(int index, std::string &text) {
	bool rc = false;
    if(index < 0 || index >= listCount) {
        text = "";
    } else {
        node *current = first;
        for(int i = 0; i < index; i++) {
            current = current->next;
        }
    text = current->text;
	rc = true;
    }
    return rc;
}

//******************************************************************************

//This clears memory for all the nodes and updates the first and last pointers to null, which makes the list empty.*/
void stringLinkedList::clear() {
    clear(first);
    first = last = nullptr;
    listCount = 0;
}

//******************************************************************************

/*Bella
RECURSION BABYYYYY this is literally the coolest thing ever to me and i just
figured it out. we call the private function we set up at the top and
literally just run that.
*/

int stringLinkedList::getIndex(string text) const{
    return getIndex(text, first, 0);
}

//******************************************************************************

/*Bella
more recursion i flipping love this thing its great we once more call the
EXACT function from up top and use that sucker here.
*/

void stringLinkedList::printIt() const {
    printIt(first, 0);
}

//******************************************************************************

/* Bella
this returns the count we have, which is the amount of nodes that exist
when we call the function. isn't that handy? This way we can tell if
any of them are floating out in space.
*/

int stringLinkedList::count() const {
    return listCount;
}
