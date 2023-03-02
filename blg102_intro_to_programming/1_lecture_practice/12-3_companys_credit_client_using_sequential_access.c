/*	
	Write a C program that store the company's credit client infos.
		1. Get necessary informations from users until the end.
		2. Print out given informations to file.
		3. Read informations from the file and print them to the terminal.
	+ For each client, the program obtains an ‘account number’, the ‘client’s name’ and the ‘client’s balance’ (i.e., the amount the client owes the company for goods and services received in the past).
	+ The data obtained for each client constitutes a “record” for that client.
	+ The account number is used as the record key in this application, the file will be created and maintained in account-number order.
	+ This program assumes the user enters the records in account-number order.
	+ In a comprehensive accounts receivable system, a sorting capability would be provided so the user could enter the records in any order.
	+ The records would then be sorted and written to the file.
	+ Character limit for a name & number limit for clients are 20.
*/

#include <stdio.h>	// FILE, puts, fgets, fprintf, fscanf, feof, fopen, fclose, exit
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE

#define SIZE 20

typedef struct{
	int		number;
	double	balance;
	char	name[SIZE];
} Client;

void get_input(Client* company){
	// Get client details:
	puts("Enter the account number: ");
	scanf("%d", &(company->number));
	
	if (!feof(stdin)){
		puts("Enter the client's name: ");
		scanf("%s", company->name);
	}
	
	if (!feof(stdin)){
		puts("Enter the client's balance: ");
		scanf("%lf", &(company->balance));
	}
	
	printf("\n");
}

void f_write(FILE* file, Client* company){
	// Open a file with write mode
	if ((file = fopen("12-3_client_list.txt", "w")) == NULL){
		fprintf(stderr, "File could not opened");
		exit(EXIT_FAILURE);
	}
	
	// Store the header
	fprintf(file, "%15s%20s%15s\n", "Account Number", "Client Name", "Balance");
	
	// Run until entering end-of-file key combination
	while (!feof(stdin)){
		// Get input by the user
		get_input(company);
		
		// Store given information into the file
		if(!feof(stdin))
			fprintf(file, "%15d%20s%15.2f\n", company->number, company->name, company->balance);
	}
	
	fclose(file);
}

void f_read(FILE* file, Client* company){
	// Open a file with read mode
	if ((file = fopen("12-3_client_list.txt", "r")) == NULL){
		fprintf(stderr, "File could not opened");
		exit(EXIT_FAILURE);
	}
	
	// Print the header
	char header[SIZE * 3];
	fgets(header, SIZE * 3, file);
	printf("%s", header);
	
	// Run until end-of-file
	while(!feof(file)){
		// Read information from the file
		fscanf(file, "%d%s%lf", &(company->number), company->name, &(company->balance));
		
		// Print information
		if(!feof(file))
			printf("%15d%20s%15.2f\n", company->number, company->name, company->balance);
	}
	
	fclose(file);
}

int main(){
	Client	company;
	FILE*	file;
	
	f_write(file, &company);
	f_read(file, &company);
	
	return EXIT_SUCCESS;
}