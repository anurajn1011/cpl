#include <stdio.h>

/* entab exercise */

#define TABSTOP 4

int main()
{
	int c, column, blanks, tabs;
	column = 1;
	blanks = 0;
	tabs = 0;
	
	while ((c = getchar()) != EOF) {
		if (c == ' ') { //keep incrementing if we encounter blanks
			if (column % TABSTOP != 0) {
				++blanks;
			}
			else {
				blanks = 0;
				++tabs;
			}
			++column;
		}
		else {
			for (int i = 0; i < tabs; ++i) {
				putchar('\t'); //accounting for the tabs
			}
			for (int j = 0; j < blanks; ++j) {
				putchar(' '); //acounting for the remaining blank spaces
			}
			blanks = 0;
			tabs = 0;
			putchar(c);
			++column;
		}				
	}
	
	return 0;
}