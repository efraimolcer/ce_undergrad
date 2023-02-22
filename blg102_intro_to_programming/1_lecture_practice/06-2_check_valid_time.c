/*	
	Write a C program that take only valid hours and minutes.
		1. Ask for minutes and hours as different inputs.
		2. Check the values valid or invalid.
		3. Print out the "Congratulation" if user gives the true values for both hour and minute.
	+ Hours can be between 0-23, minutes can be between 0-59.
	+ If user will give invalid hour or minute, don't print out any error, just print out scanf point again.
	+ If user will give valid hour and minute, print out "Congratulation"
*/

#include <stdio.h>
#include <stdbool.h>

/*
 * @func	Checks that the input is valid or not and gets input until the valid ones are entered.
 * @return	The valid input
 * @param	min: minimum value that can be entered
 * 			max: maximum value that can be entered
 * 			type: type of the entered value | 0 is hour, 1 is minute
 */
int get_valid(int min, int max, bool type){
	int input;
	do{
		printf("Enter a value between %d and %d for ", min, max);
		switch(type){
			case 0:
				printf("hour: ");
				break;
			case 1:
				printf("minute: ");
				break;
		}
		scanf("%d", &input);
	}while (input < min || input > max);

	return input;
}

int main(){
	get_valid(0, 23, 0);
	get_valid(0, 59, 1);

	printf("Congratulation\n");

	return 0;
}