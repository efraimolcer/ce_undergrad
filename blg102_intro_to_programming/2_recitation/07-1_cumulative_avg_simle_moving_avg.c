/*	
	Write a program that
		1. Gets a sequence of data from the user
		2. Calculate cumulative average
		3. Calculate moving average for N
		4. Print them to the screen
	+ Cumulative Average is the average of the data up until the newest data.
	+ Simple Moving Average is the average of the newest n data.
*/

#include <stdio.h>
#define SIZE 1000

int main(){
	double	arr[SIZE],
			sum_cum = 0,
			sum_mov = 0,
			cum_avg = 0,
			mov_avg = 0;
	int		n;
	
	// Get the n value for the simple moving average
	do{
		printf("Enter the value 'n' to calculate simple moving average: ");
		scanf("%d", &n);
	} while (n <= 0);
	
	arr[0] = 0;																// Put 0 to the 0th index to simplify calculations below
	// Calculate & Print cumulative and simple moving averages
	for (int i = 1; i < SIZE; i++){
		// Gets a sequence of data from the user
		printf("\nEnter -1 to terminate the program.\nEnter a data: ");
		scanf("%lf", &arr[i]);
		
		// If -1 is entered, terminate the program
		if (arr[i] == -1){
			printf("Program closed.\n\n");
			break;
		}
		
		// Calculate & Print cumulative average
		sum_cum += arr[i];
		cum_avg	= sum_cum / i;
		printf("Cumulative Average: %.2f\n", cum_avg);
		
		// Calculate & Print simple moving average
		sum_mov += arr[i];
		
		if (i >= n){
			sum_mov -= arr[i - n];											// Remove rigth-most (n+1)th value
			mov_avg = sum_mov / n;
			printf("Simple Moving Average: %.2f\n", mov_avg);
		}
		else																// Put a break-line if there is no simple moving avg.
			printf("\n");
	}
	
	return 0;
}