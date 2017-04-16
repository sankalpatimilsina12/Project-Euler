/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <iostream>
#include <cmath>

int main()
{
  bool flag = false;

  int a, b;

  for(a = 1; a < 1000; a++)
  {
    for(b = a + 1; b < 1000; b++)
    {
      if(pow(a, 2) + pow(b, 2) == pow(1000 - a - b, 2))
      {
        flag = true;
        break;
      }
    }

    if(flag)
      break;
  }

  std::cout << "The product abc is: " << a * b * (1000 - a - b) << std::endl;
  return 0;
}
