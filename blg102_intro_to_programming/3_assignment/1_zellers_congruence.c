//////////////////////////
// Name: Efraim Olcer   //
// SID:  150190713	    //
// Mail: olcer16		//
//////////////////////////

#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE

int main()
{

	// Get a date
	int year, m, q;

	printf("Enter date [year month day]: ");
	scanf("%d %d %d", &year, &m, &q);

	// Check whether the date is valid:
	if (q <= 0 || m <= 0 || m > 12 || year < 0 ||													// Negative year, non-positive day & month, +12 month
		(m == 2 && q > 28) ||																		// +29 Days
		((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && q > 31) || 		// +31 Days
		((m == 2 || m == 4 || m == 6 || m == 9 || m == 11) && q > 30)){								// +30 Days
		
		printf("Invalid date.\n");
		return EXIT_FAILURE;
	}

	// Get an end year
	int end_year;

	printf("Enter end year: ");
	scanf("%d", &end_year);

	// Determine the day of the week using Zeller's Congruence
	int day, j, k, y;

	y = year;
	if (m == 1 || m == 2){
		m += 12;
		y -= 1;
	}
	j = y / 100;
	k = y % 100;

	day = (q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

	// Print the day of the week
	printf("It's a ");
	switch(day){
		case 0:
			printf("Saturday");
			break;
		case 1:
			printf("Sunday");
			break;
		case 2:
			printf("Monday");
			break;
		case 3:
			printf("Tuesday");
			break;
		case 4:
			printf("Wednesday");
			break;
		case 5:
			printf("Thursday");
			break;
		case 6:
			printf("Friday");
			break;
	}
	printf(".\n");

	// For the remaining years, count how many of the sameday-and-month fall on the same weekday and print the result.
	int tmp_day, ctr = 0;
	
	year++;
	for (int i = year; i <= end_year; i++){
		j = i / 100;
		k = i % 100;
		tmp_day = (q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

		if (day == tmp_day)
			ctr++;
	}
	printf("Same day-and-month on same weekday between %d and %d: %d\n", year, end_year, ctr);

	return EXIT_SUCCESS;
}

/*	CALICO
	python3 -m calico.cli assignment1.t
	init ..................................... PASSED
	build .................................... PASSED
	case0_1900_1_1_1999 ...................... 6 / 6
	case0_invalid_11_31 ...................... 2 / 2
	case1_1868_11_13_2018 .................... 6 / 6
	case1_1582_2_24_2018 ..................... 6 / 6
	case1_330_5_11_1453 ...................... 6 / 6
	case1_1444_11_10_1921 .................... 6 / 6
	case1_722_1_2_1492 ....................... 6 / 6
	case2_invalid_2_30 ....................... 2 / 2
	case2_invalid_4_31 ....................... 2 / 2
	case2_invalid_6_31 ....................... 2 / 2
	case2_invalid_9_31 ....................... 2 / 2
	case2_invalid_11_31 ...................... 2 / 2
	case2_invalid_negative_1 ................. 2 / 2
	case2_invalid_negative_2 ................. 2 / 2
	case2_invalid_negative_3 ................. 2 / 2
	case2_invalid_other ...................... 2 / 2
	case2_invalid_other2 ..................... 2 / 2
	case3_0_1_1_2018 ......................... 6 / 6
	case3_1993_3_10_2018 ..................... 6 / 6
	case3_1993_3_10_2021 ..................... 6 / 6
	case3_1999_8_17_2070 ..................... 6 / 6
	case3_1546_7_4_5000 ...................... 6 / 6
	case3_1526_8_28_3000 ..................... 6 / 6
	case3_200_12_31_2000 ..................... 6 / 6
	Grade: 100 / 100
*/