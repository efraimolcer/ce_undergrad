/*	
	Write a program that
		1. Gets a sequence of data from the user
		2. Calculate cumulative average
		3. Calculate moving average for N
		4. Print them to the screen
	+ Cumulative Average is the average of the data up until the newest data.
	+ Simple Moving Average is the average of the newest n data.
	+ Use different functions for different operations
*/

#include <stdio.h>
#define SIZE 1000

/*
 * @func	Get array size from the user
 * @return	size: Entered size (capacity) of the array
 * @param	-
 */
int get_size(){
	int size;
	
	do{
		printf("How many values you want to enter: ");
		scanf("%d", &size);
	} while (size <= 0 || size >= SIZE);
	
	return size;
}

/*
 * @func	Get n value for simple moving average from the user
 * @return	n: Entered n value
 * @param	-
 */
int get_n(){
	int n;
	
	do{
		printf("Enter the value 'n' to calculate simple moving average: ");
		scanf("%d", &n);
	} while (n <= 0);
	printf("\n");
	
	return n;
}

/*
 * @func	Get value from the user
 * @return	value: Entered value
 * @param	i: Current index number in the array for the entered value
 */
double get_value(int i){
	double value;
	
	printf("Enter %d. value: ", i);
	scanf("%lf", &value);
	
	return value;
}

/*
 * @func	Calculate & print cumulative average for the current position
 * @return	sum: Summation of all values up-to-now
 * @param	num: Current value in the array
 * 			ctr: Count of numbers up-to-now
 * 			sum: Summation of all values for the previous step
 */
double cumulative_avg(int num, int ctr, double sum){
	double cum_avg;
	
	sum += num;
	cum_avg = sum / ctr;
	
	printf("Cumulative Average: %.2f\n", cum_avg);
	
	return sum;
}

/*
 * @func	Calculate & print simple moving average for the current position
 * @return	sum: Summation of most recent (last) n values
 * @param	arr: Array to store all values given by the user
 * 			i: Current index value for the array
 * 			n: Entered n value for simple moving average from the user
 * 			sum: Summation of most recent n values for the previous step
 */
double simple_moving_avg(double arr[], int i, int n, double sum){
	double mov_avg;
	
	sum += arr[i];
	
	if (i >= n){
		sum -= arr[i - n];											// Remove rigth-most (n+1)th value
		mov_avg = sum / n;
		printf("Simple Moving Average: %.2f\n\n", mov_avg);
	}
	else
		printf("\n");												// Put a break-line if there is no simple moving avg.
	
	return sum;
}

int main(){
	double	arr[SIZE],
			sum_cum = 0,
			sum_mov = 0;
	int 	size,
			n;
	
	size	= get_size();
	n		= get_n();
	
	arr[0] = 0;
	for (int i = 1; i < size; i++){
		// Get values
		arr[i] = get_value(i);
		
		// Calculate & Print cumulative average
		sum_cum = cumulative_avg(arr[i], i, sum_cum);
		
		// Calculate & Print simple moving average
		sum_mov = simple_moving_avg(arr, i, n, sum_mov);
	}
	
	return 0;
}