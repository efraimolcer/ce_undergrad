/*	
	Write a C program that finds the sum of all digits.
		1. Ask for a number.
		2. Print out the sum of digits.
*/

#include <stdio.h>

int main()
{
	int	num;
	int sum = 0;

	printf("Enter a integer value: ");
	scanf("%d", &num);

	while (num > 0){
		sum += num % 10;
		num /= 10;
	}
	printf("Number: %d\nSum of digits: %d\n", num, sum);
	
	return 0;
}