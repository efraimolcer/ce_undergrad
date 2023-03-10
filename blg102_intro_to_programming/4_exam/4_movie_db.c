/*
    Assume we keep an array (name: movies) of pointers to structs. Write
        1. Create a struct that has a name 'Movie'. In this Movie struct, there are three attributes:
            The title of the movie
            How many times it was purchased
            An average rating for the movie.
        2. A function called get_purchases that searches a movie in the array using its title given by the user.
            If it finds the movie in the array, it returns the number of times the movie was purchased.
            If it does not find the movie in the array, it returns -1.
        3. Write a function called compute_rating that re-calculates the average rating of a movie based on the new rating given by the user.
            The function first searches for the movie with its title given by the user.
            If the movie is found
                The function adds the new rating to the movie's total rating, and re-calculates the average rating of the movie.
                The function then updates the rating of the movie.
                It also increments the number of purchases for the movie by one.
            If the movie is not found
                We offer the user to add this new movie with the given rating. This part is described in 4.
        4. Write a function called add_movie that adds a new movie to the array with its title and rating given by the user.
            It also sets the number of purchases to 1.
    + The array has a fixed size of 50, and it is assumed that the user will not try to add more than 50 movies to this array.
    + The title search must be case sensitive.
    + The array initially has two elements as shown in the source code.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MOVIES 50
#define MAX_TITLE 100

//add your functions and struct definition here.

typedef struct{
    char    movie_title[MAX_TITLE];
    int     purchases;
    double  movie_rating;
} Movie;

int check_same(char* name1, char* name2){
    int len1 = strlen(name1),
        len2 = strlen(name2);
    
    if (len1 != len2)
        return 0;
    else
        for (int i = 0; i < len1; i++)
            if (name1[i] != name2[i])
                return 0;
    
    return 1;
}

int movie_count(Movie* movies){
    int ctr_movie = 0;
    
    // Find the total number of movies
    while(movies[ctr_movie].movie_title[0] != '\0')
        ctr_movie++;
    
    return ctr_movie;
}

int get_purchases(Movie* movies, char* title){
    // Check that the given movie is in the database or not
    for (int i = 0; i < movie_count(movies); i++)
        if (check_same(movies[i].movie_title, title))
            return movies[i].purchases;
    
    return -1;
}

double compute_rating(Movie* movies, char* title, double movie_rating){
    // Scan all database
    for (int i = 0; i < movie_count(movies); i++){
        // Check that the given movie is in the database or not
        if(check_same(movies[i].movie_title, title)){
            movies[i].movie_rating = ((movies[i].movie_rating * movies[i].purchases) + movie_rating) / (movies[i].purchases + 1);
            movies[i].purchases++;
            printf("The movie %s is updated. The number of purchases is %d. The rating is updated to %.2f.\n", movies[i].movie_title, movies[i].purchases, movies[i].movie_rating);
            return movies[i].movie_rating;
        }
    }
    
    return 0;
}

int add_movie(Movie* movies, char* title, double movie_rating){
    int new_i = movie_count(movies);
    
    // Add new record to the database if there exists at least one empty space
    if (new_i < N_MOVIES){
        for(int i = 0; i < strlen(title); i++)
            movies[new_i].movie_title[i] = title[i];
        movies[new_i].movie_title[strlen(title)]  = '\0';
        movies[new_i].purchases                   = 1;
        movies[new_i].movie_rating                = movie_rating;
        return 1;
    }
    else
        return 0;
}

int main()
{
	//there are initially two elements in the array. 
    Movie movies[N_MOVIES] = { {"Spartacus", 9, 4.0}, {"Ben Hur", 5, 1.8}};
    
    char movie_title[MAX_TITLE];
    int movie_rating, menu_selection, result;
    char input;
    
    for (int i = 2; i < N_MOVIES; i++)
        movies[i].purchases = -1;
    
    printf("Welcome to the movie database.\n");
    do {
        printf("Enter your request (1 for getting the purchases of a movie, 2 for updating the rating of a movie, 3 for exit):");
        scanf("%d", &menu_selection);
        
        if (menu_selection == 1) {
            printf("Enter the movie title:");
            scanf(" %[^\n]s", movie_title);
            
            result = get_purchases(movies, movie_title);
            
            if (result != -1) {
                printf("The movie %s has been purchased %d times.\n", movie_title, result);
            } else {
                printf("The movie %s could not be found in the database.\n", movie_title);
            }
        }
        else if (menu_selection == 2) {
            printf("Enter the movie title:");
            scanf(" %[^\n]s", movie_title);
            
            printf("Enter the movie rating (out of 5):");
            scanf("%d", &movie_rating);
            
            while (movie_rating < 0 || movie_rating > 5) {
                printf("Enter the movie rating (out of 5):");
                scanf("%d", &movie_rating);
            }
            
            result = compute_rating(movies, movie_title, movie_rating);
            if (result == 0) {
                printf("The movie %s could not be found in the database. Would you like to add this movie (Y/N):", movie_title);
                scanf(" %c", &input);
                
                while (input != 'Y' && input != 'N') {
                    printf("Please enter a valid input (Y/N):");
                    scanf(" %c", &input);
                }
                if (input == 'Y') {
                    result = add_movie(movies, movie_title, movie_rating);
                    if (result == 1) {
                        printf("The movie %s is added to the database with a rating of %d.\n", movie_title, movie_rating);
                    } else {
                        printf("The movie %s could not be added to the database.\n", movie_title);
                    }
                }
            }
        }
    } while (menu_selection != 3);
    
    return EXIT_SUCCESS;
}

/*  CALICO
    python -m calico.cli q2.t
    init ..................................... PASSED
    build .................................... PASSED
    case0 .................................... PASSED
    case1 .................................... PASSED
    case2 .................................... PASSED
    case3 .................................... PASSED
    Grade: 100 / 100
*/