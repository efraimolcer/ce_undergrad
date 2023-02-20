/*	
	Write a C program that converts the total minute to hours and minutes.
		1. Ask for a total minute.
		2. Convert the total minute to hours and minutes.
		3. Print out the hours and minutes.
	+ Users can write what they want, there is no limitation.
*/

#include <stdio.h>

int main()
{
	const int MINUTES_IN_HOUR = 60;				// Always constant
	int duration = 0;

	printf("Enter duration [min]: ");
	scanf("%d", &duration);

	int hours = duration / MINUTES_IN_HOUR;		// Get integer division which means hours
	int minutes = duration % MINUTES_IN_HOUR;	// Get remainder which means minutes
	
	printf("%d minutes equal to %d hours %d minutes\n", duration, hours, minutes);

	return 0;
}