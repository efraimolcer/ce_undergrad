/*	
	Write a C program that plays the dice game known as craps.
		1. Create random number for player.
		2. Run the program based on rules.
		3. Print out the result as "You won!" or "You Lost! House won!"
	+ User rolls two dice. Each dice has six faces from 1 to 6.
	+ After the dice have come to rest, the sum of the spots on the two upward faces is calculated.
	+ If the sum is 7 or 11 on the first throw, the player wins.
	+ If the sum is 2, 3, or 12 on the first throw (called “craps”), the player loses (i.e., the “house” wins).
	+ If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then that sum becomes the player’s “point.”  To win, you must continue rolling the dice until you “make your point.”. The player loses by rolling a 7 before making the point.
*/

#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <time.h>	// time

int throw(){
	// Generate two random dice value
	int dice_1	= rand() % 6 + 1;
	int dice_2	= rand() % 6 + 1;

	// Sum and return the result
	int sum	= dice_1 + dice_2;
	printf("Player rolled %d + %d = %d\n", dice_1, dice_2, sum);	
	return sum;
}

void point(target){
	int sum;
	printf("Target point: %d.\nTry untill reach this point.\n\n", target);

	// Repeat the game until reaching the target or the value '7'
	while (sum != target && sum != 7)
		sum = throw();
	
	// Print the game result
	if (sum == 7)
		printf("You Lost!\n");
	else
		printf("You Won!\n");
}

int main(){
	int sum;
	
	// Roll 2 dice first time
	srand(time(NULL));
	sum = throw();


	// Check sum of the dice values
	if (sum == 4 || sum == 5 || sum == 6 || sum == 8 || sum == 9 || sum == 10)
		point(sum);
	else if (sum == 7 || sum == 11)
		printf("You won!\n");
	else
		printf("You lost!\n");

	return 0;
}