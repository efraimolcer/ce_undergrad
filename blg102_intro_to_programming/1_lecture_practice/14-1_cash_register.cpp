#include "14-1_cash_register.h"

cash_register::cash_register(){
	total_amount = 0.0;
	item_count = 0;
}

cash_register::cash_register(int i, double d){
	total_amount = i;
	item_count = d;
}

void cash_register::clear(){
	total_amount = 0.0;
	item_count = 0;
}

void cash_register::add_price(double price){
	total_amount += price;
	item_count++;
}

double cash_register::get_total_amount() const {
	return total_amount;
}

int cash_register::get_item_count() const {
	return item_count;
}