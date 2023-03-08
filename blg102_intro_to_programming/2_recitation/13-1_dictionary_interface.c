#include "13-1_dictionary.h"

void print_menu(){
    puts("\e[1;1H\e[2J");
    puts("(0) Terminate the program");
    puts("(1) Add a word");
    puts("(2) Delete a word");
    puts("(3) Change a word");
    puts("(4) Translate a word");
    puts("(5) List all");
    puts("(6) List words have a specific letter as a first letter");
    printf("What do you want to do: ");
}

void check_error(bool check){
    if(check)
        puts("Operation is successfully completed! (I)");
    else
        puts("Operation could not be successfully completed! (I)\n");
}

void conv_lowercase(char* word, bool type){
    size_t i = 0;
    
    if (type == 0){                                     // type 0: char
        if (*word >= 'A' && *word <= 'Z')
            *word += ' ';
    }
    else{                                               // type 1: string
        while (word[i] != '\0'){
            if (word[i] >= 'A' && word[i] <= 'Z')
                word[i] += ' ';
            i++;
        }
    }
}

void continue_run(){
    char tmp;
    printf("Enter to continue!");
    scanf("%c", &tmp);
    scanf("%c", &tmp);
}

void add_word(){
    char    word[SIZE],
            trans[SIZE];
    
    // Get a word and it's translation
    puts("ADD WORD");
    printf("Enter a word: ");
    scanf("%s", word);
    conv_lowercase(word, 1);
    
    printf("Enter the translation of a word: ");
    scanf("%s", trans);
    conv_lowercase(trans, 1);
    
    // Add these words into the database
    check_error(add_word_op(word, trans));
    
    continue_run();
}

void delete_word(){
    char    word[SIZE];
    
    // Get a word that wants to be deleted
    puts("DELETE WORD");
    printf("Enter a word that you want to delete: ");
    scanf("%s", word);
    conv_lowercase(word, 1);
    
    // Delete the word from the database
    if(delete_word_op(word))
        check_error(1);
    else
        printf("Word %s does not exist in the dictionary! (C)\n", word);
    
    continue_run();
}

void change_word(){
    char    word[SIZE],
            translate[SIZE];
    
    // Get a word to change the translation & its new translation
    puts("CHANGE WORD");
    printf("Enter a word: ");
    scanf("%s", word);
    conv_lowercase(word, 1);
    
    printf("Enter a new translation of the word: ");
    scanf("%s", translate);
    conv_lowercase(translate, 1);
    
    if(change_word_op(word, translate))
        check_error(1);
    else
        printf("Word %s does not exist in the dictionary! (C)\n", word);        
    
    continue_run();
}

void translate_word(){
    char    word[SIZE],
            translate[SIZE];
    
    translate[0] = '\0';
    
    // Get a word want to know the translation of it
    puts("TRANSLATE WORD");
    printf("Enter a word: ");
    scanf("%s", word);
    conv_lowercase(word, 1);
    
    translate[0] = '\0';
    
    translate_word_op(word, translate);
    
    // Print the translation
    if (translate[0] != '\0')
        printf("Translation: %-20s\n", translate);
    else
        printf("Word %s does not exist in the dictionary! (C)\n", word);
    
    translate[0] = '\0';
    continue_run();
}

void list_all(unsigned int* sel){
    // List all database
    check_error(list_op('0'));
    
    continue_run();
}

void list_letter(unsigned int* sel){
    char letter;
    
    // Get a letter to be listed
    printf("Enter a letter to list: ");
    scanf(" %c", &letter);
    conv_lowercase(&letter, 0);
    
    // List words have a given letter as the first letter
    check_error(list_op(letter));
    
    continue_run();
}

void run_dictionary(){
    unsigned int sel = 1;
    
    while (sel != 0){
        print_menu();
        scanf("%u", &sel);
        
        puts("\e[1;1H\e[2J");                           // Clear the terminal
        
        switch(sel){
            case 0:
                puts("Program is terminated! (I)\n");
                exit(EXIT_SUCCESS);
            case 1:
                add_word();
                break;
            case 2:
                delete_word();
                break;
            case 3:
                change_word();
                break;
            case 4:
                translate_word();
                break;
            case 5:
                list_all(&sel);
                break;
            case 6:
                list_letter(&sel);
                break;
            default:
                puts("Selection does not valid. Please enter a valid selection. (I)\n");
        }
    }
}

int main(int argc, char** argv){
    run_dictionary();
    
    return EXIT_SUCCESS;
}