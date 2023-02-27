/*	
	Develop a program that uses a triangular array to simulate a Galton board.
		1. Simulate a board with ten rows of pegs
		2. Each row requires an array of counters
		3. Print each row
		4. Simulate a ball bouncing through the pegs
		5. Print out the total count of balls for each step and options
	+ A Galton board consists of a pyramidal arrangement of pegs and a row of bins at the bottom.
	+ Balls are dropped onto the top peg and travel toward the bins.
	+ At each peg, there is a 50 percent chance of moving left or right.
	+ The balls in the bins approximate a bell-curve distribution.
	+ The Galton board can only show the balls in the bins, but we can do better by keeping a counter for each peg, incrementing it as a ball travels past it.
	+ Run the game 1000 times.
*/

#include <stdio.h>
#include <stdlib.h> // malloc, rand, srand
#include <time.h>

#define ROWS 10
#define RUN 1000

int main(){
	int* rows[ROWS];
	
	// Create triangular array
	for (int i = 0; i < ROWS; i++){
		rows[i] = (int*)malloc((i + 1) * sizeof(int));
		
		// Initialize all cells to 0
		for (int j = 0; j < i + 1; j++)
			rows[i][j] = 0;
	}
	
	// Run the game RUN times
	srand(time(NULL));
	for (int run = 0; run < RUN; run++){
		// Add 1 to cell on the top
		
		rows[0][0]++;
		int j = 0;
		
		// Increase the total number of cell on the current row
		for (int i = 1; i < ROWS; i++){
			// If even, go to the right, else go to the down
			if(rand() % 2 == 0)
				j++;
			rows[i][j]++;
		}
	}
	
	// Print the game plan
	for (int i = 0; i < ROWS; i++){
		// Print empty characters for aligning to the center
		int center = (ROWS - i) * 2;
		printf("%*c", center, ' ');
		
		// Print total counts for each cells
		for(int j = 0; j < i + 1; j++){	
			printf("%4d", rows[i][j]);
		}
		printf("\n");
	}
	
	// Free all dynamic memories
	for (int i = 0; i < ROWS; i++)
		free(counts[i]);
	
	return 0;
}