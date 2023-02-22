/*	
	Write a function that will return the number of digits in a positive integer.
	Don't use math functions like pow or log10.
*/

#include <stdio.h>

int digit_count(int num){
	int digit = 0;

	while (num != 0){
		num /= 10;
		digit++;
	}

	return digit;
}

int main(){
	int num = 12350;
	printf("Digit count for %d: %d\n", num, digit_count(num));

	return 0;
}