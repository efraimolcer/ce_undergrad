/*	
	Body Surface Area (BSA) measures the total surface area of the body and is used to calculate drug dosages.
	BSA can be calculated with Boyd formula as follows: BSA(m^2) = 0.0003207 x Height^0.3 x Weight^(0.7285 - (0.0188 x log_10Weight))
	where Height is in cm and Weight is in grams

	Write a C program that
		1. Asks for height (cm) and weight (gr)
		2. Calculates BSA using Boyd formula
		3. Prints out the BSA
*/

#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS
#include <math.h>	// log10, pow

// Constants that are used in the formula.
#define CONST1 0.0003207
#define CONST2 0.7285
#define CONST3 0.0188

int main()
{
	double height, weight, exp, bsa;

	printf("Enter your height (cm): ");
	scanf("%lf", &height);

	printf("Enter your weight (gr): ");
	scanf("%lf", &weight);

	exp = CONST2 - (CONST3 * log10(weight));
	bsa = CONST1 * pow(height, 0.3) * pow(weight, exp);

	printf("Your BSA: %.4f m^2\n", bsa);

	return EXIT_SUCCESS;
}