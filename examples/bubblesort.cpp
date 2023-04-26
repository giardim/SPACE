/*
This program is to show the user how SPACE is used in a bubblesort algorithm
    Please note you do not need to understand the bubblesorting algorithm,
    this is just a demo on how to use SPACE can be used to visualize how an 
    algorithm works

When you compile and run this program, a data.json file will either be
    created or overwritten. Drag and drop that file into the browser app
    to visualize how a sorting algorithm is accomplished.

    Written By Sean Smith and  Sazzad Ibrahim

*/

#include <iostream>
#include <algorithm>

// First, we need to include space.hpp
#include "../space.hpp"

int main() {
    // Its a good idea to save the size of the array in a variable to 
    // make your code easier to read and modify
    int size = 12;
    int my_array[size] = {7, 4, 2, 1, 15, 3, 6, 11, 18, 13, 12, 5};

    // Save the initial state of the array
    space::sout("my_array", my_array, size);

    // Bubble sort algorithm
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (my_array[j] > my_array[j + 1]) {
            
                // Swap elements using std::swap
                std::swap(my_array[j], my_array[j + 1]);

                // Every time there is a swap, save the array again
                space::sout("my_array", my_array, size);
                
            }
        }
    }

    // Save the final state of the array
    space::sout("my_array", my_array, size);

    return 0;
}