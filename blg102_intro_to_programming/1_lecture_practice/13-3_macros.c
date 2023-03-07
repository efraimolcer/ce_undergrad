/*	
	Write a C program to check these macros & relevant usages.
		- square x * x
			* square(2 + 3)
			* square((2 + 3))
		- square (x) * (x)
			* square(2 + 3)
		- square printf("\n%20s%d\n", "square3(5) = ", ++x * ++x)
			* square(5)
*/

#include <stdio.h>

#define square1(x) x * x
#define square2(x) (x) * (x)
#define square3(x) printf("\n%20s%d\n", "square3(5) = ", ++x * ++x)

int main(){
	unsigned int res, x;
	
	// Check for x * x
	printf("%20s%d\n", "x * x = ", 5 * 5);
	
	res= square1(2 + 3);								// 2 + 3 * 2 + 3 = 11
	printf("%20s%d\n", "square1(2 + 3) = ", res);
	
	res= square1((2 + 3));								// (2 + 3) * (2 + 3) = 25
	printf("%20s%d\n", "square1((2 + 3)) = ", res);
	
	// Check for (x) * (x)
	printf("\n%20s%d\n", "(x) * (x) = ", 5 * 5);
	
	res= square2(2 + 3);								// (2 + 3) * (2 + 3) = 25
	printf("%20s%d\n", "square2(2 + 3) = ", res);
	
	// Check for increment & decrement
	x = 5;
	res= square2(x++);									// 5 * 6 = 30 | x = 7
	printf("%20s%d\n", "square2(5++) = ", res);
	
	x = 5;
	res= square2(++x);									// 6 * 7 = 42 | x = 7
	printf("%20s%d\n", "square2(++5) = ", res);
	
	x = 5;
	square3(x);											// Same as above
	
	return 0;
}