/* Team 4
Kandice Coop, Bella Goodman
Dr. Wheat
CSC 255 Data Structures
Program 5a - sAVL
*/

//include the things you need otherwise everything falls apart
#include <string>
#include <iostream>

//the cpp is useless without the header
#include "p5.h"

//who wants to type std:: before every string text? not me
using namespace std;

int max(a, b) {
	rc = a;
	if (a < b) {
		rc = b;
	}
	return rc;
}
//******************************************************************************

//Kandice - initializes the right and left pointers to NULL. Sets the text variable to the value of text

sNode::sNode(std::string text) {
    right = left = NULL;
    this->text = text;
}

//******************************************************************************

/*Kandice - the constructor sets up a empty Binary Search Tree by initializing
 the pointer to Null and treeCount to 0
 */
 
sAVL::sAVL() {
    root = NULL;
    treeCount = 0;
	h = 0;
}

//******************************************************************************

//Bella - a deconstructor for the sAVL that clears every node and takes us back
//to the root

sAVL::~sAVL() {
    clear(root);
}


void sAVL::rotateLeft(sNode *&p1) {
	sNode p2 = p1->right;
	p1->right = p2->left;
	p2->left = p1;
	p1->h = calcHeight(p2);
	p1 = p2;
	p1->h = calcHeight(p2);
}

void sAVL::rotateRight(sNode *&p1) {
	sNode p2 = p1->left;
	p1->left = p2->right;
	p2->right = p1;
	p1->h = calcHeight(p2);
	p1 = p2;
	p1->h = calcHeight(p2);
}

void sAVL::bal(sNode *&p) {
}

int sAVL::height(sNode *p) const {
	rc = -1;
	while p->next != NULL;
		p = p->next;
		rc++;
	return rc;
}

int sAVL::calcHeight(sNode *p, int &index) {
	return (max(height(p->left)), height(p->right));
}

//******************************************************************************

/*Kandice - the while loop will continue as long as there is a left child node. 
When there are no more left child nodes you have reached the min value.
*/

string sAVL::findMin(sNode *ptr) const {
    while (ptr->left != nullptr) {
        ptr = ptr->left;
    }
    return ptr->text;
}

//******************************************************************************

/*Bella - insert the text wherever it needs to go. check each node to see if it
needs to be on the left or right and then recursively call insert to see if
a node needs to be created somewhere in the left and right subtrees until
eventually a new node goes poof and our text is added to it.
*/

bool sAVL::insert(string text, sNode *&p) {
    bool rc = false;
    if (p) {
        if (p->text > text) {
            rc = insert(text, p->left);
        } else if (p->text < text) {
            rc = insert(text, p->right);
        }
    } else {
        p = new sNode(text);
        rc = true;
        treeCount++;
    }
    return rc;
}

//******************************************************************************

/*Bella - it removes things. im sure you're asking how, but heres the thing.
there are three different cases where the function is either gonna look for the 
text down the left subtree, the right subtree, or its been found which is cool.
if it finds the text it has to see if its a leaf. if so, cool! if not, make it
a leaf. then delete the leaf and it works.
*/

bool sAVL::remove(string text, sNode *&p) {
    bool rc = false;
    if (p){
	if (p->text > text) {
       	    rc = remove(text, p->left);
	} else if (p->text < text) {
	    rc = remove(text, p->right);
	} else if (p->text == text) {
	    if ((!p->left) && (!p->right)) {
		rc = true;
		delete p;
		p = NULL;
		treeCount--;
	    } else if (!p->right){
		sNode *pn = p->left;
		delete p;
		p = pn;				
		treeCount--;
		rc = true;
	    } else {
		p->text = findMin(p->right);
		rc = remove(p->text, p->right);
	    }
	}
    }
    return rc;

}

//******************************************************************************

/*Kandice - this function makes sure that there are no nodes left. If the 
current node is not NULL it will clear all the nodes to the left subtree and 
right. Then after clearing those it will delete the current node.
*/

void sAVL::clear(sNode *node) {
    if (node != NULL) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

//******************************************************************************

/*Bella - look around the binary tree and compare the text to the root, then 
to the subtrees all the way down until the text being compared is the same. then
return true because its totally there.
*/

bool sAVL::isIn(string text, sNode *p) const {
    bool rc = false;
	if (p) {
	    if (p->text > text) {
		    rc = isIn(text, p->left);
	    } else if (p->text < text) {
		    rc = isIn(text, p->right);
	    } else if (p->text == text) {
		    rc = true;
	    }
	}
    return rc;
}

//******************************************************************************

/*Bella - print it recursively, if it has children go down and check if they
have children. go all the way down then print left -> right -> parent and so on
and so forth.
*/

void sAVL::printIt(sNode *node) const {
    if (node){
        printIt(node->left);
        cout << node->text << endl;
        printIt(node->right);
    }
}

//******************************************************************************

//Bella - call the private insert that we spent some time making

bool sAVL::insert(string text) {
    return insert(text, root);
}

//******************************************************************************

//Bella - call the private remove so the user doesn't know what we did hehe

bool sAVL::remove(string text) {
    return remove(text, root);
}

//******************************************************************************

//Bella - call the other isIn cuz this isIn just isnt enough

bool sAVL::isIn(string text) const {
    return isIn(text, root);
}

//******************************************************************************

//Bella - call the private printIt wooohooooo recursion^3?

void sAVL::printIt() const {
    printIt(root);
}

//******************************************************************************

/*Bella - this is so basic it just tells the user what the current treeCount is
aka how many elements are stored in the BST
*/

int sAVL::count() const{
    return treeCount;
}

//******************************************************************************

/*Bella - I KEPT GETTING AN ABORT ERROR FROM THIS AND IT WAS SO DUMB but
it works now. it deletes the sAVL and clears everything out including the
variables we use to keep track of the treeCount and it sets the root to NULL
so we don't try to reference things that don't exist after clear is called
*/

void sAVL::clear() {
    clear(root);
    root = NULL;
    treeCount = 0;
}
