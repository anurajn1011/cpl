#include <stdio.h>

/* printing histograms */

int main() 
{
	// Exercise 1-13: write a program to print a histogram of the lengths of words
	int c, word;
	int wordLengths[25];
	word = 0;
	
	//create the array
	for (int i = 0; i < 25; ++i) {
		wordLengths[i] = 0;
	}
	
	//get the lengths of words
	while ((c = getchar()) != EOF) {
		if (c != '\n' && c != ' ' && c != '\t') {
			++wordLengths[word]; //increment the length of the word
		}
		else { //if we have come to the end of the word, move to the next index for the next word
			++word;
		}
	}
	
	//print the horizontal chart
	for (int i = 0; i < 25; ++i) {
		printf("%d: ", i);
		for (int j = 0; j < wordLengths[i]; ++j) {
			printf("|");
		}
		printf("\n");
	}
	
	// Exercise 1-14: write a program to print histogram of the frequencies of different characters;
	//let's count a,b,c,d,e,f,g, and h
	int character;
	int frequencies[26];
	
	//create the array
	for (int i = 0; i < 26; ++i) {
		frequencies[i] = 0;
	}
	
	//every index represents an alphabet starting from a at 0
	while ((c = getchar()) != EOF) {
		if (c >= 'A' && c <= 'Z') { //handles uppercase inputs
			c = c + ('a' - 'A');
		}
		if (c >= 'a' && c <= 'z') {
			++frequencies[c - 'a'];
		}
	}
	
	for (int i = 0; i < 26; ++i) {
		printf("%d: ", i);
		for (int j = 0; j < frequencies[i]; ++j) {
			printf("|");
		}
		printf("\n");
	}	
}