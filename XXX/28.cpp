/*
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral
is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/

#include <iostream>

int main() {
  /*
    Top-right = n^2
    Top-left = n^2 - n + 1
    Bottom-left = n^2 - 2n + 2
    Bottom-right = n^2 - 3n + 3

    Summing above equations = 4n^2 - 6n + 6, where n is odd.
    The above equation will give the sum of the elements on the four corners assumming n is odd.
    For next value of n, the sum will of the the elements on the four corners narrowed one step down(assumming
    n is being decreased).
  */

  const int dimension = 1001;
  long int sum = 0;

  for(int n = dimension; n >= 3; n -= 2)
    sum += 4 * n * n - 6 * n + 6;
  
  // Add the last num '1'.
  sum += 1;
  
  std::cout << "The sum of the numbers on the diagonals for the 1001 by 1001 spiral is: " << sum << std::endl;
  return 0;
}