/*	
	Write a C program that finds the actual floor at an elevator that has a missing 13th floor.
		1. Ask for a floor.
		2. Convert the given floor to actual floor.
		3. Print out the actual floor.
	+ The elevator panel has buttons labeled 1 through 20.
	+ The 13th floor is missing.
	+ In each of cases except above conditions, it will give an error message and exit the program.
*/

#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE

int main()
{
	int floor;

	printf("Enter the floor number: ");
	scanf("%d", &floor);

	if (floor == 13 || floor <= 0 || floor > 20){
		printf("There is no floor %d. Please get out of the elevator!\n", floor);
		return EXIT_FAILURE;
	}

	if (floor > 13){
		floor--;
	}

	printf("Actual floor: %d\n", floor);

	return EXIT_SUCCESS;
}