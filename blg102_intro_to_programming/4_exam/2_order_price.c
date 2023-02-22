/*	
	The following pseudocode describes how a bookstore computes the price of an order from the total price and the number of the books that were ordered.
		Read the total book price and the number of books.
		Compute the tax (7.5% of the total book price).
		Compute the shipping charge ($2 per book).
		The price of the order is the sum of the total book price, the tax, and the shipping charge. Print the price of the order.
	Translate this pseudocode into a C program.
*/

#include <stdio.h>

int main(){
	int total_price, book_num;
	
	// Get the total book price and the number of books
	printf("Enter the total book price: ");
	scanf("%d", &total_price);
	
	printf("Enter the number of books: ");
	scanf("%d", &book_num);
	
	// Calculate the tax, the shipping charge, and the price of the order
	double tax, shipping, order_price;
	tax			= total_price * 7.5 / 100;
	shipping	= book_num * 2;
	order_price = total_price + tax + shipping;
	
	printf("Order price is %.2lf\n", order_price);
	
	return 0;
}