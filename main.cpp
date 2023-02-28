#include <ctime>
#include <cstdlib>
#include <iostream>

#include "space.hpp"

int main()
{
    srand(time(0));

    int size = 7, array[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 64;
    }
    space::sout("array", array, size, 0, 1);

    // Bubble Sort
    for (int i = 0; i < size - 1; i++)
    {
        bool swap = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
                space::sout("array", array, size, i , j);
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
