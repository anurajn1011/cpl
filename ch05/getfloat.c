/*
	This is my code for the floating point version of getint. This is exercise 5.2 in K&R
*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "getint_getfloat.h"

float getfloat(float *pn)
{
	int c, sign; //starts of the same as getint, some minor differences
	
	while (isspace(c = getch())) { //to skip white space
		continue;
	}
	
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') { //if the current entry is not a sign or digit, '.' denotes decimal
		ungetch(c);
		return 0;
	}
	
	sign = (c == '-') ? -1 : 1; //setting the sign
	if (c == '+' || c == '-') {
		c = getch(); //moving on since the sign has already been processed
	}
	
	// we begin to differ noticeably from getint. Now, we want to compute the integer portion as before.
	int decimal = 0;
	for (*pn = 0; isdigit(c) || c == '.'; c = getch()) {
		if (c == '.') {
			decimal = 1;
		}
		else {
			if (decimal < 1) {
				//proceed as normal, like with the getint case
				*pn = 10 * *pn + (c - '0');
			}
			else {
				//now we are at the decimal part
				*pn = *pn + ((float)(c - '0')/pow(10.0, decimal));
				++decimal;
			}
		}
	}
	
	*pn *= sign; //multiply the sign, therefore completing the computation of the pointer
	
	if (c != EOF) {
		ungetch(c);
	}
	
	return c;
}