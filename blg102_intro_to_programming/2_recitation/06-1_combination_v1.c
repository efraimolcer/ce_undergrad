/*	
	Write a function(functions) to calculate combination without any library functions.
		1. Design your code considering performance and functionality.
		2. Test with inputs.
	+ C(n, r) = n! / (r! * (n-r)!)
*/

#include <stdio.h>

/*
 * @func	Calculate the factorial
 * @return	The factorial value
 * @param	num: The number that is used to find the factorial
 */
int factorial(int num){
	int result = 1;
	
	for (int i = 2; i <= num; i++){
		result *= i;
	}

	return result;
}

/*
 * @func	Calculate the combination
 * @return	The combination value
 * @param	n: The 'n' term for a combination
 * 			r: The 'r' term for a combination
 */
int combination(int n, int r){
	int result = 1;

	result = factorial(n) / (factorial(r) * factorial (n - r));
	return result;
}

int main(){
	int n, r;

	printf("Enter the n: ");
	scanf("%d", &n);

	printf("Enter the r: ");
	scanf("%d", &r);

	printf("C(%d, %d) = %d\n", n, r, combination(n, r));

	return 0;
}