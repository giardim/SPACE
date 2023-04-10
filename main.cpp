#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "space.hpp"

int partition(std::string name, int **array, int rows, int cols, int l, int h)
{
  int R0 = 0, C0 = 0, R1 = 0, C1 = 0, R2 = 0, C2 = 0;
  int i = l - 1;
  for (int j = l; j <= h - 1; j++)
  {
    R0 = j / cols, C0 = j % cols, R1 = h / cols, C1 = h % cols;
    space::sout(name, array, rows, cols, R0, C0, R1, C1);
    if (array[R0][C0] < array[R1][C1])
    {
      i++;
      R2 = i / cols, C2 = i % cols;
      std::swap(array[R0][C0], array[R2][C2]);
      space::sout(name, array, rows, cols, R0, C0, R2, C2);
    }
  }
  i++;
  R2 = i / cols, C2 = i % cols;
  std::swap(array[R1][C1], array[R2][C2]);
  space::sout(name, array, rows, cols, R1, C1, R2, C2);
  return i;
}

void quicksort(std::string name, int **array, int rows, int cols, int l, int h)
{
  if (l < h)
  {
    int pi = partition(name, array, rows, cols, l, h);
    quicksort(name, array, rows, cols, l, pi - 1);
    quicksort(name, array, rows, cols, pi + 1, h);
  }
}

int main()
{
  srand(time(0));
  std::string name = "";
  int rows = 0, cols = 0, **array = 0;

  for (int n = 0; n < 16; n++)
  {
    name = "";
    for (int i = 0; i < 8; i++)
    {
      name += rand() % 26 + 97;
    }

    rows = cols = rand() % 16 + 16;
    array = new int *[rows];
    for (int r = 0; r < rows; r++)
    {
      array[r] = new int[cols];
      for (int c = 0; c < cols; c++)
      {
        array[r][c] = rand() % (rows * cols);
      }
    }

    quicksort(name, array, rows, cols, 0, rows * cols - 1);

    for (int r = 0; r < rows; r++)
      delete[] array[r];
    delete[] array;
  }

  return 0;
}