/*	
	Write a C program that print out the dealing card for 4 people using one deck.
		1. Write all faces and all suits constantly
		2. Combine faces and suits and mix the deck
		3. Deal the cards randomly
		4. Print out all cards for 4 people using both member and pointer operations
	+ Faces: Ace, Deuce, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King
	+ Suits: Hearts, Diamonds, Clubs, Spades
*/

#include <stdio.h>
#include <stdlib.h>	// rand(), srand()
#include <time.h>	// time()

#define SIZE		10
#define LIM_FACE	13
#define LIM_SUIT	4

typedef struct{
	char face[SIZE];
	char suit[SIZE];
} Cards;

int main(){
	char* faces[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	char* suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	// Create a deck array
	Cards deck[52];
	
	// Generate 52 card structures separately
	for (int i = 0; i < LIM_FACE; i++){								// Generate each faces
		for (int j = 0; j < LIM_SUIT; j++){							// Generate each suits for all faces
			for (int k = 0; k < SIZE; k++){							// Copy names into decks struct array
				deck[i * LIM_SUIT + j].face[k] = faces[i][k];		// i * LIM_SUIT + j = 1 to 52 | k = each char | [i][k] = each faces
				deck[i * LIM_SUIT + j].suit[k] = suits[j][k];		// [j][k] = each suits
			}
		}
	}
	
	// Assign 4 different card for 4 people randomly
	srand(time(NULL));
	int sel;
	
	// Print values using member operator
	for (int i = 1; i <= 4; i++){
		sel = rand() % 52;
		printf("Person %d: %s %s\n", i, deck[sel].face, deck[sel].suit);
	}
	printf("\n\n");
	
	// Print values using pointer operator
	for (int i = 1; i <= 4; i++){
		sel = rand() % 52;
		printf("Person %d: %s of %s\n", i, (deck + sel)->face, (deck +sel)->suit);
	}
	
	return 0;
}