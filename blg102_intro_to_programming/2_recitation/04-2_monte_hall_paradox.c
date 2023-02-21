/*	
	Write a C program that
		1. Calculates the winning ratio for both changing & unchanging selection for Monte Hall Paradox
	+ Iteration count is constant: 10000
*/

#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <time.h>	// time

#define LIMIT 10000

int main(){
	int door_prize, door_selected;
	int ctr_change = 0, ctr_not = 0;

	srand(time(NULL));					// Totally random numbers
	for(int i = 0; i < LIMIT; i++){
		door_prize		= rand() % 3;	// Door numbers: 0, 1, 2
		door_selected	= rand() % 3;
		
		if(door_selected == door_prize)
			ctr_not++;
		else if (door_selected != door_prize)
			ctr_change++;
	}

	printf("Winning ratio for changing the selection: %f\n", (float)ctr_change / LIMIT);
	printf("Winning ratio for unchanging the selection: %f\n", (float)ctr_not / LIMIT);

	return 0;
}