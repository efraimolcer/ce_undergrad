/*	
	Write a C program that execute all instructions seen below.
		1. Initialize value x as 12, value y as 345
		2. Print out the binary representation of x
		3. Right shift 2 times to x & print out the binary representation
		4. Get a complement of x & print out the binary representation
		5. Operate ‘x AND y’ & print out the resulting value as a binary representation
		6. Operate ‘x INCLUSIVE OR y’ & print out the resulting value as a binary representation
		7. Operate ‘x EXCLUSIVE OR y’ & print out the resulting value as a binary representation
*/

#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS
#include <stddef.h> // size_t
#include <limits.h> // CHAR_BIT

void display_binary(unsigned int num){
	unsigned int	mask = 1 << (CHAR_BIT * (sizeof(unsigned int)) - 1);
	
	for (size_t i = 0; i < CHAR_BIT * sizeof(unsigned int); i++){
		putchar(num & mask ? '1' : '0');
		num <<= 1;
	}
}

int main(){
	unsigned int	x = 12,
					y = 345;
	
	// Print out the binary representation of x
	printf("%30s%u\n", "Decimal representation of x = ", x);
	printf("%30s", "Binary representation of x = ");
	display_binary(x);
	
	// Left shift 4 times to x & print out the binary representation
	printf("\n\n%30s", "2 times right-shifted x = ");
	display_binary(x >> 2);
	
	// Get a complement of x & print out the binary representation
	printf("\n%30s", "Complement of x = ");
	display_binary(~x);
	
	// Print binary representations of x and y
	printf("\n\n%30s", "Binary representation of x = ");
	display_binary(x);
	printf("\n%30s", "Binary representation of y = ");
	display_binary(y);
	
	// Operate ‘x AND y’ & print out the resulting value as a binary representation
	printf("\n\n%21d & %d = ", x, y);
	display_binary(x & y);
	
	// Operate ‘x INCLUSIVE OR y’ & print out the resulting value as a binary representation
	printf("\n%21d | %d = ", x, y);
	display_binary(x | y);
	
	// Operate ‘x EXCLUSIVE OR y’ & print out the resulting value as a binary representation
	printf("\n%21d ^ %d = ", x, y);
	display_binary(x ^ y);
	
	return 0;
}