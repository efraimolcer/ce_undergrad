/*	
	Write a C program to produce a table of powers.
		1. Print the output in the format as:
			(n. Row: x^1   x^2   x^3   x^4)
			1. Row:  1     1     1     1
			...      .     .     .     .
			10. Row: 10    100   1000  10000
*/

#include <stdio.h>
#include <math.h> // pow

int main()
{
	for (int i = 1; i <= 10; i++){
		printf("%2d. Row: ", i);
		for (int j = 1; j <= 4; j++){
			printf("%6.0lf ", pow(i, j));
		}
		printf("\n");
	}

	return 0;
}