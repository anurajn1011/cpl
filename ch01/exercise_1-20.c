#include <stdio.h>

/* detab function */

/* Explanation: Consider the phrase 'This is'. Say the tab stops occur at every 5. Then, since this ends
at column 4, we add one space after and then proceed to the next word. 'is' will end on column 7, so we 
add 3 spaces after is. */

int main() 
{
	int c, tabs, column;
	tabs = 5;
	column = 1;
	
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			putchar(' ');
			while (column % tabs != 0) {
				putchar(' ');
				++column;
			}		
		}
		else {
			putchar(c);
		}
		++column;
	}
	return 0;
}