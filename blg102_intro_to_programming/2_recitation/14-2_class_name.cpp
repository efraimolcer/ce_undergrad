/*
    Write a class to store, display and reverse a name in C++.
        1. Have a private char* variable to store a string (which is an address of a char array)
        2. Write the following class member functions:
            - Implement a constructor
            - Implement a destructor
            - Write a display() function
            - Write a reverse() function
        + Source file must end with .cpp instead of .c
*/

#include <iostream>
#include <string>
#include <stddef.h>

using namespace std;

class Name {
    public:
        Name(const char*);
        ~Name();
        void display()      const;
        void reverse();
    
    private:
        char* mp;
};

Name::Name(const char *p){
    int     len = strlen(p);
    size_t  i;
    
    mp = (char*)malloc((len + 1) * sizeof(char));
    strcpy(mp, p);
}

Name::~Name(){
    free(mp);
}

void Name::display() const {
    cout << "Your name is: " << mp << endl;
}

void Name::reverse(){
    int     len = strlen(mp);
    char    tmp;
    
    for (size_t i = 0; i < len / 2; i++){
        tmp = mp[i];
        mp[i] = mp[len - i - 1];
        mp[len - i - 1] = tmp;
    }
}

// Test code is already given
int main(){
    Name myname("nese");
    
    myname.display();
    
    myname.reverse();
    myname.display();
    
    return 0;
}