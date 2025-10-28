/*Bella Goodman, Kandice Coop
Dr. Wheat
CSC 255 Data Structures
Program 4a - Binary Search Tree
Comments
*/

#include <string>
#include <iostream>

#include "p4.h"

using namespace std;

//*****************************************************************************

//Comments

sNode::sNode(std::string text) {
    this->text = text;
    left = NULL;
    right = NULL;
}

bool sBST::insert(sNode *node, std::string text) {
    if (node == nullptr) {
        treeCount++;
        node = new sNode(text);
    } else {
        if(text < node->text) {
            node->left = insert(node->left, text);
        } else if (text > node->text) {
            node->right = insert(node->right, text);
        }
    }
    return node;
}

bool sBST::remove(sNode *node, std::string text) {
    
}

string sBST::findMinNode(sNode *node) const {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

void sBST::clear(sNode *node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

sBST::sBST() {
    root = nullptr;
    treeCount = 0;
}

sBST::~sBST() {
    clear();
}

bool sBST::insert(std::string text) {
    root = insert(root, text);
    return true;
}

bool sBST::remove(std::string text) {
    bool pn = false;
    if (isIn(text)) {
        root = remove(root, text);
        pn = true;
    }
    return pn;
}

bool sBST::isIn(std::string text) const {
    return isIn(root, text);
}

bool sBST::isIn(sNode *node, std::string text) const {
    
}

void sBST::printIt() const {

}

int sBST::count() const {
    return treeCount;
}

void sBST::clear() {

}
