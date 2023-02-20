/*	
	To convert Fahrenheit to Celsius, we use the formula: Celsius = 5*(Fahrenheit - 32)/9
	Write a C program that
		1. Asks for a temperature value in Fahrenheit
		2. Converts the entered temperature value to Celsius • Prints out the temperature in Celsius
*/

#include <stdio.h>

int main()
{
	double	fahrenheit, celsius;

	printf("Write a temperature in Fahrenheit: ");
	scanf("%lf", &fahrenheit);

	celsius = 5 * (fahrenheit - 32) / 9;

	printf("%.1f Fahrenheit = %.1f Celsius\n", fahrenheit, celsius);

	return 0;
}