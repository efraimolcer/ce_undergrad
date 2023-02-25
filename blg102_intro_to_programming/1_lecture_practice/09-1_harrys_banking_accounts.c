/*	
	Write a program that will calculate the current bank deposits and withdrawals for more three bank accounts.
		1. Get each balance of bank accounts.
		2. Get withdrawal operations for different bank accounts.
		3. Print out current balance for the current bank account in each step.
	+ Use pointers.
*/

#include <stdio.h>
#include <stdlib.h> // exit()

/*
 * @func	Get balanca values for each banking accounts
 * @return	-
 * @param	*acc_a: Address of banking account A for balance
 * 			*acc_b: Address of banking account B for balance
 * 			*acc_c: Address of banking account C for balance
 */
void get_balance(double* acc_a, double* acc_b, double* acc_c){
	printf("Enter account balances for banking A, B & C: ");
	scanf("%lf %lf %lf", acc_a, acc_b, acc_c);
	
	double* tmp_ptr;
	while (*acc_a < 0 || *acc_b < 0 || *acc_c < 0){
		printf("\nIt is not possible to have a negative value in your account.\nRe-enter a account balance for banking ");
		
		if (*acc_a < 0){
			printf("A");
			tmp_ptr = acc_a;
		}
		if (*acc_b < 0){
			printf("B");
			tmp_ptr = acc_b;
		}
		if (*acc_c < 0){
			printf("C");
			tmp_ptr = acc_c;
		}
		
		printf(" (Min $0): ");
		scanf("%lf", acc_a);
	}
}

/*
 * @func	Select banking account to withdraw or terminate the program
 * @return	sel: Address of the banking account that want to withdraw
 * @param	-
 */
int select_account(){
	int sel = 0;
	
	do{
		printf("\n(1) Banking A\n(2) Banking B\n(3) Banking C\n(4) Terminate the Program\nEnter your banking account number to withdraw: ");
		scanf("%d", &sel);
		
		if (sel == 4){
			printf("Program is closed!\n\n");
			exit(1);
		}
		else if (sel < 1 || sel > 4){
			printf("Value is not existed. Try again!\n");
		}
	} while (sel < 1 || sel > 4);
	
	return sel;
}

/*
 * @func	Assign pointer to the address of selected account
 * @return	*acc_ptr: Pointer that points the address of selected account
 * @param	*sel: Address of the banking account that want to withdraw
 * 			*acc_a: Address of banking account A for balance
 * 			*acc_b: Address of banking account B for balance
 * 			*acc_c: Address of banking account C for balance
 */
double* ptr_assign(int* sel, double* acc_a, double* acc_b, double* acc_c){
	double* acc_ptr;
	
	if (*sel == 1)
		acc_ptr = acc_a;
	else if (*sel == 2)
		acc_ptr = acc_b;
	else if (*sel == 3)
		acc_ptr = acc_c;
	else
		acc_ptr = NULL;
	
	return acc_ptr;
}

/*
 * @func	Get withdraw value and complete the withrawal operation
 * @return	-
 * @param	*acc_ptr: Pointer that points the address of selected account
 * 			*sel: Address of the banking account that want to withdraw
 * 			*acc_a: Address of banking account A for balance
 * 			*acc_b: Address of banking account B for balance
 * 			*acc_c: Address of banking account C for balance
 */
void withdraw(double* acc_ptr, int* sel, double* acc_a, double* acc_b, double* acc_c){
	double amount = 0;
	
	printf("Enter the withdrawal amount ($): ");
	scanf("%lf", &amount);
	
	while (amount < 0 || amount > *acc_ptr){
		if (amount < 0)
			printf("Amount can not be negative value. Try again!\n");
		else if (amount > *acc_ptr)
			printf("Amount can not be greater than the account balance. Try again!\n");
		
		printf("Enter the withdrawal amount ($): ");
		scanf("%lf", &amount);
	}
	
	*acc_ptr -= amount;
}

int main(){
	double acc_a, acc_b, acc_c;
	double* acc_ptr;
	
	// Get account balances
	get_balance(&acc_a, &acc_b, &acc_c);
	
	// Continue the program except terminating is selected
	int sel = 0;
	while (sel != 4){
		// Select account that is want to withdrawal
		sel = select_account();
		
		// Assign related account to the pointer
		acc_ptr = ptr_assign(&sel, &acc_a, &acc_b, &acc_c);
		
		// Get withdrawal & withdraw the account
		withdraw(acc_ptr, &sel, &acc_a, &acc_b, &acc_c);
		
		printf("\nAccount A: %.2f\nAccount B: %.2f\nAccount C: %.2f\n\n", acc_a, acc_b, acc_c);
	}
	
	return 0;
}