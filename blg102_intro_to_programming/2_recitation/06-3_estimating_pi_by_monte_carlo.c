/*	
	Write a C program that uses following funtions to estimate the value of π using Monte Carlo Method
		1. double getRandomNumber(double lower_limit, double upper_limit)
			Returns a pseudo random real number between the lower_limit and upper_limit
		2. double calculatePi(int max_iteration)
			Returns estimated value of π using max_iteration random points
	+ Unit circle fits inside square with edge length 2.
	+ Ratio of random points inside the unit circle over random points inside the square can be used to estimate the value of π.
	+ Area of square / Area of circle  = 4r^2 / πr^2. => ratio of area of circle to area of square = π/4
	+ Total number of hits inside circle / Total number of throws = M/N => π/4 ~ M/N => π ~ 4*M/N
*/

#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <time.h>	// time
#include <limits.h> // RAND_MAX
#include <math.h>	// pow

/*
 * @func	Generate a random double number
 * @return	A pseudo random real number between the lower_limit and upper_limit
 * @param	lower_limit: lower bound of the random number interval
 * 			upper_limit: upper bound of the random number interval
 */
double getRandomNumber(double lower_limit, double upper_limit){
	// rand / RAND_MAX [0, 1];
	return ((upper_limit - lower_limit) * ((double)rand() / RAND_MAX)) + lower_limit;
}

/*
 * @func	Calculate estimated pi value using Monte Carlo Method
 * @return	Estimated value of π using max_iteration random points
 * @param	max_iteration: total number of throws
 */
double calculatePi(int max_iteration){
	double x, y, estimated_pi;
	int inside = 0;

	// Throw as max_iteration
	for (int i = 0; i < max_iteration; i++){
		// Get random x and y values.
		x = getRandomNumber(-1, 1);
		y = getRandomNumber(-1, 1);
		
		// If the hypotenuse is equal to or smaller than 1, it means throw is inside the circle.
		if (pow(x, 2) + pow(y, 2) <= 1)
			inside++;
	}
	
	// Calculate π using Monte Carlo Method
	return 4 * (double)inside / max_iteration;
}

int main(){
	srand(time(NULL));
	
	double estimated_pi;
	estimated_pi = calculatePi(1000000);
	
	printf("%lf\n", estimated_pi);
	
	return 0;
}