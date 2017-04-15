/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <iostream>

int main()
{
  bool flag = false;
  int  i;

  for(i = 20; ; i++)
  {
    for(int j = 1; j <= 20; j++)
    {
      if(i % j != 0)
        break;

      if(j == 20 and (i / j) % 2 == 0)
        flag = true;
    }

    if(flag)
      break;
  }

  std::cout << "The smallest positive number is: " << i << std::endl;
  return 0;
}