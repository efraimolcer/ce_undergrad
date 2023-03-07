/*	
	Write a C program that calculate the volume of cube with using 3 different files.
		1. Create a ‘main.c’ file for the main function
		2. Create a ‘cube.h’ file to point the ‘cube_volume’ function in ‘cube.c’ file
		3. Create a ‘cube.c' file to calculate a volume using ‘cube_volume’ function
		4. Create Makefile
*/

#include <stdio.h>
#include "13-4_cube.h"

int main(){
	unsigned int	len,
					vol;
	
	printf("Enter a length: ");
	scanf("%u", &len);
	
	vol = cube_volume(len);
	printf("Volume of the cube: %d\n", vol);
	
	return 0;
}