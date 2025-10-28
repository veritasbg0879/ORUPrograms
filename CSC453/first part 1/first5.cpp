/* Otters 
Hanna Fontanez, Bella Goodman, Lara Silverthorn, Chloe Winkler
CSC 453 Fall 2024
Assignment: Program Midterm Part 1
9/7/24
This program reads in a grammar of any length and categorizes each character recieved
*/

#include "first.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//******************************************************************************

node::node(std::string text) {
    //sets nex
    this->text = text;
    next = NULL;
    down = NULL;
}

//******************************************************************************

symbolTable::symbolTable(int size) {
    table = new int[size];
    for (int i = 0; i<size; i++) {
        table[i] = 0;
    }
}

//******************************************************************************

symbolTable::~symbolTable() {
    delete[]table;
}



//******************************************************************************

productions::productions() {
    startSymb = 'x';
    lastNT = NULL;
    lastT = NULL;
    product = ' ';
    text = new char[1000];
    table = new int[256];
    for(int i = 0; i<256; i++){
        table[i] = 0;
    }
    for(int i = 0; i<1000; i++) {
        text[i] = 0;
    }


}

//******************************************************************************

productions::~productions() {
    startSymb = NULL;
    delete text;
    delete table;
    for (int i = 0; i < 1000; i++){ 
        
        //delete nodes
    }
}

//******************************************************************************

void productions::terminalIdentifier(char c){
    //tsymbolTble to store the chars and show if it's a terminal or NT
    
    if(table[c] != 2){
        table[c] = 1;
    }
}

//******************************************************************************

void productions::nontermIdentifier(char c){
    table[c] = 2;
}

//******************************************************************************

node* productions::add(string text, node *last){
	// Creates a node with the passed text then adds it to the end of the list by
	// setting last to point to the new node and then changing last to point to 
	// the added node
	
	node *p = new node(text);
	
	if(last){
		last->next = p;
    } else {
        startSymb = p;
    }
	last = p;
	return p;
}

//******************************************************************************

node* productions::addNT(string text, node *last){
	// Creates a node with the passed text then adds it to the end of the list by
	// setting last to point to the new node and then changing last to point to 
	// the added node
	
	node *p = new node(text);
	
	if(last){
		last->down = p;
    } else {
        startSymb = p;
    }
	last = p;
	return p;
}

//******************************************************************************

bool productions::readFile(string fname) {
    bool rc = false;
    ifstream inFile;
    inFile.open(fname);
    char ch;
    char prev;
    int i = 0;
    if (!inFile.fail()) {
        rc = true;
        
        while (inFile.get(ch)) {
            if(ch != ' ' && ch != '\n' && ch != '-') {
                if((prev == '\n')||(i == 0)){
                    charNT(ch);
                } else {
                    charT(ch);
                }
                i = 1;
            }
            
            prev = ch;
        }

        inFile.close();
        
    }

    return rc;
}

//******************************************************************************

void productions::charNT(char c){
    string product;
	string s(1,c);
    lastNT = addNT(s,lastNT);
    nontermIdentifier(c);//denotes the char as a nonterminal
    lastT = NULL;
    
    
}
//******************************************************************************

void productions::charT(char c){

    if(c != '|' && c != '>' && c != ';'){
        terminalIdentifier(c);//denotes the char as a terminal
        product += string(1, c);//appends the char to the string to hold entire production
    } else if(c != '>') {//we have reached a bar
        if (lastT){
            lastT = add(product,lastT);
        } else {
            lastT = add(product,lastNT);//add new node that tracks productions for a specific nonterm
        }
        product = ' ';//essentially clearing for the next string that is a production
        }
        
}


//******************************************************************************

void productions::printGrammar() const {
    node *nt = startSymb;
    node *term = startSymb->next;
    while(nt->down){   
        cout << nt->text;
        cout << "->";
        while(term->next){
            cout << term->text;
            cout << "|";
            term = term->next;
        }
        cout << term->text;
        cout << ";" << endl;
        nt = nt->down;
        term = nt->next;
    }

}