#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>

// Billy's input - Function to free memory for 1D dynamic array
void deleteIntRand1DArray_dynamic(int *dynamic1Darray)
{
  delete[] dynamic1Darray;
}

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

// Billy's input - Function to free memory for 2D dynamic array
void deleteIntRand2DArray_dynamic(int **dynamic2Darray, int row)
{
  for (int i = 0; i < row; i++)
  {
    delete[] dynamic2Darray[i];
  }
  delete[] dynamic2Darray;
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

// function 3 Convert an 2D array to a string
std::string arrayToString(int **input, int rows, int cols)
{
  std::string result;
  if (!input || rows <= 0 || cols <= 0)
    return result;
  for (int r = 0; r < rows; r++)
  {
    for (int c = 0; c < cols; c++)
    {
      result += std::to_string(input[r][c]);
      result += " ";
    }
    result += '\n';
  }
  return result;
}

// Function to free memory for an ordered 1D array
void deleteOrderedArray(int* orderedArray) {
    delete[] orderedArray;
}

// function 4 generates an ordered array of int
int *generateOrderedArray(int n)
{
  if (n <= 0)
    return nullptr;
  int *result = new int[n];
  for (int i = 0; i < n; i++)
  {
    result[i] = i;
  }
  return result;
}

// function 5 calculates the average of a 2d int array
double calculateAverage(int **array, int rows, int cols)
{
  // sum the items in variable array
  int totalSum = 0;
  for (int i = 0; i < rows; i++)
  {
    for (int k = 0; k < cols; k++)
    {
      totalSum += array[i][k];
    }
  }

  // caculate and return average
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

  deleteIntRand1DArray_dynamic(test1D);

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

  // test calculateAverage for 2D Array
  double test_averageOf_2DArray = calculateAverage(test2D, length_2D, height_2D);
  std::cout << "\nThe average of the 2D array is: " << test_averageOf_2DArray << '\n';

  // test arrayToString function for 2D Array
  std::cout << "\nArray to string out put for test 2D array: " << '\n';
  std::cout << arrayToString(test2D, length_2D, height_2D) << '\n';
  deleteIntRand2DArray_dynamic(test2D, length_2D);

  // test generateOrderedArray function
  std::cout << "Testing generateOrderedArray function: \n";
  int *ordered = generateOrderedArray(10);
  for (int i = 0; i < 10; i++)
  {
    std::cout << ordered[i] << " ";
  }
  std::cout << '\n';

  deleteOrderedArray(ordered);

  return 0;
}
