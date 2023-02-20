/*	
	Write a C program that calculates the yearly taxes based on different situations in the USA.
		1. Ask for a taxable income and marriage status.
		2. Calculate the fit tax amount depending to the taken data.
		3. Print out the fit tax amount.
	+ Users can write only positive numbers for taxable income and only 'single or married for marriage status.
	+ If marriage status is single and the taxable income is at most $32.000, the tax equals to %10 of taxable income.
	+ If marriage status is single and the taxable income is over $32.000, the tax equals to 3.200 and %25 of the amount over 32.000.
	+ If marriage status is married and the taxable income is at most $64.000, the tax equals to %10 of taxable income.
	+ If marriage status is married and the taxable income is over $64.000, the tax equals to 6.400 and %25 of the amount over 64.000.
*/

#include <stdio.h>

int main()
{
	double taxable_income, tax;
	int marriage_status;

	const double LIM_SINGLE = 32000;
	const double LIM_MARRY = 64000;

	printf("Write your taxable income ($): ");
	scanf("%lf", &taxable_income);

	printf("1 for married\n0 for single\nWrite your marriage status: ");
	scanf("%d", &marriage_status);

	if (marriage_status == 1){	
		if (taxable_income < LIM_MARRY){
			tax = taxable_income * 0.1;
		}
		else{
			tax = LIM_MARRY * 0.1 + (taxable_income - LIM_MARRY) * 0.25;
		}
	}
	else
	{
		if (taxable_income < LIM_SINGLE){
			tax = taxable_income * 0.1;
		}
		else{
			tax = LIM_SINGLE * 0.1 + (taxable_income - LIM_SINGLE) * 0.25;
		}
	}

	printf("Total Tax: %.2f!\n", tax);

	return 0;
}