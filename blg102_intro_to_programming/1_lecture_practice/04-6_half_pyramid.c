/*	
	Write a program to print half pyramid.
		1. Print the final shape.
	+ Use 4 rows & ‘*’ character.
*/

#include <stdio.h>

int main()
{
	for (int i = 0; i < 4; i++){
		for (int j = 0; j <= i; j++){
			printf("* ");
		}
		printf("\n");
	}

	return 0;
}