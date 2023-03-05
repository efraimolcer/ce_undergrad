//////////////////////////
// Name: Efraim Olcer   //
// SID:  150190713	    //
// Mail: olcer16		//
//////////////////////////

#include <stdio.h>
#include <stdlib.h> // EXIT_SUCESS, EXIT_FAILURE
#include <stddef.h>	// size_t

#define LINE_LIM	10000
#define LINE_CHAR	200

struct instruction_s{
	int step;
	int index;
};

/*
 * @func	Read text file & store in 2-D array
 * @return	-
 * @param	book: 2-D array to store the text line-by-line
 * 			book_name: name of the text file
 */
void read_file(char** book, char* book_name){
	FILE*	file;
	char	ch;
	
	// Open a book file
	if ((file = fopen(book_name, "r")) == NULL)
		exit(EXIT_FAILURE);
	
	// Read the book char-by-char, store in 2-D array (line->row, column->char)
	for(size_t i = 0; i < LINE_LIM; i++){
		for(size_t j = 0; j < LINE_CHAR; j++){
			ch = fgetc(file);
			
			if (ch == EOF){
				fclose(file);
				return ;
			}
			else if (ch == '\n')																// If a char is an end-of-line, stop getting chars from the current line
				break;
			else if(ch >= 'A' && ch <= 'Z')														// If a char is an uppercase, convert it into lowercase
				book[i][j] = ch + ' ';
			else if (ch != ' ' && !(ch >= '0' && ch <= '9') && !(ch >= 'a' && ch <= 'z'))		// If a char is a punctuation, enter a blank instead of it
				j--;
			else
				book[i][j] = ch;
		}
	}
	fclose(file);
}

/*
 * @func	Read instruction file & store in an array
 * @return	i: number of instructions read by the book (number of lines in instructions book)
 * @param	instructions: struct array to store instruction details one-by-one
 * 			inst_name: name of the instruction file
 */
int read_inst(struct instruction_s* instructions, char* inst_name){
	FILE*	file;
	
	// Open an instruction file
	if ((file = fopen(inst_name, "r")) == NULL)
		exit(EXIT_FAILURE);
	
	// Read instructions line-by-line, store in a struct
	int i = 0;
	while(!feof(file)){
		fscanf(file, "%d %d", &(instructions[i].step), &(instructions[i].index));
		i++;
	}
	
	fclose(file);
	return i;
}

/*
 * @func	Find the word in a given line
 * @return	word: char pointer to store the found word
 * @param	s: given line string
 * 			n: number of index which means the order number for the word in a given line
 * @dynam	word
 */
char* get_word(char* s, int n){
	char	*word = (char*)(malloc(sizeof(char) * (LINE_CHAR + 1)));		// Create dynamic memory to use a local variable as global to retur
	
	// Skip all blanks at the beginning of a line
	size_t	i_sen = 0;														// Char counter for the sentence array
	while(s[i_sen] == ' ')
		i_sen++;
	
	// Find the word
	size_t	ctr_word = 1,													// Word counter
			i_word = 0;														// Char counter for the word array
	while(s[i_sen] != '\0'){
		// Finding a blank means another word might comes
		if (s[i_sen] == ' '){
			ctr_word++;
			
			// Skip all blanks until a new word
			while(s[i_sen] == ' ')
				i_sen++;
		}
		
		// Save the word when it is founded
		if (ctr_word == n){
			word[i_word] = s[i_sen];
			i_word++;
		}
		i_sen++;
	}
	
	return word;
}

/*
 * @func	Find the hidden sentence through finding words marked in instructions file
 * @return	-
 * @param	lines: 2-D array that has whole text line-by-line
 * 			instructions: struct array that has instruction information
 * 			n_instructions: number of instructions read by the book
 * 			sentence: found hidden sentence (empty at the beginning & full at end of the function)
 * @dynam	word
 */
void get_sentence(char** lines, struct instruction_s* instructions, int n_instructions, char* sentence){
	char* word;
	
	// Find each word one-by-one
	size_t	i_line = -1,
			i_sen = 0;
	for(size_t i = 0; i < n_instructions; i++){
		i_line += instructions[i].step;										// Cumulative addition for line number because subsequent instructions specify the offset of the next line
		
		// Find a word by given instructions
		word = get_word(lines[i_line], instructions[i].index);
		
		// Store found word into a sentence array
		size_t i_word = 0;
		while(word[i_word] != '\0'){
			sentence[i_sen] = word[i_word];
			i_word++;
			i_sen++;
		}
		sentence[i_sen] = ' ';
		i_sen++;
		
		// Free the word array created in get_word
		free(word);
	}
}

// @dynam	**book, (*book) x LINE_LIM, sentence
int main(int argc, char* argv[]){
	struct	instruction_s* instructions = malloc( LINE_CHAR * sizeof(struct instruction_s));	// Create a struct array to store instructions
	char	**book = (char**)malloc(LINE_LIM * sizeof(*book)),									// Create a 2-D char array to store book line-by-line
			*sentence = (char*)malloc((LINE_CHAR + 1) * sizeof(char)),							// Create a char array to store the decrypted sentence
			*book_name = argv[1],
			*inst_name = argv[2];
	int		n_instructions;																		// Number of instructions (means instruction lines)
	
	for(int i = 0; i < LINE_LIM; i++)															// Create a char array for each line (index) of 2-D book array
		book[i] = (char*)malloc((LINE_CHAR + 1) * sizeof(char));
	
	// Read a book file
	read_file(book, book_name);
	
	// Read an instruction file & store in a struct
	n_instructions = read_inst(instructions, inst_name);
	
	// Find the hidden sentence & strore in a sentence string
	get_sentence(book, instructions, n_instructions, sentence);
	
	printf("%s", sentence);
	
	// Free dynamic memory allocations
	for(int i = 0; i < LINE_LIM; i++)
		free(book[i]);
	free(book);
	free(instructions);
	
	return EXIT_SUCCESS;
}

/*	CALICO
	python3 -m calico.cli assignment4_evaluation_tests.t
	init ..................................... PASSED
	build .................................... PASSED
	case1_given_with_hw ...................... 10 / 10
	case2_capitals ........................... 10 / 10
	case3_same_line .......................... 10 / 10
	case4_warning ............................ 10 / 10
	case5_single_word ........................ 10 / 10
	case6_two_dashes ......................... 10 / 10
	case7_single_dash ........................ 10 / 10
	case8_forward_walk ....................... 10 / 10
	case9_backward_walk ...................... 10 / 10
	case10_punctuations ...................... 10 / 10
	Grade: 100 / 100
*/