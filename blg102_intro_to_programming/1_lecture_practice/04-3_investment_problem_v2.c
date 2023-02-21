/*	
	Write a C program that given years later have how many balance totally starting with $10,000.
		1. Start with a year value of 0 and a balance of $10,000.
		2. While the balance equal to the given year, add 1 to the year value and compute the interest by multiplying the balance value by 0.05 (%5 interest). Lastly, add the interest to the balance.
		3. Report the each year and balance for current year.
*/

#include <stdio.h>

int main()
{
	const double INTEREST_RATE	= 0.05;

	double balance	= 10000;
	int lim;

	printf("Enter the number of years: ");
	scanf("%d", &lim);

	for (int i = 1; i <= lim; i++){
		balance += INTEREST_RATE * balance;
		printf("%d. year | Current balance: %.2f\n", i, balance);
	}

	return 0;
}