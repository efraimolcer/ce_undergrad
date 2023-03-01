/*	
	Write a C program that print out the reverse of given sentence with using file functions.
		1. Get the sentence from user
		2. Print out the given sentence
		3. Get another sentence
		4. Reverse the sentence
		5. Print out the reverse sentence
	+ Use getchar, fgets, putchar & puts functions at least one time.
	+ Character limit for a sentence is 100.
*/

#include <stdio.h>	// getchar, fgets, putchar, puts
#include <stddef.h> // site_t

#define LIM 100

int main(){
	char 	sentence[LIM];
	
	// Get a sentence
	printf("Enter a sentence: ");
	
	size_t lim = 0;
	for (char ch; (ch = getchar()) != '\n'; lim++)
		sentence[lim] = ch;
	sentence[lim] = '\0';
	
	// Print the sentence
	printf("Given sentence: ");
	puts(sentence);
	
	// Get another sentence
	printf("\nEnter another sentence: ");
	fgets(sentence, LIM, stdin);
	
	// Find the total number of characters & the last character of the sentence
	char*	ptr = sentence;
	
	lim = 0;
	while (*ptr != '\n'){
		lim++;
		ptr++;
	}
	ptr--;
	
	// Reverse the sentence
	printf("Reversed sentence: ");
	for (; lim > 0 ; lim--){
		putchar(*ptr);
		ptr--;
	}
	putchar('\n');
	
	return 0;
}