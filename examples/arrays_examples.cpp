/*
This program is to show the user how to use our product to save and store
    one and two dimentional arrays
*/

#include <iostream>
#include "../space.hpp"

int main (void){
    // Below are initializations of arrays
    // Note: these arrays are initialized as integers
    //      however, SPACE supports ints, floats, doubles,
    //      bools, chars, and wchar_t data types
    int one_dimentional_array[5] = {1, 2, 3, 4, 5};
    int two_dimentional_array[3][3] = {{1,2,3}, {4, 5, 6}, {7, 8, 9}};

    // Below we are calling the sout function with one dimentioal arrays
    // Note: The sout function take three mandatory parameters and two optional 
    //      paramters. You must pass in the array name as a string, the array itself
    //      and the size of the array as an integer. As seen with the second sout call, you can
    //      also pass in the indices of the array as an integer, which will highlight the 
    //      indices in the browser app
    // sout function with indices
    space::sout("one_dimentional_array_no_indicies", one_dimentional_array, 5);
    // sout function without indices
    space::sout("one_dimentional_array_yes_indicies", one_dimentional_array, 5, 1, 2);

    // Below we are calling the sout function with one dimentioal arrays
    // Note: The sout function take four mandatory parameters and four optional 
    //      paramters. You must pass in the array name as a string, the array itself
    //      the number of rows as an integer and the number of columns as an integer.
    //       As seen with the second sout call, you can  also pass in the indices of 
    //      the array as an integer, which will highlight the indices in the browser app
    // sout function with indices
    space::sout("two_dimentional_array_no_indicies", two_dimentional_array, 3, 3);
    // sout function without indices
    space::sout("two_dimentional_array_yes_indicies", two_dimentional_array, 3, 3, 1, 2, 3, 4);

    // Notice how a data.JSON file has either been created or overwritten,
    //      you can now drag and drop that data.JSON file into the browser app
    //      to visualize your queue


    return 0;

}