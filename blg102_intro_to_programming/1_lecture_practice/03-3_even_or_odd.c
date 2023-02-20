/*	
	Write a C program that gives the even/odd type of figure, which is between 0 and 9.
		1. Ask for a figure.
		2. Choose the right even/odd type for the figure.
		3. Print out the even/odd type of the figure.
	+ All figures must be between 0 and 9. For more than 9 and less than 0, we will want to give an error message and exit the program.
*/

#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE

int main()
{
	int figure;

	printf("Write a figure from 0 to 9: ");
	scanf("%d", &figure);

	if (figure < 0 || figure > 9){
		printf("%d is not acceptable.\nProgram closed.\n", figure);
		return EXIT_FAILURE;
	}

	switch (figure){
		case 0:
		case 2:
		case 4:
		case 6:
		case 8:
			printf("%d is even.\n", figure);
			break;
		default:
			printf("%d is odd.\n", figure);
			break;
	}

	return EXIT_SUCCESS;
}