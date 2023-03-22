#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "space.hpp" 

int main()
{
    srand(time(0));

    int diff = 0;
    std::string name = "";
    int row = 5, col = 5;

    float array[5][5];

    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            array[i][j] = rand() % 1000;
        }
    }


    p2d(array, row, col);

    

    

    return 0;
}
