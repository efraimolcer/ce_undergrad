/*	
	Assume that you have the following function that sorts a given array: "void sort(int x[], int x_size)"
	Using this 'sort function' and the 'equals function', write a function that checks whether two arrays have the same elements but not necessarily in the same order.
	+ equals function: bool equals(int a[], int a_size, int b[], int b_size)
*/

#include <stdio.h>
#include <stdbool.h>

void sort(int x[], int x_size){
	int tmp;
	for (int i = 0; i < x_size - 1; i++){
		for (int j = 0; j < x_size - i - 1; j++){
			if (x[j] > x[j + 1]){
				tmp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = tmp;
			}
		}
	}
}

bool equals(int a[], int a_size, int b[], int b_size){
	int*	lim;
	
	// Check for the size
	if (a_size < b_size)
		lim = &a_size;
	else
		lim = &b_size;
	
	// Check each elements one-by-one
	for(int i = 0; i < *lim; i++){
		if (a[i] != b[i])
			return 0;
	}
	
	return 1;
}

bool check(int a[], int a_size, int b[], int b_size){
	// Sort arrays as ordered
	sort(a, a_size);
	sort(b, b_size);

	// Check for equality
	return equals(a, a_size, b, b_size);
}

int main(){
	int a[] = {5, 7, 0, 1, 2},
		b[] = {1, 7, 2, 0, 5},
		a_size = 5,
		b_size = 5;
	
	printf("%d\n", check(a, a_size, b, b_size));
	return 0;
}