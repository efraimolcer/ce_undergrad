/*
	The value of ln(1 + x) can be calculated using the formula given below.
	ln (1 + x) = x - x^2/2! + x^3/3! - x^4/4! + ...
	
	Write a C function that takes a real number x and an integer n as its arguments and returns the value of ln(1 + x) where n determines the number of terms in the summation.
	Don't use the pow function.
*/

#include <stdio.h>

double ln(double x, int n){
	double	result = 0;
	double	num = 1;
	
	// Generate each term of the summation.
	for (int i = 1; i <= n; i++){
		// Increase the power.
		num *= x;
		
		// If the order number for a term is even, change the sign of the term.
		if (i % 2 == 0)
			result -= num / i;
		else
			result += num / i;
	}

	return result;
}

int main(){
	double	x = 20;
	int		n = 1;
	
	printf("%lf\n", ln(x, n));
	
	return 0;
}