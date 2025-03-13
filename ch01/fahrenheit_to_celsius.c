#include <stdio.h>

/* Printing Farenheit to Celsius Table */

#define LOWER 0 //symbolic constants, improves readability
#define UPPER 300
#define STEP 20

int main() 
{
	// float fahrenheit, celsius; //variable declaration
	// float lower, upper, step;
	
	// lower = 0;
	// upper = 300;
	// step = 20;
	
	// fahrenheit = lower;
	
	// printf("%3s%10s \n", "Fahrenheit", "Celsius");
	
	// while (fahrenheit <= upper) {
		// celsius = 5.0 * (fahrenheit - 32.0) / 9.0; //5/9 is computed as 0 due to integer truncation. 
		// printf("%5.0f %12.1f \n", fahrenheit, celsius); //%d denotes integer argument and %f is float; the precedent numbers denote space and the num after decimal denote space for decimals
		// fahrenheit = fahrenheit + step;
	// }
	
	// celsius to fahrenheit
	// upper = 150;
	// celsius = lower;
	
	// printf("%6s%12s \n", "Celsius", "Fahrenheit");
	
	// while (celsius <= upper) {
		// fahrenheit = (9.0/5.0) * celsius + 32.0;
		// printf("%5.0f %12.1f \n", celsius, fahrenheit);
		// celsius = celsius + step;
	// }
	
	//doing the previous in a for loop in descending fashion; Exercise 1-5	
	printf("%3s%10s \n", "Fahrenheit", "Celsius");
	for (float fahrenheit = UPPER; fahrenheit >= LOWER; fahrenheit = fahrenheit - STEP) {
		printf("%5.0f %12.1f \n", fahrenheit, (5.0/9.0) * fahrenheit - 32.0);
	}
}