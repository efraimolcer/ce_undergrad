/*	
	Write a program that maintains a bank’s account information, updating existing accounts, adding new accounts, deleting accounts and storing a listing of all the current accounts in a text file for printing.The program has five options.
		1. Option 1 calls function `textFile` to store a formatted list of all the accounts (typically called a report) in a text file called `accounts.txt` that may be printed later.
			The function uses `fread` and the sequential file access techniques used in the program.
		2. Option 2 calls the function `updateRecord` to update an account.
			The function will update only a record that already exists, so the function first checks whether the record specified by the user is empty.
			If the record contains no information, and a message is printed stating that the record is empty. Then the menu choices are displayed.
			If the record contains information, function `updateRecord` inputs the transaction amount, calculates the new balance and rewrites the record to the file.
		3. Option 3 calls the function `newRecord` to add a new account to the file.
			If the user "enter"s an account number for an existing account, newRecord displays an error message indicating that the record already contains information, and the menu choices are printed again.
		4. Option 4 calls function `deleteRecord` to delete a record from the file.
			Deletion is accomplished by asking the user for the account number and reinitializing the record.
			If the account contains no information, deleteRecord displays an error message indicating that the account does not exist.
		5. Option 5 terminates program execution.
	+ System capable of storing up to 100 fixed-length records.
	+ Character limit for a name is 20.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define SIZE 20
#define LIM 100

const char RANDOM_NAME[] = "12-7_random_file.txt";
const char TEXT_NAME[] = "12-7_text_file.txt";

typedef struct{
	int		account_num;
	char	first_name[SIZE];
	char	last_name[SIZE];
	double	balance;
} Client;

int select_option(){
	int opt;

	puts("\nOption 1: Save");
	puts("Option 2: Update");
	puts("Option 3: Add");
	puts("Option 4: Delete");
	puts("Option 5: Close");
	
	printf("Enter: ");
	scanf("%d", &opt);
	
	// If unknown option is entered, get an input again
	while (opt < 1 || opt > 5){
		puts("Option is not defined. Try again!");
		printf("Enter: ");
		scanf("%d", &opt);
	}
	
	return opt;
}

void random_file(Client* empty){
	FILE* file;
	
	// Check that file is opened or not
	if ((file = fopen(RANDOM_NAME, "wb")) == NULL)
		fprintf(stderr, "File could not be opened.");
	else{
		// Create random-access file that has 100 empty unit
		for(size_t i = 0; i < LIM; i++)
			fwrite(empty, sizeof(Client), 1, file);
	}
	fclose(file);
}

void text_file(FILE* file_random, Client* client){
	FILE* file_text;
	
	// Check that files are opened or not
	if((file_text = fopen(TEXT_NAME, "w")) == NULL)
			fprintf(stderr, "File could not be opened.");
	else{
		int check;
		// Scan all random-access file
		while(!feof(file_random)){
			// Read each line one-by-one in random-access file
			check = fread(client, sizeof(Client), 1, file_random);
			
			// If there is no record or account number is 0 (which is initialized value), skip that line
			if (check == 0 || client->account_num == 0)
				continue;
			
			// Save record in the random-access file into a text file
			fprintf(file_text, "%5d %15s %-10s %8.2f\n", client->account_num, client->first_name, client->last_name, client->balance);
		}
	}
	fclose(file_text);
}

void update_record(FILE* file, Client* client){
	int		check_num;
	double	amount;
	
	// Check that file is opened or not
	printf("Enter account number to update: ");
	scanf("%d", &check_num);
	
	// Find relevant position & check
	fseek(file, (check_num - 1) * sizeof(Client), SEEK_SET);
	
	fread(client, sizeof(Client), 1, file);
	if(client->account_num == 0)													// If the record does not exist, display error message
		printf("Account %d does not exist!\n", check_num);
	else{																		// If yes, rewrite the record as NULL, means delete
		// Check for transaction amount
		printf("Enter transaction amount: ");
		scanf("%lf", &amount);
		
		// Calculate the new balance
		fseek(file, (check_num - 1) * sizeof(Client), SEEK_SET);
		client->balance += amount;
		
		// Update the record
		fwrite(client, sizeof(Client), 1, file);
	}
}

void delete_record(FILE* file, Client* client, Client* empty){
	int		check_num;
	
	printf("Enter account number to delete: ");
	scanf("%d", &check_num);
	
	// Find relevant position & check
	fseek(file, (check_num - 1) * sizeof(Client), SEEK_SET);
	
	fread(client, sizeof(Client), 1, file);
	if(client->account_num == 0)													// If the record does not exist, display error message
		printf("Account %d already does not exist!\n", check_num);
	else{																		// If yes, rewrite the record as NULL, means delete
		fseek(file, (check_num - 1) * sizeof(Client), SEEK_SET);
		fwrite(empty, sizeof(Client), 1, file);
	}
}

void new_record(FILE* file, Client* client){
	Client	existing;
	
	// Get record details
	printf("Enter account number, first-name, last-name and balance: ");
	scanf("%d %s %s %lf", &(client->account_num), client->first_name, client->last_name, &(client->balance));
	
	fseek(file, (client->account_num - 1) * sizeof(Client), SEEK_SET);
	
	fread(&existing, sizeof(Client), 1, file);
	if (existing.account_num != 0)											// If the account number exists, display error message
		printf("Account %d already exists.\n", client->account_num);
	else{																	// If not, store given information into a random-access file
		fseek(file, (client->account_num - 1) * sizeof(Client), SEEK_SET);
		fwrite(client, sizeof(Client), 1, file);
	}
}

int main(){
	Client	client,
			empty = {0, "", "", 0.0};
	int	opt;
	
	// Run the statement below only once in the same folder
	// random_file(&empty);
	
	// Open the random-access file
	FILE*	file;
	if ((file = fopen(RANDOM_NAME, "rb+")) == NULL){
		fprintf(stderr, "File could not be opened.");
		return EXIT_FAILURE;
	}
	
	// Print the menu & relevant function
	opt = select_option();
	while (opt != 5){
		rewind(file);
		switch(opt){
			case 1:
				text_file(file, &client);
				break;
			case 2:
				update_record(file, &client);
				break;
			case 3:
				new_record(file, &client);
				break;
			case 4:
				delete_record(file, &client, &empty);
				break;
			case 5:
				puts("Program is terminated. Bye!");
				fclose(file);
				return EXIT_SUCCESS;
		}
		opt = select_option();
	}
	fclose(file);
	
	return EXIT_SUCCESS;
}