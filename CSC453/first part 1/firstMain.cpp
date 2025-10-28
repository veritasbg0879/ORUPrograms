/* Otters 
Hanna Fontanez, Bella Goodman, Lara Silverthorn, Chloe Winkler
CSC 453 Fall 2024
Assignment: Program Midterm Part 1: This is the Main for the first file. It calls
the constructor, calls the readfile function, and prints the grammar so we can see
the output of all our hard work. 
9/7/24
*/

//include a bunch of things so it'll run properly
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

//include the header so we know what we're working off of
#include "first.h"

//this is useful in everything ever so include it here
using namespace std;

//******************************************************************************
/*this is the only thing in our main class. we call the productions constructor
and we call the readFile to set up all of our arrays and linked lists inside
the function. After that, we call the printGrammar function so we can obtain
an output file with the properly organized grammar.
*/

int main(int argc, char *argv[]) {
    productions *myProductions = new productions();
    myProductions->readFile("C:/Users/Verit/OneDrive/Documents/first.txt");
    myProductions->printGrammar();

};