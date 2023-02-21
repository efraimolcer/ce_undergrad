/*	
	Write a C program that given years later have how many balance totally starting with $10,000.
		1. Start with a year value of 0 and a balance of $10,000.
		2. While the balance equal to the given year, add 1 to the year value and compute the interest by multiplying the balance value by 0.05 (%5 interest). Lastly, add the interest to the balance.
		3. Report the each year and balance for current year.
*/

#include <stdio.h>

int main()
{
	float	salary = 0, sum = 0;
	int		ctr = 0;

	do{
		sum += salary;
		ctr++;
		
		printf("Enter a salary value: ");
		scanf("%f", &salary);
	} while(salary != -1);
	ctr--;
	
	if (ctr == 0){
		printf("No data\n");
	}
	else{
		printf("Average salary: %.2f\n", sum / ctr);
	}

	return 0;
}