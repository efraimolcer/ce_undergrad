/*	
	Create a credit-processing system. Execute all steps seen below:
		1. Create an empty random-access file.
		2. Get necessary informations from users until the end.
		3. Print out given informations to file.
		4. Read informations from the file and print them to the terminal.
	+ System capable of storing up to 100 fixed-length records.
	+ Character limit for a name is 20.
	+ Each record should consist of an account number that will be used as the record key, a last name, a first name and a balance.
	+ The resulting program should be able to update an account, insert a new account record, delete an account and list all the account records in a formatted text file for printing.
	+ Use a random-access file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define SIZE	21
#define LIM		100

typedef struct{
	unsigned int	number;
	char			first_name[SIZE];
	char			last_name[SIZE];
	double			balance;
} Client;

int main(){
	FILE*	file;
	Client	client = {0, "", "", 0.0};
	const char FILENAME[] = "12-6_client_list.txt";
	
	// Open the file for writing in binary
	if ((file = fopen(FILENAME, "wb")) == NULL){
		fprintf(stderr, "File could not be opened!");
		return EXIT_FAILURE;
	}
	
	// Create an empty random-access file sequentially
	for (size_t i = 0; i < LIM; i++)
		fwrite(&client, sizeof(Client), 1, file);
	
	// Close the file
	fclose(file);
	
	// Open the file for updating (reading & writing) in binary
	if ((file = fopen(FILENAME, "rb+")) == NULL){
		fprintf(stderr, "File could not be opened!");
		return EXIT_FAILURE;
	}
	
	// Get account number
	printf("\nEnter 0 to terminate the program.\nAccount number must between 1 to 100.\nEnter account number: ");
	fscanf(stdin, "%d", &(client.number));
	
	// Get input from the user & save them into the file
	while (client.number != 0){
		// Get first-name, last-name & balance
		printf("Enter first-name: ");
		fscanf(stdin, "%s", client.first_name);
		
		printf("Enter last-name: ");
		fscanf(stdin, "%s", client.last_name);
		
		printf("Enter balance: ");
		fscanf(stdin, "%lf", &(client.balance));
		
		// Store given inputs into the random-access file
		fseek(file, (client.number - 1) * sizeof(Client), SEEK_SET);
		fwrite(&client, sizeof(Client), 1, file);
		
		// Get account number
		printf("\nEnter 0 to terminate the program.\nAccount number must between 1 to 100.\nEnter account number: ");
		fscanf(stdin, "%d", &(client.number));
	}
	
	// Close the file
	fclose(file);
	
	// Open the file for reading in binary
	if ((file = fopen(FILENAME, "rb")) == NULL){
		fprintf(stderr, "File could not be opened!");
		return EXIT_FAILURE;
	}
	
	// Read the file
	size_t check;
	while (!feof(file)){
		check = fread(&client, sizeof(Client), 1, file);
		
		// If readable size is 0 which means there is no readable element on the current file, skip
		// or account number is 0 which means there is no client added into the file, it still as initial, skip
		if (check == 0 || client.number == 0)
			continue;
		
		// Print the stored client information
		printf("%5d %10s %s %-5.2f\n", client.number, client.first_name, client.last_name, client.balance);
	}
	// Close the file
	fclose(file);
	
	return EXIT_SUCCESS;
}