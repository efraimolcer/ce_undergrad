/*	
	Write a function(functions) to calculate combination without any library functions.
	Calculating n!, r!, (n-r)! does same multiplication many times
	Design a combination with better performance where the code does not do the same multiplication many times.
	+ C(n, r) = n! / (r! * (n-r)!)
*/

#include <stdio.h>

/*
 * @func	Calculate the combination
 * @return	The combination value
 * @param	n: The 'n' term for a combination
 * 			r: The 'r' term for a combination
 */
int combination(int n, int r){
	int nom		= 1,
		den_1	= 1,
		den_2	= 1,
		min;
	
	// 'n' or 'n - r' must be minimum. Select which one is it.
	if (r < n - r)
		min = r;
	else
		min = n - r;
	
	// Calculate min! which is the first term of the denominators
	for (int i = 1; i <= min; i++)
		den_1 *= i;
	
	// Calculate (n - min)! which is the second term of the denominators. Continue to the multiplication from previously calculated first denominator.
	den_2 = den_1;
	for (int i = min + 1; i <= n - min; i++)
		den_2 *= i;
	
	// Calculate n! which is the term of the numerator. Continue to the multiplication from previously calculated second denominator.
	nom = den_2;
	for (int i = n - min + 1; i <= n; i++)
		nom *= i;
	
	return nom / (den_1 * den_2);
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