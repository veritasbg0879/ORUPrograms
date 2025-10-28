/*Bella Goodman, Kandice Coop
Team 4
Dr. Wheat
CSC 255 Data Structures
P13.cpp Final - Huffman Encoding
This is a program that implements the greedy algorithm, Huffman Encoding.
*/

#include <iostream>
#include <fstream>
#include <string>
 
#include "p13.h"


huffNode::huffNode(char val, int key, huffNode *left, huffNode *right) {
    // Instructor provided
    this->val = val;
    this->key = key;
    this->left = left;
    this->right = right;
}

//******************************************************************************

//Bella - set up the constructor

huffman::huffman() {
	pq = new huffPQ(FCOUNT);
	fileSize = 0;
	freqs = new int[FCOUNT];
	
}

//******************************************************************************

//Bella - destruction time

huffman::~huffman() {
	delete []freqs;
	delete pq;
	clear();
}

//******************************************************************************

//Bella - clear that sucker out to prevent memory leakage

void huffman::clear(huffNode *p) {
	if (p != NULL) {
		clear(p->left);
		clear(p->right);
		delete(p);
	}
}

//******************************************************************************

/*Kandice
 For each leaf node this function generates and assigns a huffman code to the 
 character's position in the array*/
 
void huffman::getEncodings(huffNode *p, encoding code, encoding *rv) const {
	if (p) {
		getEncodings(p->left, code, rv);		
		if (p->left) {
			code.pat = code.pat << 1;
			code.patCount++;
		} else if (p->right) {
			code.pat = code.pat += 1;			
		}
		if (p->key > 0) {
			rv[p->val] = code;		
		}	
		getEncodings(p->right, code, rv);
		
	}
}

//******************************************************************************

//Bella - this code was given to print out the specific things in order

void huffman::printPattern(char val, int freq, encoding code) const {
    std::cout << val << "(" << (100.0*(float)freq/(float)fileSize) << "%) ";
    for (int i = 0; i < code.patCount; i++) {
	std::cout << (int)(((code.pat >> code.patCount - 1 - i)) & 1);
    }
    std::cout << std::endl;
}

//******************************************************************************

//Bella - print out only the leaves

void huffman::printIt(huffNode *p, encoding code) const {
	encoding* mobileHome = getEncodings();
	if (p != NULL) {
		printIt(p->left, code);		
		printPattern(p->val, p->key, mobileHome[p->val]);
		printIt(p->right, code);		
	}
}

//******************************************************************************

//Bella - print out the whole data structure

void huffman::dumpTree(huffNode *p, encoding code) const {
	if (p != NULL) {
		printIt(p->left, code);
		std::cout << "the thing or something " << std::endl;
		printIt(p->right, code);
	}	
}

//******************************************************************************

//Kandice - import the file using the name passed in

bool huffman::importFile(std::string fname) {
	bool rc = false;
	std::ifstream theFile(fname);
	char x;
	while (theFile.get(x)) {
		for (int index = 0; index < FCOUNT; index++) {
			if (index == x) {
				freqs[index]++;
				fileSize++;
				rc = true;
			}
		}	
	}
	return rc;
}

//******************************************************************************

//Bella - build the tree

void huffman::buildTree() {
	int c;
	for (int i = 0; i < FCOUNT; i++) {
		if (freqs[i] > 0) {
			huffNode *node = new huffNode(i, freqs[i]);
			pq->enq(node);
		}
	}

	c = pq->count();
	for (int i = 0; i < c - 1; i++) {
		huffNode *x;
		huffNode *y;			
		pq->deq(x);
		pq->deq(y);
		int kiki = x->key + y->key;
		huffNode *thing = new huffNode('@', kiki, x, y);
		pq->enq(thing);
	} 
	
	pq->deq(root);
}

//******************************************************************************

void huffman::clear() {
    // traverse the tree, deleting all the nodes
    // and clear the counts and empty the pq
    
    clear(root);
    fileSize = 0;
    root = NULL;

    for (int i = 0; i < FCOUNT; i++) {
	freqs[i] = 0;
    }

    pq->clear();
}

//******************************************************************************

encoding *huffman::getEncodings() const {
    encoding *rv = new encoding[FCOUNT];

    encoding code;
    code.pat = 0;
    code.patCount = 0;

    getEncodings(root, code, rv);

    return rv;
}

//******************************************************************************

int huffman::getOutFileSizeBits() const {
    int rc = 0;

    encoding *encodings = getEncodings();


    for (int i = 0; i < FCOUNT; i ++) {
	rc += encodings[i].patCount * freqs[i];
    }

    delete [] encodings;

    return rc;
}
//******************************************************************************

int huffman::getInFileSizeBytes() const {
    return fileSize;
}

//******************************************************************************

void huffman::printIt() const {
	encoding code;
    code.pat = 0;
    code.patCount = 0;
    printIt(root, code);
}

//******************************************************************************

void huffman::dumpTree() const {
	encoding code;
    code.pat = 0;
    code.patCount = 0;
    dumpTree(root, code);
}