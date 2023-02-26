/*
	Write a program that inform for the taxi order for 30 days.
		1. Get the number of taxis in a taxi office.
		2. Print out taxi order for 30 days.
	+ There are N taxis in a taxi office.
	+ Each taxi has an numeric id that varies from 0 to N-1.
	+ To be fair, they use the following strategy:
		Taxis leave from office for costumers in a random order.
		In the following day, to be fair they leave from office in reverse order of previous day.
		This strategy continues with creating new random order every other day.
	+ Assume that user inputs are valid and no need to check.
	+ N value can be maximum 50
*/

#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <time.h>	// time

#define DAYS	 30
#define MAX_TAXI 100

void generate_order(int order[MAX_TAXI], int* N){
	for(int i = 0; i < *N; i++){
		order[i] = rand() % *N;
	}
}

void print_days(int order[MAX_TAXI], int *N, int* i){
	
	// Odd Day | Normal Order
	printf("Day %2d | ", *i * 2 + 1);
	for(int j = 0; j < *N; j++)
		printf("%2d | ", order[j]);
	printf("\n");
	
	// Even Day | Reverse Order
	printf("Day %2d | ", *i * 2 + 2);
	for(int j = 0; j < *N; j++)
		printf("%2d | ", order[*N - j - 1]);
	printf("\n");
}

int main(){
	// Get the number of taxis in a taxi office.
	int N, order[MAX_TAXI];
	printf("Enter the number of taxis in your taxi office: ");
	scanf("%d", &N);
	
	srand(time(NULL));
	
	for(int i = 0; i < DAYS / 2; i++){
		generate_order(order, &N);
		print_days(order, &N, &i);
	}
	
	return 0;
}