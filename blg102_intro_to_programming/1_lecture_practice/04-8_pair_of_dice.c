/*	
	Write a C program that print out random 2 numbers for pair of dice.
		1. Print out 2 numbers which are generated randomly based on pair of dice 10 times.
	+ All numbers must be between 1 and 6.
	+ Numbers must be selected totally randomly. Not use any logical statement.
	+ Program must gives all numbers come from 10 times in a one prompt.
*/

#include <stdio.h>
#include <stdlib.h> // rand, srand, EXIT_SUCCESS
#include <time.h>	// time

int main(){
	srand(time(NULL));

	for (int i = 0; i <= 10; i++)
		printf("#%2d: %3d %3d\n", i, rand() % 6 + 1, rand() % 6 + 1);

	return EXIT_SUCCESS;
}