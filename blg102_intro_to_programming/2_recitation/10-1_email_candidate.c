/*
	Write an email address suggestion program. 	Implement following functions:
		1. Function for suggestion (will be called from main)
		2. String functions (strlenght, strcopy, strconcatenate, substring, strreverse)
		3. Utility functions (swap,inttostring)
	+ This program suggests 3 candidate email addresses using name, surname & year (Feridun, Hurel, 1951)
		- Initial of name + surname + last 2 digits of year (fhurel51@itu.edu.tr)
		- First two from name + first two from surname + randomnumber(4 digit) (fehu8245@itu.edu.tr)
		- Surname + Name + Year (hurelferidun1951@itu.edu.tr)
	+ Remember to use pointers.
	+ Both return the result and write it into string using pass by reference
	+ Maximum character limit for both name and surname is 50
*/

#include <stdio.h>
#include <string.h>	// strncpy, strcat
#include <stdlib.h> // malloc, free, rand, srand
#include <time.h>	// time

#define MAX 51

void get_inputs(char* name, char* surname, int *year){
	// Get name
	printf("Enter your name: ");
	scanf("%s", name);

	// Get name
	printf("Enter your surname: ");
	scanf("%s", surname);

	// Get year
	printf("Enter your year: ");
	scanf("%d", year);
}

void str_clear(char* str, int lim){
	for (int i = 0; i < lim; i++)
		str[i] = '\0';
}

void int_to_str(int num, char* ch){
	int		i	= 0,
			lim = 0;
	char	tmp;
	
	// Convert int to char-array/string in reverse
	while (num != 0){
		ch[i] = (char)((num % 10)) + '0';
		num	/= 10;
		i++;
	}
	ch[i] = '\0';
	lim = i;

	// Reverse the string
	for(i = 0; i < lim / 2; i++){
		tmp = ch[i];
		ch[i] = ch[lim - i - 1];
		ch[lim - i - 1] = tmp;
	}
}

void email_suggest(char* name, char* surname, int *year){
	char* suggest = (char*)malloc(MAX * 2 * sizeof(char));
	char* str_num = (char*)malloc(MAX * sizeof(char));
	
	printf("\n3 different email suggestions are here for you:\n");	
	
	// 1: Initial of name + surname + last 2 digits of year
	strncpy(suggest, name, 1);										// Add initial of name
	strcat(suggest, surname);										// Add surname
	
	int_to_str(*year % 100,  str_num);								// Convert last 2 digits into a string
	strcat(suggest, str_num);										// Add last 2 digits of year 
	strcat(suggest, "@itu.edu.tr");
	
	printf("1: %s\n", suggest);
	str_clear(suggest, strlen(suggest));							// Clear the suggestion string
	str_clear(str_num, strlen(str_num));							// Clear the number string
	
	// 2: First two from name + first two from surname + randomnumber(4 digit)
	strncat(suggest, name, 2);										// Add first two from name
	strncat(suggest, surname, 2);									// Add first last from surname
	int_to_str(rand() % 8999 + 1000, str_num);						// Generate 4-digit random number & convert the integer into a string
	strcat(suggest, str_num);										// Add 4-digit random number
	strcat(suggest, "@itu.edu.tr");
	
	printf("2: %s\n", suggest);
	str_clear(suggest, strlen(suggest));
	str_clear(str_num, strlen(str_num));
	
	// 3: Surname + Name + Year
	strcat(suggest, surname);										// Add surname
	strcat(suggest, name);											// Add name
	int_to_str(*year, str_num);										// Convert year into a string
	strcat(suggest, str_num);										// Add year
	strcat(suggest, "@itu.edu.tr");
	
	printf("3: %s\n", suggest);
	
	// Free dynamic memories
	free(suggest);
	free(str_num);
}

int main(){
	char* name		= (char*)malloc(MAX * sizeof(char));
	char* surname	= (char*)malloc(MAX * sizeof(char));
	int year;
	
	// Get inputs
	get_inputs(name, surname, &year);
	
	// Generate email suggestions
	srand(time(NULL));
	email_suggest(name, surname, &year);
	
	// Free dynamic memories
	free(name);
	free(surname);
	
	return 0;
}