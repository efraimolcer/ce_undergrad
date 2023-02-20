/*	
	Write a C program that finds the actual floor at an elevator that has a missing 13th floor.
		1. Ask for a floor.
		2. Convert the given floor to actual floor.
		3. Print out the actual floor.
	+ Users can write what they want, there is no limitation.
	+ The 13th floor is missing.
*/

#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS

int main()
{
	int floor;

	printf("Enter the floor number: ");
	scanf("%d", &floor);

	if (floor > 13){
		floor--;
	}

	printf("Actual floor: %d\n", floor);

	return EXIT_SUCCESS;
}