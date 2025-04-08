// main function
#include <stdio.h>
#include "getint_getfloat.h"

int main()
{
	printf("Enter a number, either int or float:\t");
	
	float num;
	
	if (getfloat(&num)) {
		printf("You entered the number: %f", num);
	}
	else {
		printf("invalid number");
	}
	
	return 0;
}
	