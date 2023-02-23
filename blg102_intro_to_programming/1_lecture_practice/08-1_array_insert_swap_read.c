/*	
	Write a program that will do the all steps below.
		1. Ask for array values
		2. Print out all array values with using element separators
		3. Ask value and position to insert. Add the value in the given position and print out the array
		4. Ask two position number to swap 2 numbers and print out the array
		5. Get new values, add them at the end of the array and print out the array
	+ Get 10 input to array.
	+ If user do not full the array, write 0 to all empty values.
	+ If -1 is written, finish to get a value.
*/

#include <stdio.h>
#define SIZE 100

void print_arr(int arr[], int size){
	// Print out the array using element separators
	printf("\nARRAY: ");
	for (int i = 0; i < size; i++){
		if (i > 0)
			printf(" | ");
		printf("%d", arr[i]);
	}
	printf("\n\n");
}

int main(){
	// Get 10 integer values
	int arr[SIZE];
	int i, size;
	
	for (i = 0; i < 10; i++){
		printf("Enter a value: ");
		scanf("%d", &arr[i]);
		
		// If -1 is entered, stop to get a value
		if (arr[i] == -1){
			arr[i] = 0;
			break;
		}
	}
	size = i;
	
	print_arr(arr, size);
	
	{
		// INSERT OPERATION
		printf("INSERT\n");
		
		// Ask value and position to insert
		int value, pos;
		
		printf("Enter the value you want to insert: ");
		scanf("%d", &value);
		
		printf("Which position you want to add the value on: ");
		scanf("%d", &pos);
		
		// Move all elements above the insertion location to a higher index
		for (int i = size; i >= pos; i--)		
			arr[i] = arr[i - 1];
		size++;
		
		// Add the value in the given position
		arr[pos - 1] = value;
		
		print_arr(arr, size);
	}
	
	{
		// SWAP OPERATION
		printf("SWAP\n");
		
		// Ask two position numbers to swap
		int pos1, pos2, tmp;
		printf("Enter two position number: ");
		scanf("%d %d", &pos1, &pos2);
		
		// Swap 2 numbers
		tmp				= arr[pos1 - 1];
		arr[pos1 - 1]	= arr[pos2 - 1];
		arr[pos2 - 1]	= tmp;
		
		print_arr(arr, size);
	}
	
	{
		// READ OPERATION
		printf("CONTINUE TO READ\n");
		for (i = size; i < SIZE; i++){
			printf("Enter a value: ");
			scanf("%d", &arr[i]);
			
			// If -1 is entered, stop to get a value
			if (arr[i] == -1){
				arr[i] = 0;
				break;
			}
		}
		size = i;
		
		print_arr(arr, size);
	}
	
	return 0;
}