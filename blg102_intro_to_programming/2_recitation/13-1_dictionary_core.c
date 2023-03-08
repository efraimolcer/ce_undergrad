#include "13-1_dictionary.h"

bool check_open_file(GDBM_FILE db){
    // If file could not opened, print error and stop to execute the function
    if (db == NULL){
        // Print error number if error occured
        printf("%s\n", gdbm_strerror(gdbm_errno));
        return 0;
    }
    else
        return 1;
}

bool add_word_op(char* word, char* trans){
    GDBM_FILE   db;
    datum       native,
                translate;
    int         check;
    
    db = gdbm_open(DB_FILENAME, 0, GDBM_WRCREAT, 0664, NULL);
    
    // If file could not opened, print error and stop to execute the function
    if (!check_open_file(db))
        return 0;
    
    // Create a word structures as datum struct
    native.dptr = word;
    native.dsize = strlen(word);
    
    translate.dptr = trans;
    translate.dsize = strlen(trans);
    
    // Store the data
    check = gdbm_store(db, native, translate, GDBM_INSERT);
    
    // Close the database
    gdbm_close(db);
    
    // Check storing status
    if (check == 1){
        printf("The word '%s' is already existed in the dictionary!\n", word);
        return 1;
    }
    else if (check == 0)
        return 1;
    else
        return 0;
}

bool delete_word_op(char* word){
    GDBM_FILE   db;
    datum       native;
    int         check;
    
    db = gdbm_open(DB_FILENAME, 0, GDBM_WRCREAT, 0664, NULL);
    
    // If file could not opened, print error and stop to execute the function
    if (!check_open_file(db))
        return 0;
    
    // Create a word structure as datum struct
    native.dptr = word;
    native.dsize = strlen(word);
    
    // Delete the data
    check = gdbm_delete (db, native);
    
    // Close the database
    gdbm_close(db);
    
    // Check deleting status
    if (check == 0)
        return 1;
    else
        return 0;
}

bool change_word_op(char* word, char* trans){
    int         check;
    
    // Delete the data
    if(!delete_word_op(word))
        return 0;
    
    // Add a word with new translation
    check = add_word_op(word, trans);
    
    // Check adding status
    if (check == 0)
        return 0;
    else
        return 1;
}

bool translate_word_op(char* word, char* trans){
    GDBM_FILE   db;
    datum       native,
                translate;
    
    db = gdbm_open(DB_FILENAME, 0, GDBM_READER, 0, NULL);
    
    // If file could not opened, print error and stop to execute the function
    if (!check_open_file(db))
        return 0;
    
    // Create a word structure as datum struct
    native.dptr = word;
    native.dsize = strlen(word);
    
    // Find the translation
    translate = gdbm_fetch(db, native);
    
    // Get the translation if it the word exists
    if (translate.dptr != NULL){
        strcpy(trans, translate.dptr);
        gdbm_close(db);
        return 1;
    }
    else{
        gdbm_close(db);
        return 0;
    }
}

bool list_op(char letter){
    GDBM_FILE   db;
    datum       native,
                translate;
    
    db = gdbm_open(DB_FILENAME, 0, GDBM_READER, 0, NULL);
    
    // If file could not opened, print error and stop to execute the function
    if (!check_open_file(db))
        return 0;
    
    // Find the key of the first element in the database
    native = gdbm_firstkey(db);
    
    // Print end of dictionary
    size_t i = 1;
    while(native.dptr != NULL){
        translate = gdbm_fetch(db, native);
        
        // If letter is 0, it means list all elements; or if the first letter of the current word equals to the given letter
        if(letter == '0' || letter == native.dptr[0]){
            if (i == 1)
                printf("%3s: %-20s\t%-20s\n", "#", "Native", "Translation");
            
            printf("%3zd: %-20s\t%-20s\n", i, native.dptr, translate.dptr);
            i++;
        }
        native = gdbm_nextkey(db, native);
    }
    
    // Close the database
    gdbm_close(db);
    
    return 1;
}