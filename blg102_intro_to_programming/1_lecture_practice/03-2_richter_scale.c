/*	
	Write a C program that gives different expectations based on magnitudes of earthquakes.
		1. Ask for a magnitude of earthquake.
		2. Choose the right expectation based on a magnitude of earthquake.
		3. Print out the related expectation.
	+ Users can write what they want, there is no limitation.
	+ Richer Scale (Value: Effect)
		4.5: Damage to poorly constructed buildings
		6: Many buildings considerably damaged and some collapse
		7: Many buildings destroyed
		8: Most structures fall
*/

#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS

int main()
{
	float magnitude = 0.0;
	
	printf("What is the magnitude of earthquake: ");
	scanf("%f", &magnitude);

	if (magnitude >= 8){
		printf("The %.2f magnitude earthquake causes to most structures fall.\n", magnitude);
	}
	else if (magnitude >= 7){
		printf("The %.2f magnitude earthquake causes to many building destroyed.\n", magnitude);
	}
	else if (magnitude >= 6){
		printf("The %.2f magnitude earthquake causes to many buildings considerably damaged and some collapse.\n", magnitude);
	}
	else if (magnitude >= 4.5){
		printf("The %.2f magnitude earthquake causes to damage to poorly constructed buildings.\n", magnitude);
	}
	else{
		printf("The %.2f magnitude earthquake causes to no destruction.\n", magnitude);
	}

	return EXIT_SUCCESS;
}