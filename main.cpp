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
    int size = 0, *array = 0;

    for (int n = 0; n < 16; n++)
    {
        name = "";
        for (int i = 0; i < 8; i++)
        {
            name += rand() % 26 + 97;
        }

        diff = rand() % 3 * 32;
        size = rand() % 32 + 32, array = new int[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = rand() % 64 - diff;
        }

        // Bubble Sort
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                space::sout(name, array, size, j, j + 1);
                if (array[j] > array[j + 1])
                {
                    std::swap(array[j], array[j + 1]);
                    space::sout(name, array, size, j, j + 1);
                }
            }
        }

        delete[] array;
    }

    return 0;
}

/* bool testing(int tarray){
    int new_array[6] = {1,2,3,4,5,6};
    int neg_array[6] = {1,};
    char char_array[6] = {};
    int neg_array[6] = {};
    char char_array_with_indices[6] = {};
    double db_array[6] = {};
    double double_array_with_indices[6] = {};

    return true;
}
*/