/*	
	Write a C program that how many years later have least $20,000 starting with $10,000 based on compound interest.
		1. Start with a year value of 0 and a balance of $10,000.
		2. While the balance is less than $20,000, add 1 to the year value and compute the interest by multiplying the balance value by 0.05 (%5 interest). Lastly, add the interest to the balance.
		3. Report the each year and balance for current year.
		4. Report the final year and balance values as the answer.
*/

#include <stdio.h>

int main()
{
	const double INTEREST_RATE	= 0.05;
	const double TARGET			= 20000;

	double balance	= 10000;
	int year		= 0;

	while (balance <= TARGET){
		balance += INTEREST_RATE * balance;
		year++;
		printf("%d. year | Current balance: %.2f\n", year, balance);
	}
	printf("Final year: %d \nFinal balance: %.2f\n", year, balance);

	return 0;
}