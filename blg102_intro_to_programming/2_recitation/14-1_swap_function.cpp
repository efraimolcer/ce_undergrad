/*
    Write two swap() functions to replace integer variables.
        1. One with using pointers
            - Declaration: void swap(int *p1, int *p2);
        2. The other one must be using references from C++
            - Declaration: void swapr(int &p1, int &p2);
    + Source file must end with .cpp instead of .c
*/

#include <iostream>

using namespace std;

void swap(int *p1, int *p2){
    int tmp;
    
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void swapr(int &p1, int &p2){
    int tmp;
    
    tmp = p1;
    p1 = p2;
    p2 = tmp;
}


// Test code is already given
int main() {
    int x = 10;
    int y = 45;
    
    swap(&x, &y);
    printf("x = %d \n", x);
    printf("y = %d \n", y);
    
    swapr(x, y);
    printf("x = %d \n", x);
    printf("y = %d \n", y);
    
    return 0;
}