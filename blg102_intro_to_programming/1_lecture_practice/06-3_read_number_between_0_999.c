/*	
	Write a C program that prints out the reading of number based on given number.
		1. Ask for number.
		2. Print out the reading of the number.
	+ The number will be between 0 and 999. If user gives a bigger or smaller number from these array, print out an error message and ask again.
*/

#include <stdio.h>

void read_0_9(int num){
	// Print digit texts
	switch(num){
		case 0:
			printf("Zero");
			break;
		case 1:
			printf("One");
			break;
		case 2:
			printf("Two");
			break;
		case 3:
			printf("Three");
			break;
		case 4:
			printf("Four");
			break;
		case 5:
			printf("Five");
			break;
		case 6:
			printf("Six");
			break;
		case 7:
			printf("Seven");
			break;
		case 8:
			printf("Eight");
			break;
		case 9:
			printf("Nine");
			break;
	}
}

void read_10_19(int num){
	// Print digit texts
	switch (num){
		case 10:
			printf("Ten");
			break;
		case 11:
			printf("Eleven");
			break;
		case 12:
			printf("Twelve");
			break;
		case 13:
			printf("Thirteen");
			break;
		case 14:
			printf("Forteen");
			break;
		case 15:
			printf("Fifteen");
			break;
		case 16:
			printf("Sixteen");
			break;
		case 17:
			printf("Seventeen");
			break;
		case 18:
			printf("Eighteen");
			break;
		case 19:
			printf("Nineteen");
			break;
	}
}

void read_20_99(int num){
	// Print second digits first
	switch (num / 10){
		case 2:
			printf("Twen");
			break;
		case 3:
			printf("Thir");
			break;
		case 4:
			printf("For");
			break;
		case 5:
			printf("Fif");
			break;
		case 6:
			printf("Six");
			break;
		case 7:
			printf("Seven");
			break;
		case 8:
			printf("Eigh");
			break;
		case 9:
			printf("Nin");
			break;
	}
	printf("ty");

	// If first digits is not 0, print the digit text
	if (num % 10 != 0){
		printf(" ");
		read_0_9(num % 10);
	}
}

void read_100_999(int num){

	// Print third digit as a text directly
	read_0_9(num / 100);

	// Print singular or plural form of 'hundred'
	if (num / 100 == 1)
		printf(" Hundred");
	else
		printf(" Hundreds");
	
	// If first two digits are not 0, print the digit texts for these two digits
	if ((num % 100) != 0){
		printf(" ");
		// If second digit is 0, that means there is no tens digit
		if ((num % 100) / 10 == 0)
			read_0_9(num % 100);
		// If second digit is 1, that means these two digits between 10 to 19
		else if ((num % 100) / 10 == 1)
			read_10_19(num % 100);
		// If second digit is not 0 or 1, that means these two digits between 20 to 99
		else
			read_20_99(num % 100);
	}
}

int main(){
	// Get the number until the given number if valid
	int num = -1;
	while(num < 0 || num > 999){
		printf("Write a number: ");
		scanf("%d", &num);

		if (num < 0 || num > 999){
			printf("%d not between 0 and 999. Try again.\n", num);
		}
	}

	// Number texts are grouped by 4: 0-9, 10-19, 20-99, 100-999
	if (num >= 0 && num <= 9)
		read_0_9(num);
	else if (num >= 10 && num <= 19)
		read_10_19(num);
	else if (num >= 20 && num <= 99)
		read_20_99(num);
	else
		read_100_999(num);

	return 0;
}