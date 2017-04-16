/*
The sum of the squares of the first ten natural numbers is,

1^2 + 2%2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first
ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one
hundred natural numbers and the square of the sum.
*/

#include <iostream>
#include <cmath>

int main()
{
  int
    sumOfSquares = 0,
    sum          = 0,
    squareOfSum;

  for(int i = 1; i <= 100; i++)
  {
    sumOfSquares += pow(i, 2);
    sum          += i;
  }

  squareOfSum = pow(sum, 2);

  std::cout << "The difference is: " << squareOfSum - sumOfSquares << std::endl;
  return 0;
}