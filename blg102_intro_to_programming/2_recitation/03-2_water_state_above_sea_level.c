/*	
	The boiling point of water drops by about one degree celsius for every 300 meters of altitude.

	Write a C program that
		1. Asks and reads a temperature value and the letter C for Celsius or F for Fahrenheit.
		2. Asks and reads the altitude in meters.
		3. Decides on the state of water at the given temperature at the given altitude.
		4. Prints out whether water is liquid, solid, or gaseous at the given temperature at the given altitude.
*/

#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE

int main()
{
	float temp, boiling;
	char unit;
	int altitude;

	printf("C for Celsius\nF for Fahrenheit\nEnter the temperature unit: ");
	scanf("%c", &unit);

	printf("What is the temperature in %c: ", unit);
	scanf("%f", &temp);

	// Convert Fahrenheit to the equivalent Celsius value.
	if (unit == 'F')
		temp = 5 * (temp - 32) / 9;
	// Check that the unit is acceptable or not.
	else if (unit != 'C'){
		printf("Given temperature unit is undefined.\nProgram is closed.\n");
		return EXIT_FAILURE;
	}

	printf("What is the altitude in meters: ");
	scanf("%d", &altitude);
	
	// Update the boiling point based on the altitude.
	boiling = 100 - altitude / 300;

	printf("Water is ");
	if (temp <= 0)
		printf("solid\n");
	else if (temp > 0 && temp < boiling)
		printf("liquid\n");
	else
		printf("gaseous\n");

	return EXIT_SUCCESS;
}