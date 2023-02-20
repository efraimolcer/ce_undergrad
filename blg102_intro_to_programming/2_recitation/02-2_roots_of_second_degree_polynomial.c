/*	
	A second degree polynomial has the form: ax^2 + bx + c
	In order to solve it, we first need to find discriminant discriminant = b^2 – 4ac
	Then, the roots can be found as
		x1 = ( (-b) + sqrt(discriminant) ) / (2a)
		x2 = ( (-b) - sqrt(discriminant) ) / (2a)

	Write a C program that
		1. Asks for a, b, and c coefficients
		2. Calculates discriminant and uses it to find the roots (x1 and x2)
		3. Prints out the roots x1 and x2
*/

#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS
#include <math.h>	// pow, sqrt

int main()
{
	double a, b, c, disc, x1, x2;

	printf("polynomial is defined as ax^2 + bx + c\n");
	printf("enter a number for a: ");
	scanf("%lf", &a);

	printf("enter a number for b: ");
	scanf("%lf", &b);

	printf("enter a number for c: ");
	scanf("%lf", &c);

	disc = pow(b, 2) - (4 * a * c);
	x1 = (b * -1 + sqrt(disc)) / (2 * a);
	x2 = (b * -1 - sqrt(disc)) / (2 * a);

	printf("x1: %.2f\nx2: %.2f\n", x1, x2);

	return EXIT_SUCCESS;
}