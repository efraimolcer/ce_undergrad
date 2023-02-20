/*	
	The program asks the user to enter the number of days and then converts that value to weeks and days.
	For example, if the user types "18", the program should print "18 days are 2 weeks, 4 days.",
			and	if the user types "35", the program should print "35 days are 5 weeks, 0 days."
	+ The maximum number of days the user enters is 10000.
	+ The user enters non-negative integers only.
*/

#include <stdio.h>	// printf, scanf
#include <stdlib.h>	// EXIT_SUCCESS

int main()
{
	int days, week, days_v2;
	printf("Enter the number of days: ");
	scanf("%d",&days);
	
	//Your solution starts here,
	week 	= days / 7;
	days_v2 = days % 7; 
	//Your solution ends here
	
	printf("%d days are %d weeks, %d days.\n", days, week, days_v2); //Fix me
	return EXIT_SUCCESS;
}

/*	CALICO
	python3 -m calico.cli question1.t
	init ..................................... PASSED
	build .................................... PASSED
	case_18 .................................. 1 / 1
	case_35 .................................. 1 / 1
	case_0 ................................... 1 / 1
	case_9999 ................................ 1 / 1
	Grade: 4 / 4
*/