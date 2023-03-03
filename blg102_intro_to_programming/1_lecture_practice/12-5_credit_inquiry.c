/*	
	Write a C program that allows a credit manager to obtain lists of customers.
		1. Display a menu and allows the credit manager to enter one of three options to obtain credit information
		2. Print out related customer list
	+ Menu options:
		* Option 1 produces a list of accounts with zero balances. (i.e., customers who do not owe any money)
		* Option 2 produces a list of accounts with credit balances. (i.e., customers to whom the company owes money)
		* Option 3 produces a list of accounts with debit balances. (i.e., customers who owe the company money for goods and services received)
		* Option 4 terminates program execution.
	+ A credit balance is a negative amount; a debit balance is a positive amount.
	+ Character limit for a name & number limit for clients are 20.
	+ Use client list created at 12-3_client_list.txt
*/

#include <stdio.h>	// fopen, stderr, fprintf, fscanf
#include <stdlib.h>	// EXIT_SUCCESS, EXIT_FAILURE
#include <stdbool.h>

#define SIZE	20
#define LIM		3

typedef struct{
	int		number;
	double	balance;
	char	name[SIZE];
} Client;

int main(){
	FILE*	file;
	Client	list;
	
	int opt;
	char*	options[LIM + 1] =	{"Option 1: Zero Balance\n", 
								"Option 2: Credit Balance\n",
								"Option 3: Debit Balance\n",
								"Option 4: Terminate the Program\n"};
	
	// Open the file.
	if ((file = fopen("12-3_client_list.txt", "r")) == NULL){
		fprintf(stderr, "File could not opened!");
		return EXIT_FAILURE;
	}
	
	// Run until terminating or selection error
	while(1){	
		// Print the menu & get an option
		fprintf(stdout, "%s%s%s%s", options[0], options[1], options[2], options[3]);
		printf("Enter the option number: ");
		scanf("%d", &opt);
		
		// Check for terminating or selection error
		if (opt <= 0 || opt >= 4){
			if (opt == 4)
				fprintf(stdout, "\nProgram is terminated.");
			else
				fprintf(stderr, "\nNo option selected. Program is terminated");
			
			return EXIT_FAILURE;
		}
		
		// Print the selected option
		printf("\n%s", options[opt - 1]);
		
		// Print the header
		char header[SIZE * 3];
		fgets(header, SIZE * 3, file);
		printf("%s", header);
		
		// Scan the file
		while (!feof(file)){
			fscanf(file, "%d%s%lf", &(list.number), list.name, &(list.balance));
			
			// Select based on option & balance status
			if (feof(file))
				break;
			else if ((opt == 1 && list.balance == 0)	||			// Option 1
					(opt == 2 && list.balance < 0)  	|| 			// Option 2
					(opt == 3 && list.balance > 0))					// Option 3
				printf("%15d%20s%15.2f\n", list.number, list.name, list.balance);
		}
		printf("\n");
		
		rewind(file);
	}
	
	return 0;
}