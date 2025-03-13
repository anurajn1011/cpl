#include <stdio.h>

/* This is the code for exercises 1.8-10 */

int main() 
{
	//Exercise 1-8
	int c, total;
	total = 0;
	
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			++total;
		}
	}
	printf("Number of newlines, blanks, and tabs: %d\n", total);
	
	// Exercise 1-9
	int character;
	
	while ((character = getchar()) != EOF) {
		if (character == ' ') {
			while (character == ' ') {
				character = getchar();
			}
			putchar(' ');
		}
		putchar(character);
	}
	printf("\n");
	
	//Exercise 1-10
	int cha;
	
	while ((cha = getchar()) != EOF) {
		if (cha == '\t') {
			printf("\\t");
		} if (cha == '\b') {
			printf("\\b");
		} if (cha == '\\') {
			printf("\\\\");
		} else {
			putchar(cha);
		}
	}
}