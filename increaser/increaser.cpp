//
//  increaser.cpp
//  increaser
//
//  Created by Tim Lobes on 1/13/15.
//  Copyright (c) 2015 Tim Lobes. All rights reserved.
//

#include <iostream>

// Function to take an unknown data type pointer and increases it's referenced value

// Param: Pointer, byte size of pointer type, value to increment by (default: 1)
void increaser (void * data, int size, int incrementBy=1) {
    if (data == NULL)
        std::cout << "Invalid data passed in\n";
    else if (size == sizeof(char)) {
        char* Ptr = (char*)data;
        for (int i = 0; i < incrementBy; i++)
            (*Ptr)++;
    }
    else if (size == sizeof(int)) {
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
    void * nullPtr = nullptr; // For testing the null case
    
    std::cout << "char size of " << sizeof(x) << " B and int size of " << sizeof(num) << " B\n";
    
    std::cout << "Before increaser call\n";
    std::cout << "x = " << x << std::endl;
    std::cout << "num = " << num << std::endl;
    
    increaser(cPtr, sizeof(char));
    increaser(cPtr, sizeof(char), 5);
    increaser(iPtr, sizeof(int));
    increaser(iPtr, sizeof(int), 5);
    increaser(nullPtr, sizeof(int));
    increaser(nullPtr, sizeof(int), 5);
    
    std::cout << "After increaser call\n";
    std::cout << "x = " << x << std::endl;
    std::cout << "num = " << num << std::endl;
    
    return 0;
}