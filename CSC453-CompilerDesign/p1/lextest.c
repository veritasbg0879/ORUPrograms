// Name: Chloe Winkler, Bella Goodman, Lara Silverthorn, Hanna Fontanez
// Assignment: Program 1 - Part 1
// Class: CSC453 Fall 2022
// File: lextest.c

#include <stdio.h>
#include "global.h"

int
main(int argc, char* argv[])
{
    init();
	//will print the number of arguments and and first argument
    fprintf(stderr, "argc = %d\nargv[0] = %s\n", argc, argv[0]);

    int t = 0;
    do {
	t=lexan();
	if (t != NONE) {
	    putchar('<');
	    if (t < DONE) {
			printf("%c,%d> ", (char)t, -1);
	    } else {
			switch(t) {

				//if you have reached the end of the input print and break
				case DONE:
					printf("DONE");
					printf(",%d> ", symtable[tokenval].var_index);
					break;

				//if the token is an identifier print
				case ID:
					printf("ID");
					printf(",%d> ", tokenval);
					break;
			
				//if the token is 8bit int token
				case INT8:
					printf("INT8");
					printf(",%d> ", tokenval);
					break;
				
				//if token is 16bit int token
				case INT16:
					printf("INT16");
					printf(",%d> ", tokenval);
					break;
				
				//if token is 32bit int token
				case INT32:
					printf("INT32");
					printf(",%d> ", tokenval);
					break;
				
				//if token is an argument token
				case ARG:
					printf("ARG");
					printf(",%d>", tokenval);
					break;

				//if token is return token
				case RET:
					printf("RET");
					printf(",%d>", tokenval);
					break;
			}
	    }
	}
	//go until the end of the file is reached
    } while (!(t == DONE || t == EOF));
	//print newline at end of file
    putchar('\n');
    return 0;
}
