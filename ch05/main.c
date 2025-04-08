// main function
#include <stdio.h>
#include "getint_getfloat.h"

int main()
{
	printf("Enter a number, either int or float");
	
	float num;
	
	if (getfloat(&num)) {
		printf("You entered the number: \t%f", num);
	}
	else {
		printf("invalid number");
	}
	
	return 0;
}
	