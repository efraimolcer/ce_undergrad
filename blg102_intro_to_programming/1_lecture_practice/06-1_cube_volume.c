/*	
	Write a C program that calculate the volume of the cube based on the given length.
		1. Ask for length.
		2. Calculate the volume with using different function.
		3. Print out the volume.
*/

#include <stdio.h>
#include <math.h>	// pow

double cube_volume(double len){
	return pow(len, 3);
}

int main(){
	double len, vol;

	printf("Write the length: ");
	scanf("%lf", &len);

	vol = cube_volume(len);
	printf("The volume is equal to %.2f", vol);

	return 0;
}