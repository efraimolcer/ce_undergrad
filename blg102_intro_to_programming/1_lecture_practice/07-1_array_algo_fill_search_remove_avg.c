/*	
	Write a program that will do the all steps below.
		1. Ask for array values.
		2. Print out the array using element separators.
		3. Calculate and print out the sum and average values.
		4. Find and print out the maximum and minimum values.
		5. Ask to search particular value and print out the order number. Give an error for -1 or not existed value.
		6. Ask a value to remove particular value and remove the value. Give an error for -1 or not existed value.
		7. Print out the final array using element separators.
	+ Get 10 input to array. After getting 10 value, prints out ‘Thanks’ message.
	+ If user do not full the array, write 0 to all empty values.
	+ If -1 is written, finish to get a value.
*/

#include <stdio.h>
#include <stdbool.h>
#define SIZE 10

int main(){
	// Get integer values
	int arr[SIZE];
	int i, size;
	
	for (i = 0; i < SIZE ;i++){
		printf("Enter a value: ");
		scanf("%d", &arr[i]);
		
		// If -1 is entered, stop to get a value
		if (arr[i] == -1){
			arr[i] = 0;
			break;
		}
	}
	size = i;
	
	// Fill empty cells with 0.
	for (i++; i < SIZE; i++)
		arr[i] = 0;
	
	// Print out the array using element separators & Calculate the sum and average values
	int sum = 0;
	
	printf("ARRAY: ");
	for (i = 0; i < size; i++){
		if (i > 0)
			printf(" | ");
		printf("%d", arr[i]);
		
		sum += arr[i];
	}
	printf("\n\n");
	
	// Print out the sum and average values
	printf("Sum of the array: %d\n", sum);
	printf("Average of the array: %.2lf\n\n", sum / (double)size);
	
	// Find and print out the maximum and minimum values
	int max = arr[0],
		min = arr[0];
	
	for (i = 1; i < size; i++){
		if (arr[i] > max)
			max = arr[i];
		
		if (arr[i] < min)
			min = arr[i];
	}
	printf("Maximum: %d\nMinimum: %d\n\n", max, min);
	
	// Ask to search particular value and print out the order number. Give an error for -1 or not existed value
	int		value	= -1;
	bool	flag	= 0;	// If the value does not find flag = 0, else flag = 1
	
	while(flag == 0){
		printf("Which value you want to learn the order in the array: ");
		scanf("%d", &value);
		
		// Find and print out the order number of the value
		for (i = 0; i < size ; i++){
			if (value == arr[i]){
				printf("Value is existed on order #%d in the array.\n", i + 1);
				flag = 1;
				break;
			}
		}
		
		// Give an error if the value does not existed in the array & Get another input
		if (flag == 0)
			printf("Value does not exist. Try again!\n");
	}
	printf("\n");
	
	// Ask a value to remove particular value and remove the value. Give an error for -1 or not existed value.
	flag = 0;
	
	while(flag == 0){
		printf("Which value you want to remove from the array: ");
		scanf("%d", &value);
		
		// Find and print out the order number of the value
		for (i = 0; i < size ; i++){
			if (value == arr[i]){
				printf("%d is removed from the array.\n\n", value);
				arr[i] = arr[size - 1];
				size--;
				flag = 1;
				break;
			}
		}
		
		// Give an error if the value does not existed in the array & Get another input
		if (flag == 0)
			printf("Value does not exist. Try again!\n");
	}
	
	// Print out the final array using element separators.
	printf("ARRAY: ");
	for (i = 0; i < size; i++){
		if (i > 0)
			printf(" | ");
		printf("%d", arr[i]);
	}
	printf("\n\n");
	
	return 0;
}