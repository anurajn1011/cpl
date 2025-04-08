/*
	getch and ungetch functions from section 4.3 of K&R
*/

#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE]; //global scope due to the need to access by both functions
int bufp = 0;

int getch()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	}
	else {
		buf[bufp++] = c;
	}
}