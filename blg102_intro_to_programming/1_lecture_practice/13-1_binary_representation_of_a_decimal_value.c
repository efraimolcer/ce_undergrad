/*	
	Write a C program that print out the binary code of given nonnegative integer number.
		1. Get a nonnegative integer value from the user
		2. Print out the binary code of the number
	+ Use bitwise operators
*/

#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS
#include <stddef.h> // size_t
#include <limits.h> // CHAR_BIT

void print_binary(unsigned int* num){
	unsigned int	bitwise_mask = 1 << (CHAR_BIT * sizeof(unsigned int) - 1);		// Shift right-most bit to the left-most to use as a mask
	int				bit;
	
	// Print out will be from left-most to the right-most, so compare from left-most
	for (size_t i = 0; i < CHAR_BIT * sizeof(unsigned int); i++){
		if((bitwise_mask & *num) == 0)												// If there is no '1 & 1', print 0
			putchar('0');
		else																		// Else, print 1
			putchar('1');
		
		if (i % 8 == 7)																// Group characters by 8
			putchar(' ');
		*num <<= 1;																	// Shift given value to the left by 1-bit
	}
}

int main(){
	unsigned int num;
	
	printf("Enter a non-negative value: ");
	scanf("%u", &num);
	
	print_binary(&num);
	
	return EXIT_SUCCESS;
}