/*
    Write a class to store, display, push and pop nodes in a list in C++.
        1. Have a private struct Node which stores an integer type of data and an address of the next node.
        2. Write the following class member functions:
            - Implement a constructor
            - Implement a destructor
            - Write a display() function
            - Write a push() function
            - Write a pop() function
        + Source file must end with .cpp instead of .c
*/

#include <iostream>
#include <string>
#include <stddef.h>

using namespace std;

class List{
    public:
        List();
        ~List();
        void push(int);             // Increase the size of the array
        void display()      const;
        void pop();                 // Decrease the size of the array
    
    private:
        int data[100];
        int iterator;
};

List::List(){
    iterator = 0;
}

List::~List(){
}

void List::push(int val){
    if (iterator >= 100)
        cout << "List is full\n" << endl;
    else
        data[iterator] = val;
    
    iterator++;
}

void List::display() const {
    for(size_t i = 0; i < iterator; i++){
        cout << data[i] << " ";
        
        if ((i + 1) % 10 == 0)
            cout << endl;
    }
    cout << endl;
}

void List::pop(){
    iterator--;
}

// Test code is already given
int main() {
    List mylist;
    
    for (int k = 0; k < 100; k++)
        mylist.push(k);
    
    mylist.display();
    
    for (int k = 0; k < 90; k++)
        mylist.pop();
    
    mylist.display();
    
    return 0;
}