//
//  increaser.cpp
//  increaser
//
//  Created by Tim Lobes on 1/13/15.
//  Copyright (c) 2015 Tim Lobes. All rights reserved.
//

#include <iostream>

// Function to take an unknown data type pointer and increases it's referenced value

// Param: Pointer, byte size of pointer type
void increaser (void * data, int size) {
    // if data is empty
    if (data == NULL)
        std::cout << "Invalid data passed in\n";
    // if data is type char (1 byte)
    else if (size == 1) {
        char* Ptr = (char*)data; // Point new char pointer to data cast as a char pointer
        (*Ptr)++; // Increment the value of the derefernced data
    }
    // if data is type int (4 byte)
    else if (size == 4) {
        int* Ptr = (int*)data; // Point new int pointer to data cast as an int pointer
        (*Ptr)++; // Increment the value of the derefernced data
    }
}

// Overloaded Increaser
// Param: Pointer, byte size of pointer type, value to increment by
void increaser (void * data, int size, int incrementBy) {
    if (data == NULL)
        std::cout << "Invalid data passed in\n";
    else if (size == 1) {
        char* Ptr = (char*)data;
        for (int i = 0; i < incrementBy; i++)
            (*Ptr)++;
    }
    else if (size == 4) {
        int* Ptr = (int*)data;
        for (int i = 0; i < incrementBy; i++)
            (*Ptr)++;
    }
}


int main (int argc, const char* argv[]) {
    
    char x = 'a';
    int num = 0;
    
    char * cPtr = &x;
    int * iPtr = &num;
    void * nullPtr = NULL; // For testing the null case
    
    std::cout << "char size of " << sizeof(x) << " B and int size of " << sizeof(num) << " B\n";
    
    std::cout << "Before increaser call\n";
    std::cout << "x = " << x << std::endl;
    std::cout << "num = " << num << std::endl;
    
    increaser(cPtr, sizeof(char), 5);
    increaser(cPtr, sizeof(char));
    increaser(iPtr, sizeof(int), 5);
    increaser(iPtr, sizeof(int));
    increaser(nullPtr, sizeof(int));
    increaser(nullPtr, sizeof(int), 5);
    
    std::cout << "After increaser call\n";
    std::cout << "x = " << x << std::endl;
    std::cout << "num = " << num << std::endl;
    
    return 0;
}