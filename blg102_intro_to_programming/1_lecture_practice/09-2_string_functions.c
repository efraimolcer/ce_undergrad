/*	
	Write a program that execute these steps:
		1. Get the first-name and last-name from the user
		2. Print out the full-name using only a string
		3. Calculate the length of the full-name and print out
		4. Ask for changing the name
		5. Change the name and print out new full-name with old one as Step 3
		6. Print out the shorten version as ‘first letter of name and surname’
		7. Inform the user as lexicographic order relationship between name and surname
	+ Maximum length for name or surname is 20
*/

#include <stdio.h>
#include <string.h>	//strlen, strcat, strncat, strcpy, strcmp

#define MAX 40

int main(){
	char full_name[MAX], last_name[MAX / 2];
	
	// Get first-name and last-name
	printf("Enter your first-name: ");
	scanf("%s", full_name);
	
	printf("Enter your last-name: ");
	scanf("%s", last_name);
	
	// Create full-name
	strcat(full_name, " ");
	strcat(full_name, last_name);
	printf("%s\n", full_name);
	
	// Calculate the length of full-name
	printf("Length: %lu\n\n", strlen(full_name) - 1);
	
	// Get the new name
	char new_first_name[MAX / 2];
	char new_full_name[MAX];

	printf("Enter your new first-name: ");
	scanf("%s", new_first_name);
	
	// Create new full-name
	strcpy(new_full_name, new_first_name);
	strcat(new_full_name, " ");
	strcat(new_full_name, last_name);
	printf("%s\n", new_full_name);
	
	// Calculate the length of new full-name
	printf("Length: %lu\n\n", strlen(new_full_name) - 1);
	
	// Print out the shorten version of new full-name
	char short_full_name[MAX];
	
	strncat(short_full_name, new_first_name, 1);
	strcat(short_full_name, ". ");
	strcat(short_full_name, last_name);
	printf("Shorten Version: %s\n\n", short_full_name);
	
	// Inform the user as lexicographic order relationship between name and surname
	int check;
	check = strcmp(new_first_name, last_name);
	
	if (check == 0)
		printf("Your first-name and last-name are same!\n");
	else if (check < 0)
		printf("Your new first-name comes before than your last-name in lexicographic order.\n");
	else
		printf("Your new first-name comes after than your last-name in lexicographic order.\n");
	
	return 0;
}