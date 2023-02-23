/*	
	Write a C function that gets the values, changes the values with some logic and prints out all values.
		1. Write a function that takes inputs from user.
		2. Write a function that multiplies current input with all previous inputs.
		3. Write a function that prints out all initialized and multiplied values at the same time with separator.
	+ Maximum count of getting input : 10
*/

#include <stdio.h>

#define SIZE 10

/*
 * @func	Fill an array with the input values.
 * @return	It returns the number of elements that were read.
 * @param	arr: Used array
 */
int read_inputs(int arr[]){
	int i;
	
	for (i = 0; i < SIZE; i++){
		printf("Enter a value: ");
		scanf("%d", &arr[i]);
		
		// If -1 is entered, stop to get a value
		if (arr[i] == -1)
			break;
	}
	
	return i;
}

/*
 * @func	Modify array values that it receives
 * @return	-
 * @param	arr: Used array
 * 			size: Used cell count in the array
 * 			num: Modification variable to factor all array values
 */
void multiply(int arr[], int size, int num){
	for (int i = 0; i < size; i++)
		arr[i] *= num;
}

/*
 * @func	Print array values
 * @return	-
 * @param	arr: Used array
 * 			size: Used cell count in the array
 */
void print(int arr[], int size){
	printf("\nARRAY: ");
	for (int i = 0; i < size; i++){
		if (i > 0)
			printf(" | ");
		printf("%d", arr[i]);
	}
	printf("\n\n");
}

int main(){
	int size,
		arr[SIZE];
	
	size = read_inputs(arr);
	
	multiply(arr, size, 3);
	print(arr, size);

	return 0;
}