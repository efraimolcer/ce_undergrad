/*	
	Write a program to print the same shape below.
	* * *
	 * *
	* * *
*/

#include <stdio.h>

int main()
{
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 5; j++){
			if (i % 2 == 0 && j % 2 == 0)
				printf("*");
			else if (i % 2 == 0 && j % 2 == 1)
				printf(" ");
			else if (i % 2 == 1 && j % 2 == 0)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}

	return 0;
}