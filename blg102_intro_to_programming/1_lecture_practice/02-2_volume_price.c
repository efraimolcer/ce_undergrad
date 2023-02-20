/*	
	Write a C program that calculates the price for each ounce of a pack.
		1. Calculate the price for each ounce of a pack.
		2. Print out the price for each ounce.
	+ One pack has 6 cans. (Constant)
	+ The price of a pack is 1998 dollar.
	+ Every can has 333 ounce volume.
*/

#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS

int main()
{
	const double CANS_PER_PACK = 6;
	double		pack_price = 1998.0;
	double		can_volume = 333.0;

	double		pack_volume = can_volume * CANS_PER_PACK;
	double		price_per_ounce = pack_price / pack_volume;

	printf("Price per ounce: %.2f\n", price_per_ounce);

	return EXIT_SUCCESS;
}