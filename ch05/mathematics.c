/* 
	power function for the decimal expansion
*/

#include <stdio.h>

int power(int base, int pow)
{
	int total = 1;
	
	for (int foo = pow; foo > 0; --foo) {
		total *= base;
	}
	
	return total;
}