#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>

// function 1 generate an array of random numbers given size as it's length
int *intRandom1DArray(int size)
{
  srand((unsigned)time(NULL));

  int *result = new int[size];

  std::generate_n(result, size, [&]()
                  { return rand(); });

  return result;
}
// Function 2 generates vector of vectors that is equivalent to a 2D array of random numbers
std::vector<std::vector<int>> intRand2DArray(int rows, int cols)
{
  auto createRow = [cols]()
  {
    std::vector<int> row(cols);
    std::generate(row.begin(), row.end(), []()
                  { return rand(); });
    return row;
  };

  std::vector<std::vector<int>> matrix(rows);
  std::generate(matrix.begin(), matrix.end(), createRow);
  return matrix;
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
  std::cout << "Hello World!\n";
}
