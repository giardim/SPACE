#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "space.hpp"

int partition(std::string name, int array[], int size, int l, int h)
{
    int i = l - 1;
    for (int j = l; j <= h - 1; j++)
    {
        space::sout(name, array, size, j, h);
        if (array[j] < array[h])
        {
            std::swap(array[++i], array[j]);
            space::sout(name, array, size, i, j);
        }
    }
    std::swap(array[i + 1], array[h]);
    space::sout(name, array, size, i + 1, h);
    return i + 1;
}

void quicksort(std::string name, int array[], int size, int l, int h)
{
    if (l < h)
    {
        int pi = partition(name, array, size, l, h);
        quicksort(name, array, size, l, pi - 1);
        quicksort(name, array, size, pi + 1, h);
    }
}

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

        quicksort(name, array, size, 0, size - 1);

        delete[] array;
    }

    return 0;
}