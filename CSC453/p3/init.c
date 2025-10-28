#include "global.h"
#include "mycc.h"


struct Symbol keywords[] =
{
	{ "break",	BREAK, -1 },
	{ "do",		DO, -1 },
	{ "else",	ELSE, -1 },
	{ "for",	FOR, -1 },
	{ "if",		IF, -1 },
	{ "return",	RETURN, -1 },
	{ "while",	WHILE, -1 },
	{ NULL,         0, 0 }
};

/* init - populates global symbol table with keywords */
void init()
{
	struct Symbol *p;

	for (p = keywords; p->token; p++)
		insert(p->lexptr, p->token, p->localvar);
}

