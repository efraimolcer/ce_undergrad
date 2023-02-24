/*
	Write a program that has a bubble sort function that
		1. Gets any int array
		2. Gets sorting type (ascending, descending)
		3. Sorts the array using bubble sort
*/

#include <stdio.h>
#define SIZE 100

/*
 * @func	Get array numbers
 * @return	size: Entered size (capacity) of the array
 * @param	arr: Array to store entered values
 */
int get_input(int arr[]){
	// Get an array size
	int size;
	printf("How many values you want to enter: ");
	scanf("%d", &size);
	
	// Get values
	for (int i = 0; i < size; i++){
		printf("Enter %d. value: ", i + 1);
		scanf("%d", &arr[i]);
	}
	
	return size;
}

/*
 * @func	Sort the array in ascending or descending order using bubble sort
 * @return	-
 * @param	arr: Array to store entered values
 * 			size: Entered size of the array
 * 			sort_type: Requested sort type to sort the array | 1: Ascending, 2: Descending
 */
void sort_bubble(int arr[], int size, int sort_type){
	int tmp;
	
	for (int i = 0; i < size - 1; i++){
		// Sort the array
		for (int j = 0; j < size - i - 1; j++){
			if ((sort_type == 1 && arr[j] > arr[j + 1]) ||	// Ascending order
				(sort_type == 2 && arr[j] < arr[j + 1])){	// Descending order
				tmp			= arr[j];
				arr[j]		= arr[j + 1];
				arr[j + 1]	= tmp;
			}
		}
	}
}

/*
 * @func	Print the array
 * @return	-
 * @param	arr: Array to store entered values
 * 			size: Entered size of the array
 */
void print(int arr[], int size){
	for (int i = 0; i < size; i++){
		if (i != 0)
			printf(" | ");
		printf("%d", arr[i]);
	}
	printf("\n\n");
}

int main(){
	int arr[SIZE],
		size,
		sort_type;
	
	// Get an array
	size = get_input(arr);
	print(arr, size);
	
	// Get sorting type
	do{
		printf("\n(1) Ascending\n(2) Descending\nEnter sorting type: ");
		scanf("%d", &sort_type);
	} while (sort_type != 1 && sort_type != 2);
	
	// Sort the array using bubble sort
	sort_bubble(arr, size, sort_type);
	
	// Print the sorted array
	print(arr, size);
	
	return 0;
}