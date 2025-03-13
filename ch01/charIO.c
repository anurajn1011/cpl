#include <stdio.h>

/* copy input to output */

int main() 
{
	// verifying that the comparison operator is evaluated first
	int c;
	this while loop will spit out every character by character
	while (c = getchar() != EOF) {
		putchar(c);
	}
	
	//Exercise 1-6
	printf("%d", getchar() != EOF);
	// the value of end of file, Exercise 1-7
	printf("\n The value of EOF is: %d\n", EOF); //the output here is -1, which an unsigned char cannot be.
}