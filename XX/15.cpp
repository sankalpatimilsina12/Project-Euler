/*
Starting in the top left corner of a 2×2 grid, and only being able to move to
the right and down, there are exactly 6 routes to the bottom right corner.

https://projecteuler.net/project/images/p015.gif

How many such routes are there through a 20×20 grid?
*/

#include <iostream>

int main()
{
  long long int array[21][21]; // We need 21 * 21 because 21 total points make 20 boxes.

  // Fill out the outermost row line and column line by one. 
  for(int i = 1; i < 21; i++)
  {
    array[i][0] = 1;
    array[0][i] = 1;
  }

  /* Fill out the whole grid such that:
   * (x, y) = (x, y - 1) + (x - 1, y);
   * Say we have:
      (0, 1) having only one way from starting point (0, 0) to reach there.
      (1, 0) having only one way from starting point (0, 0) to reach there.
      Then, we can reach point (1, 1) by (0, 1) + (1, 0) so that the total routes will
      be sum of routes for corresponding ones ie. 1 + 1 = 2.
   * This way we continue to fill the whole grid.
   * The last point of the grid gives us the total routes for the whole grid to reach there.
  */

  for(int x = 1; x < 21; x++)
  {
    for(int y = 1; y < 21; y++)
    {
      array[x][y] = array[x][y - 1] + array[x - 1][y];
    }
  }

  std::cout << "The total number of routes is: " << array[20][20] << std::endl;
  return 0;
}
