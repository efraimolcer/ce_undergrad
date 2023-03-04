/*
	Write a program that
		1. Has a struct to get the content of the file
		2. Write a read_from_text_file function to read from students_src.txt
		3. Write a write_into_binary_file function to write into students_bin
		4. Write a read_from_binary_file function to read from students_bin
		5. Write a write_into_text_file to write into students_dst.txt
	+ Get the filenames from the command line
	+ Check if you can open the file, if not terminate the program
	+ Use fread, fwrite, fprintf, fscanf (alternativly sscanf)
	+ Data n students_src.txt consists: NAME, ID, 3 EXAM SCORES, 3 HW SCORES, LETTER_GRADE
*/

#include <stdio.h>
#include <stdlib.h>	// EXIT_SUCCESS, EXIT_FAILURE
#include <stddef.h> // size_t

#define SIZE	10
#define NUM		3

typedef struct{
	char	name[SIZE];
	int		id;
	int		exams[NUM];
	int		hws[NUM];
	char	grade[NUM];
} Student;

int	read_from_text_file(Student* class, char* src){
	FILE*	file;
	size_t	i = 0;
	
	// Check that file is opened successfully or not
	if ((file = fopen(src, "r")) == NULL){
		fprintf(stderr, "Source file could not be opened!\n");
		exit(EXIT_FAILURE);
	}
	
	int check = 0;
	for(; i < SIZE; i++){
		check = fscanf(file, "%s", class[i].name);			// Get student name from src file (sequential accesss)
		
		if (check != 1)										// If there is no name, stop to read
			break;
		
		fscanf(file, "%d", &(class[i].id));					// Get student id
		
		for(size_t j = 0; j < NUM; j++)						// Get exam scores
			fscanf(file, "%d", &(class[i].exams[j]));
		
		for(size_t j = 0; j < NUM; j++)						// Get homework scores
			fscanf(file, "%d", &(class[i].hws[j]));
		
		fscanf(file, "%s", class[i].grade);					// Get letter grade
	}
	fclose(file);
	
	return i;
}

void write_into_binary_file(Student* class, char* bin, int* size){
	FILE*	file;
	
	// Check that file is opened successfully or not
	if ((file = fopen(bin, "wb")) == NULL){
		fprintf(stderr, "Source file could not be opened!\n");
		exit(EXIT_FAILURE);
	}
	
	// Write stored student infos into dst file (random-access)
	for(size_t i = 0; i < *size; i++)
		fwrite(&(class[i]), sizeof(Student), 1, file);
	
	fclose(file);
}

void read_from_binary_file(Student* class_cpy, char* bin, int* size){
	FILE*	file;
	
	// Check that file is opened successfully or not
	if ((file = fopen(bin, "rb")) == NULL){
		fprintf(stderr, "Source file could not be opened!\n");
		exit(EXIT_FAILURE);
	}
	
	// Read from random access file
	for(size_t i = 0; i < *size; i++)
		fread(&(class_cpy[i]), sizeof(Student), 1, file);
	
	fclose(file);
}

void write_into_text_file(Student* class_cpy, char* dst, int* size){
	FILE*	file;
	
	// Check that file is opened successfully or not
	if ((file = fopen(dst, "w")) == NULL){
		fprintf(stderr, "Source file could not be opened!\n");
		exit(EXIT_FAILURE);
	}
	
	// Write into a file (sequential access)
	for(size_t i = 0; i < *size; i++)
		fprintf(file, "%-10s %4d %4d %4d %4d %4d %4d %4d %3s\n", class_cpy[i].name, class_cpy[i].id, class_cpy[i].exams[0], class_cpy[i].exams[1], class_cpy[i].exams[2], class_cpy[i].hws[0], class_cpy[i].hws[1], class_cpy[i].hws[2], class_cpy[i].grade);
	
	fclose(file);
}

int main(int argc, char* argv[]){		//argv[1]: students_src, argv[2]: students_dst, argv[3]: students_bin
	char	*src = argv[1],
			*bin = argv[2],
			*dst = argv[3];
	int		size;
	Student class[SIZE],
			class_cpy[SIZE];
	
	size = read_from_text_file(class, src);
	write_into_binary_file(class, bin, &size);
	read_from_binary_file(class_cpy, bin, &size);
	write_into_text_file(class_cpy, dst, &size);
	
	return EXIT_SUCCESS;
}