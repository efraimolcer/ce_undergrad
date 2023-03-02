/*	
	Write a C program that execute each step below.
		1. Print all person's name and age to prompt
		2. Ask the name &age to user
		3. Append new element to the file and print all elements
	+ Character limit for a name is 20.
*/

#include <stdio.h>	// FILE, fopen, fclose, fprintf, fscanf, stderr, feof

#define SIZE 20

typedef struct{
	char	name[SIZE];
	int		age;
} User;

int main(){
	User	user_list;
	FILE*	file;
	
	// Open the file to read
	if ((file = fopen("12-4_people.txt", "r")) == NULL){
		fprintf(stderr, "%s\n", "File could not opened!");
		return 1;
	}
	
	// Print the file
	while (!feof(file)){
		fscanf(file, "%s %d", user_list.name, &(user_list.age));
		printf("%s %d\n", user_list.name, user_list.age);
	}
	fclose(file);
	
	// Get input
	printf("\nEnter your name: ");
	scanf("%s", user_list.name);
	
	printf("Enter your age: ");
	scanf("%d", &(user_list.age));
	printf("\n");
	
	// Append new name & age
	file = fopen("12-4_people.txt", "a");
	fprintf(file, "\n%s %d", user_list.name, user_list.age);
	fclose(file);
	
	// Print the appended file
	file = fopen("12-4_people.txt", "r");
	while (!feof(file)){
		fscanf(file, "%s %d", user_list.name, &(user_list.age));
		printf("%s %d\n", user_list.name, user_list.age);
	}
	fclose(file);
	
	return 0;
}