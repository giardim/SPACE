#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "space.hpp"

int main()
{
    srand(time(0));

    int size = 0, *array = 0;
    for (int n = 0; n < 16; n++)
    {
        int offset = rand() % 3 * 32;
        size = rand() % 64 + 16, array = new int[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = rand() % 64 - offset;
        }
        space::sout("array" + std::to_string(n + 1), array, size);
        delete[] array;
    }

    // Bubble Sort
    // for (int i = 0; i < size - 1; i++)
    // {
    //     bool swap = false;
    //     for (int j = 0; j < size - i - 1; j++)
    //     {
    //         if (array[j] > array[j + 1])
    //         {
    //             std::swap(array[j], array[j + 1]);
    //             space::sout("array", array, size, i , j);
    //             swap = true;
    //         }
    //     }
    //     if (swap == false)
    //     {
    //         break;
    //     }
    // }

    return 0;
}
