/*
	This file contains the getint function defined in Chapter 5 of K&R
*/

#include <stdio.h>
#include <ctype.h>
#include "getint_getfloat.h"

int getint(int *pn)
{
	int c, sign;
	
	while (isspace(c = getch())) { //to skip white space
		continue;
	}
	
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') { //if the current entry is not a sign or digit
		ungetch(c);
		return 0;
	}
	
	sign = (c == '-') ? -1 : 1; //setting the sign
	if (c == '+' || c == '-') {
		c = getch(); //moving on since the sign has already been processed
	}
	for (*pn = 0; isdigit(c); c = getch()) {
		*pn = 10 * *pn + (c - '0'); //constructing the integer
	}
	*pn *= sign; //multiply the sign, therefore completing the computation of the pointer
	
	if (c != EOF) {
		ungetch(c);
	}
	
	return c;
}