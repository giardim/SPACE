#include <iostream>

#include "SPACE.hpp"

int main (void){
    int array[5] = {5, 8, 9, 3, 1};
    SPACE space;

    int size = sizeof(array) / sizeof (array[0]);

    for(int i = 0; i < 1; ++i){
        bool ans = space.test(array, i, ">", i + 1);
    }
    


    return 0;
}