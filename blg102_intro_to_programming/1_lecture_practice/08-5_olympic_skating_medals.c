/*	
	Write a C program that print out countries, gold/silver/bronze medal numbers of these countries, and total medals for each countries as a two dimension.
		1. Ask countries and the number of medals to user
		2. Find the winner country
		3. Print out all country names, all medal numbers according to medal types, total number of medals for each country and the winner country
		+ Medal Types: Gold, Silver, Bronze
		+ Multiply gold medals by 3, silver medals by 2, bronze medals by 1 to calculate the winner
		+ Maximum Country Number: 10
*/

#include <stdio.h>

#define CHAR_LIM	16	// Character limit for a country name
#define COUNTRY		10	// Country Count Limit
#define MEDAL		4	// Medal Tpyes: Gold (0), Silver (1), Bronze (2), Overall (3)

/*
 * @func	Get input for the country name
 * @return	-
 * @param	country[][CHAR_LIM]: 2-D country name array
 */
void get_input_country(char country[][CHAR_LIM]){
	printf("Be Careful! Character limit for each country name: 15\n");
	
	for (int i = 0; i < COUNTRY; i++){
		printf("Write %d. country name: ", i + 1);
		
		for (int j = 0; j < CHAR_LIM; j++){
			scanf("%c", &country[i][j]);
			
			// If enter is given, stop to get an input
			if (country[i][j] == '\n'){
				country[i][j] = '\0';
				break;
			}
		}
	}
	printf("\n");
}

/*
 * @func	Get input for the medal counts for each country
 * @return	-
 * @param	country[][CHAR_LIM]: 2-D country name array
 * 			medals[][MEDAL]: 2-D medal counts by countries
 */
void get_input_medals(char country[][CHAR_LIM], int medals[][MEDAL]){
	for (int i = 0; i < COUNTRY; i++){
		printf("%s\n", country[i]);
		
		for (int j = 0; j < MEDAL - 1; j++){
			if (j == 0)
				printf("Gold");
			else if (j == 1)
				printf("Silver");
			else
				printf("Bronze");
			printf(" medal: ");
			
			scanf("%d", &medals[i][j]);
		}
		printf("\n");
	}
}

/*
 * @func	Calculate the overall score and find the winner country
 * @return	max_i: Index value of the winner country
 * @param	medals[][MEDAL]: 2-D medal counts by countries
 */
int  find_winner(int medals[][MEDAL]){
	int max		= 0,
		max_i	= 0;
	
	for (int i = 0; i < COUNTRY; i++){
		// Calculate the overall score
		medals[i][3] = medals[i][0] * 3 + medals[i][1] * 2 + medals[i][2];
		
		// Find the greatest score
		if (medals[i][3] > max){
			max = medals[i][3];
			max_i = i;
		}
	}
	return max_i;
}

/*
 * @func	Print country names, medals counts as a table and the winner country 
 * @return	-
 * @param	country[][CHAR_LIM]: 2-D country name array
 * 			medals[][MEDAL]: 2-D medal counts by countries
 * 			winner: Index value of the winner country
 */
void print(char country[][CHAR_LIM], int medals[][MEDAL], int winner){
	// Print the header
	printf("%15s %10s %10s %10s %10s\n", "Country", "Gold", "Silver", "Bronze", "Overall");
	
	for (int i = 0; i < COUNTRY; i++){		
		// Print country name
		printf("%15s", country[i]);
		
		// Print medal counts
		for(int j = 0; j < MEDAL; j++){
			printf(" %10d", medals[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	// Print the winner country
	printf("The winner country is %s.\n", country[winner]);
}

int main()
{
	char	country[COUNTRY][CHAR_LIM];
	int		medals[COUNTRY][MEDAL];
	
	// Initialize all cells by 0
	for (int i = 0; i < COUNTRY; i++)
		for (int j = 0; j < MEDAL; j++)
			medals[i][j] = 0;
	
	// Get country names and medal counts
	get_input_country(country);
	get_input_medals(country, medals);
	
	// Find the winner country
	int	winner;
	winner = find_winner(medals);
	
	// Print country names, medal counts and overall score
	print(country, medals, winner);
	
	return 0;
}