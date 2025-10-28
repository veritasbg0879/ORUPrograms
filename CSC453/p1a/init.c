// Name: 
// Assignment: Program 1 - Part 1
// Class: CSC453 Fall 2022
// File: init.c

#include "global.h"

struct entry keywords[] =
{
    {"if", IF, -1},
	{"else", ELSE, -1},
	{"while", WHILE, -1},
	{"return", RET, -1},
	{"arg", ARG, -1},
    {0, 0, 0}
};

void init() {
    struct entry *p;

    for (p = keywords; p->token; p++) {
	insert(p->lexptr, p->token, p->var_index);
    }
}

