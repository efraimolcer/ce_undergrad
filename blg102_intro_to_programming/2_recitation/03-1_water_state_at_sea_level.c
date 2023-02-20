/*	
	Water is liquid, solid, or gaseous at a given temperature at sea level :
		Water becomes solid (i.e., freezes) at 0° Celsius or 32° Fahrenheit.
		Water becomes gas (i.e., boils) at 100° Celsius or 212° Fahrenheit.
		Water is liquid in between these two temperatures.
	
	Write a C program that
		1. Asks and reads a temperature value and the letter C for Celsius or F for Fahrenheit
		2. Decides on the state of water at the given temperature at sea level
		3. Prints out whether water is liquid, solid, or gaseous at the given temperature at sea level
*/

#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE

int main()
{
	int temp;
	char unit;

	printf("C for Celsius\nF for Fahrenheit\nEnter the temperature unit: ");
	scanf("%c", &unit);

	printf("What is the temperature in %c: ", unit);
	scanf("%d", &temp);

	if (unit == 'C'){
		printf("Water is ");

		if (temp <= 0)
			printf("solid");
		else if (temp > 0 && temp < 100)
			printf("liquid");
		else
			printf("gaseous");
	}
	else if (unit == 'F'){
		printf("Water is ");

		if (temp <= 32)
			printf("solid");
		else if (temp > 32 && temp < 212)
			printf("liquid");
		else
			printf("gaseous");
	}
	else{
		printf("Given temperature unit is undefined.\nProgram is closed.\n");
		return EXIT_FAILURE;
	}
	printf(" at %d°%c\n", temp, unit);

	return EXIT_SUCCESS;
}