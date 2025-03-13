#include <stdio.h>

/* writing a program that prints inputs one word per line */

int main()
{
	int c;
	
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			putchar('\n');
		}
		else {
			putchar(c);
		}
	}
}