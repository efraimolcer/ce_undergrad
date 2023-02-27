/*	
	1. Write a function rotate_right
		It takes two strings (dst and src), and an integer (n) as parameters.
		It rotates src right by n characters as described and stores the result in dst.
	2. Write the function main that will get a string to rotate and the rotation amount from the user
		Call the rotate_right function to do the rotation operation and prints the result.
	+ Write a program that will rotate a string to the right.
		In this operation, all characters are moved one position to the right and the last character becomes the first character of the result.
	+ For example,
		If you rotate the string "hello" 1 character to the right, you get the string "ohell".
		If you rotate "hello" 3 characters to the right, you get "llohe".
	+ You can assume that n is a non-negative integer, you don't have to check its value.
	+ You can assume that the user will type a string without spaces and a non-negative integer.
*/

#include <stdio.h>

#define MAX 1000

void rotate_right(char* dst, char* src, int n){
	int	i = 0,
		len = 0;
		
	// Find a length of the source string
	while(src[i] != '\0'){
		len++;
		i++;
	}
	
	//  Rotate the source into destination based on n value
	for(i = 0; i < len; i++)
		dst[(i + n) % len] = src[i];
	dst[i] = '\0';
}

int main(){
	unsigned int	n;
	char			src[MAX],
					dst[MAX];
	
	// Get the string & n value from the user
	printf("Get a string to rotate: ");
	scanf("%s", src);
	
	printf("Get a rotation amount: ");
	scanf("%d", &n);
	
	rotate_right(dst, src, n);
	printf("%s\n", dst);
	
	return 0;
}