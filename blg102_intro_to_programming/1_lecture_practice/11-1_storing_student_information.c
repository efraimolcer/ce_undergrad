/*	
	Write a C program that store student ID, student name, surname and student grade using struct.
		1. Write constant values for ID, name and grade.
		2. Get input from the user and store them in a struct.
		3. Print out given values using struct.
	+ Student ID is an integer, student name and surname are strings and student grade is a double.
	+ Reach the struct using both member operator and pointer operator.
	+ Character limit for both name and surname are 50.
*/

#include <stdio.h>

#define SIZE 50

struct student{
	int		id;
	char	name[SIZE];
	char	surname[SIZE];
	double	grade;
};

int main(){
	// Initialize the struct
	struct student class_a = {0, "NoName NoName", 0};
	struct student *std_ptr = &class_a;							// Pointer that points the structure tag name
	
	// Get input
	printf("\nEnter a student ID: ");
	scanf("%d", &class_a.id);
	
	printf("Enter a name: ");
	scanf("%s", class_a.name);
	
	printf("Enter a surname: ");
	scanf("%s", class_a.surname);
	
	printf("Enter the grade for student %s: ", class_a.name);
	scanf("%lf", &class_a.grade);
	
	// Print output
	printf("\nStudent ID: %d\nFull Name: %s %s\nGrade: %.2f\n", std_ptr->id, std_ptr->name, (*std_ptr).surname, (*std_ptr).grade);
	
	return 0;
}