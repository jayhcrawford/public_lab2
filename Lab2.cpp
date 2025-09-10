#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>

// Function as defined by Professor Abdelrahim
// return 1D array of arg "size" populated with random values
int *intRand1DArray_dynamic(int size)
{
  srand((unsigned)time(NULL));

  int *result = new int[size];

  for (int i = 0; i < size; i++)
  {
    result[i] = rand() % 51;
  }

  return result;
}

// Function as defined by Professor Abdelrahim
// return 2D array of dimension args: "row" x "col" populated with random values
int **intRand2DArray_dynamic(int row, int col)
{
  srand((unsigned)time(NULL));
  int **result = new int *[row];
  for (int i = 0; i < row; i++)
  {
    result[i] = new int[col];
    for (int j = 0; j < col; j++)
    {
      result[i][j] = rand() % 51;
    }
  }

  return result;
}

// Function 3 Convert an 2D array to a string
std::string arrayToString(int **input, int rows, int cols)
{
  std::string result;
  std::for_each(input, input + rows, [&](int *row)
                {
        std::for_each(row, row + cols, [&](int num) {
            result += std::to_string(num) + " ";
        });
        result += '\n'; });
  return result;
}
// function 4 generates an ordered array of int
int *generateOrderedArray(int n)
{
  int *result = new int[n];

  std::iota(result, result + n, 0);

  return result;
}
// function 5  calculates the average of a 2d int array
double calculateAverage(int **array, int rows, int cols)
{
  int totalSum = std::accumulate(array[0], array[0] + rows * cols, 0);

  double average = static_cast<double>(totalSum) / (rows * cols);
  return average;
}

int main()
{
  std::cout << "Testing 1D Array generation: " << '\n';
  int length_1D = 10;
  int *test1D = intRand1DArray_dynamic(length_1D);
  for (int i = 0; i < length_1D; i++)
  {
    std::cout << test1D[i] << " ";
  }
  std::cout << '\n'
            << '\n';

  std::cout << "Testing 2D Array generation: " << '\n';
  int length_2D = 10;
  int height_2D = 10;
  int **test2D = intRand2DArray_dynamic(length_2D, height_2D);
  for (int i = 0; i < length_2D; i++)
  {
    for (int k = 0; k < height_2D; k++)
    {
      std::cout << test2D[i][k] << " ";
    }
    std::cout << '\n';
  }

  return 0;
}
