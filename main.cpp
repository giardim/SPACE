#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "space.hpp"

int main()
{
    srand(time(0));

    // int size = 0, *array = 0;
    // for (int n = 0; n < 16; n++)
    // {
    //     int offset = rand() % 3 * 32;
    //     size = rand() % 64 + 16, array = new int[size];
    //     for (int i = 0; i < size; i++)
    //     {
    //         array[i] = rand() % 64 - offset;
    //     }
    //     space::sout("array" + std::to_string(n + 1), array, size, 1, 2);
    //     delete[] array;
    // }

    //Bubble Sort

    int size = 5, array[5] = {5, 4, 3, 2, 1};

    for (int i = 0; i < size - 1; i++)
    {
        bool swap = false;
        for (int j = 0; j < size - i - 1; j++)
        {
         space::sout("array", array, size, i , j);
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
                space::sout("array", array, size, j , j + 1);
                swap = true;
            }
        }
        if (swap == false)
        {
            break;
        }
    }

    return 0;
}
