/*Bella Goodman
CSC453 Compiler Design, Wheat
Program 4
This is the symbol table for the compiler. It takes in every
value and gives it a spot in the table. all of this code was given to me
*/
#include "global.h"

#define STRMAX 999
#define SYMMAX 100

char lexemes[STRMAX];

int lastchar = -1;

struct Symbol symtable[SYMMAX];

int lastentry = 0;
int varIndex = 3;       /* UPDATE WHEN NECESSARY */

Symbol *lookup(const char *s) {
    int i;
    Symbol *rc = NULL;

    for (i = 0; i < lastentry; i++) {
	if (strcmp(symtable[i].lexptr, s) == 0) {
	    rc = &symtable[i];
	    break;
	} 
    }
    return(rc);
}

Symbol *insert(const char s[], int tok) {

    if (lastentry+1 == SYMMAX) {
	error("symbol table full");
    }

    symtable[lastentry].token = tok;

    symtable[lastentry].lexptr = (char *)malloc(strlen(s)+1);
    strcpy(symtable[lastentry].lexptr, s);

    lastentry++;

    return(&symtable[lastentry-1]);
}

void dumpSumbolTable() {
    int i;
    fprintf(stderr, "Symbol table as %d entries\n", lastentry);

    for (i = 0; i < lastentry; i++) {
	fprintf(stderr, "%3d: ", i);
	fprintf(stderr, "for symbol %s\n", symtable[i].lexptr);
    }
}

