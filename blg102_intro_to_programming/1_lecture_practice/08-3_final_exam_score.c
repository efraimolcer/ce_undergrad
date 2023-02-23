/*	
	Write a C program that computes the final exam score
		1. Ask the scores of each questions in the final exam
		2. Calculate the total score without the minimum score
		3. Print out the total score of the final exam
	+ The final exam has 6 question. One of them is additional question. Remove the smallest score and sum all other score.
	+ User must enter scores for all questions.
*/

#include <stdio.h>
#define SIZE 6

int main(){
	int arr[SIZE],
		min = 100,
		score = 0,
		min_pos;
	
	for (int i = 0; i < SIZE; i++){
		// Get question scores
		printf("Enter score of %d. question: ", i + 1);
		scanf("%d", &arr[i]);
		
		// Find the minimum score
		if(min > arr[i]){
			min = arr[i];
			min_pos = i;
		}
	}
	
	// Calculate the total score
	for (int i = 0; i < SIZE; i++){
		if (i != min_pos)
			score += arr[i];
	}
	printf("Final score: %d\n", score);
	
	return 0;
}