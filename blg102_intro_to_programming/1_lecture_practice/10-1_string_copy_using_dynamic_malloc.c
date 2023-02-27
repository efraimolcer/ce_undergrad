/*	
	Write a program that prints out copy of name.
		1. Get a string from the user
		2. Create a ‘str_cpy’ function and copy the string into double-sized string
		3. Print out both strings
	+ Use malloc.
	+ Assume that user inputs are valid and no need to check.
	+ String can be maximum 50 characters.
*/

#include <stdio.h>
#include <stdlib.h> // malloc

#define MAX 50

void copy_string(char* target, char* source){
	int i;
	
	for (i = 0; source[i] != '\0'; i++)
		target[i] = source[i];
	target[i] = '\0';
}

int main(){
	// Create dynamic memories for arrays
	char* str_ori = (char*)malloc(MAX * sizeof(char));
	char* str_cpy = (char*)malloc(MAX * 2  * sizeof(char));
	
	// Get a string
	printf("Ente a string: ");
	scanf("%s", str_ori);
	
	// Copy the string into double-sized string
	copy_string(str_cpy, str_ori);
	
	// Print both strings
	printf("Original String: %s\nCopy String: %s\n", str_ori, str_cpy);
	
	// Free dynamic memories
	free(str_ori);
	free(str_cpy);
	
	str_ori = NULL;
	str_cpy = NULL;
	
	return 0;
}