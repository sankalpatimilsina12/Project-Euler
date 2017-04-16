/* 
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
The sum of these multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <iostream>

int main()
{
  const int LIMIT = 1000;

  int sum = 0;

  for(int i = 3; i < LIMIT; i++)
  {
    if(i % 3 == 0 or i % 5 == 0)
    {
      sum += i;
    }
  }

  std::cout << "The required sum is: " << sum << std::endl;

  return 0;
}