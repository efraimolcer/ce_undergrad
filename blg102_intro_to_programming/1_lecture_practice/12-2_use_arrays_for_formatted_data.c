/*	
	Write a C program that print out the given integer and double values
		1. Get an integer and two different double values from user
		2. Store these values into an array & print the array
		3. Read values in the array and print them one more
	+  Use sprintf and sscanf at least one time
	+ Character limit for a sentence is 100
*/

#include <stdio.h>	// sprintf, sscanf

#define LIM 100

int main(){
	char s[LIM];
	int x;
	double y, z;
	
	// 	Get input
	printf("Enter an integer: ");
	scanf("%d", &x);
	
	printf("Enter a double: ");
	scanf("%lf", &y);
	
	printf("Enter another double: ");
	scanf("%lf", &z);
	
	// Store values in an array & print the array
	sprintf(s, "These values are stored to an array:\nint: %d\ndouble I: %.2f\ndouble II: %.2f\n", x, y, z);
	printf("%s", s);
	
	// Read values in the array & print all values
	int x_read;
	double y_read, z_read;
	char s2[LIM];
	
	sscanf(s, "These values are stored to an array:\nint: %d\ndouble I: %lf\ndouble II: %lf\n", &x_read, &y_read, &z_read);
	printf("%d %.2f %.2f\n", x_read, y_read, z_read);
	
	return 0;
}