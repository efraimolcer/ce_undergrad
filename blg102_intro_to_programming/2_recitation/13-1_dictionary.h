#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <gdbm.h>

#define SIZE 100 // Character limit for a word
#define DB_FILENAME "13-1_dictionary_db" // Name of the database

// Functions in dictionary_interface.c
void print_menu();
void check_error(bool);
void conv_lowercase(char*, bool);
void continue_run();
void add_word();
void delete_word();
void change_word();
void translate_word();
void list_all(unsigned int*);
void list_all(unsigned int*);
void run_dictionary();

// Functions in dictionary_core
bool check_open_file(GDBM_FILE);
bool add_word_op(char*, char*);
bool delete_word_op(char*);
bool change_word_op(char*, char*);
bool translate_word_op(char*, char*);
bool list_op(char);