/*	
	Write a function void append(char* a, char* b) that takes two strings and appends the characters in b into a by putting a blank character in between the two.
		+ The string a can store at most 20 characters.
		+ If the function is called with the two strings (a, b), but there is not enough space left in the first string (a), function should print "Error" to the console and terminates.
		+ If there is enough space in a, function appends the string b into a, and prints the string a to the console.
*/

#include <stdio.h>
//You cannot use the string library 

#define MAX_STRING_SIZE 20

void append(char* a, char* b)
{
	//fill the function body. Do not change the arguments and the return parameter
	int	len_a = 0,
		len_b = 0;
	
	// Get a length of both strings
	while(a[len_a] != '\0')
		len_a++;
	
	while(b[len_b] != '\0')
		len_b++;
	
	// Check that there exist
	if (len_a + len_b > 18){			// 2 extra element is needed (1 blank & 1 NULL char)
		printf("Error\n");
		return ;
	}
	
	// Append string b into a
	a[len_a] = ' ';						// Add a blank
	for (int i = 0; i < len_b; i++)
		a[len_a + i + 1] = b[i];
	a[len_a + len_b + 1] = '\0';		// Add a NULL char
	
	printf("%s", a);
	
	return ;
}

int main()
{
	char a[MAX_STRING_SIZE];
	char b[MAX_STRING_SIZE];
	
	scanf("%s",a);
	scanf("%s",b);
	
	append(a,b);
	
	return 0;
}

/*	CALICO
	python -m calico.cli q1.t
	init ..................................... PASSED
	build .................................... PASSED
	case0 .................................... PASSED
	case3 .................................... PASSED
	case4 .................................... PASSED
	case5 .................................... PASSED
	Grade: 100 / 100
*/