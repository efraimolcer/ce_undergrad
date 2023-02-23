/*	
	Write a C program that switch left-half values with right-half values.
		1. Get array capacity and values from user
		2. Switch left-half values with right-half values
		3. Print out both initial and switched arrays
		+ Array capacity is 10.
*/

#include <stdio.h>
#define SIZE 10

int main(){
	int arr[SIZE],
		size, diff, tmp;
	
	// Get the array size
	do{
		printf("Enter the array size: ");
		scanf("%d", &size);
	} while (size < 0 || size > 10);
	
	// Get the array values
	for (int i = 0; i < size; i++){
		printf("Enter the value: ");
		scanf("%d", &arr[i]);
	}

	// Print out the initial array
	printf("INITIAL ARRAY\n");
	for (int i = 0; i < size; i++){
		if (i > 0)
			printf(" | ");
		printf("%d", arr[i]);
	}
	printf("\n\n");
	
	// Switch left-half values with right-half values
	if (size % 2 == 1)
		diff = size/2 + 1;
	else
		diff = size/2;

	for (int i = 0; i < size / 2; i++){
		tmp				= arr[i];
		arr[i]			= arr[i + diff];
		arr[i + diff]	= tmp;
	}
	
	// Print out the switched array
	printf("SWITCHED ARRAY\n");
	for (int i = 0; i < size; i++){
		if (i > 0)
			printf(" | ");
		printf("%d", arr[i]);
	}
	printf("\n\n");
	
	return 0;
}