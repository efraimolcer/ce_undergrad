/*	
	Write a C program to design a cash register using classes. Here is member functions:
		1. Clear the cash register to start a new sale
		2. Add the price of an item
		3. Get the total amount owed and the count of items purchased
	+ Define 2 different constructors
*/

#include <iostream>
#include <iomanip>
#include "14-1_cash_register.h"

using namespace std;

void display(cash_register reg){
	cout << "Total Count of Items: " << reg.get_item_count() << endl <<
	"Total Amount: $" << fixed << setprecision(2) << reg.get_total_amount() << endl << endl;
}

int main(){
	cash_register register1;
	
	register1.clear();
	display(register1);
	
	register1.add_price(12.984);
	display(register1);
	
	register1.add_price(0.021);
	display(register1);
	
	register1.add_price(1);
	display(register1);
	
	return 0;
}