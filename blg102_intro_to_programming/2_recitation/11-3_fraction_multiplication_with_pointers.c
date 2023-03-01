/*
	Write a program to represent a fraction
	1. Write a struct to represent a fraction
	2. Write the following functions
		- getFraction		// In this function user enters the elements of the Fraction to create one
		- multiplyFractions // Multiply two fractions (no not need to simplify)
		- printFraction
	3. Test your code in main
		- By printing the result of multiplication of two Fractions
	- Each Fraction is send to the functions with a pointer
	- Get the result fraction with another pointer
*/

#include <stdio.h>

typedef struct{
	int numerator;
	int denominator;
} Fraction;

// Get the members of the Fraction to create one structure
void get_fraction(Fraction* fraction){
	printf("Enter the numerator: ");
	scanf("%d", &(fraction->numerator));
	
	printf("Enter the denominator: ");
	scanf("%d", &(fraction->denominator));
}

// Print fraction multiplication
void print_fraction(Fraction* frac1, Fraction* frac2, Fraction* mul){
	printf("%7d %c %7d %c %7d\n", frac1->numerator, ' ', frac2->numerator, ' ', mul->numerator);
	printf("%s %c %s %c %s\n", "-------", 'X', "-------", '=', "-------");
	printf("%7d %c %7d %c %7d\n", frac1->denominator, ' ', frac2->denominator, ' ', mul->denominator);
}

// Multiply 2 fractions without simplification
void multiply_fractions(Fraction* frac1, Fraction* frac2, Fraction* mul){
	mul->numerator = frac1->numerator * frac2->numerator;
	mul->denominator = frac1->denominator * frac2->denominator;
}

// Multiply 2 fractions without simplification
int main(){
	Fraction frac1, frac2, mul;
	
	get_fraction(&frac1);
	get_fraction(&frac2);
	multiply_fractions(&frac1, &frac2, &mul);
	print_fraction(&frac1, &frac2, &mul);
	
	return 0;
}