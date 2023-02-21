/*	
	Write a C program that
		1. Get a function ax^2+bx+c
		2. Calculates derivative on x = k
		3. Calculates the root iteratively
	+ The nonlinear equation is given: x^3 - x^2 + 2
	+ The derivative of the nonlinear equation is given: 3 * x^2 - 2 * x
	+ The random initial point is given: -50
	+ The epsilon value is given: 0.00001

	Hints
		- Line : (y2 - y1) = m * (x2 - x1)
		- Use 2 close points to calculate the derivative ((x+e) and (x-e))
		- You find the root when the error is very
		- Formula for Newton-Raphson Method: x_k - (f(x_k) / f'(x_k))
*/

#include <stdio.h>
#include <math.h>	// pow, fabs

#define EPSILON 0.00001
#define INITIAL -50

int main()
{
	double	curr, next;
	int		ctr = 1;

	next = INITIAL;
	do{
		curr = next;																		// The new current guess is the next guess of the previous step.
		printf("x_%d = %lf\n", ctr, next);

		next = curr - (pow(curr, 3) - pow(curr, 2) + 2) / (3 * pow(curr, 2) - 2 * curr);	// Calculate the next guess using the equation: x_k+1 = x_k - (f(x_k) / f'(x_k))
		ctr++;
	} while (fabs(next - curr) >= EPSILON);													// Check that difference between guess values is bigger than epsilon value (tolerance).

	printf("\nTHE ROOT\nx_%d = %lf\n", ctr, next);

	return 0;
}