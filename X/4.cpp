/*
A palindromic number reads the same both ways. The largest palindrome made
from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>

bool isPalindrome(const int);

int main()
{
  int largestPalindrome = 0;

  for(int i = 100; i <= 999; i++)
  {
    for(int j = i; j <= 999; j++)
    {

      const int product = i * j; 

      if(product > largestPalindrome && isPalindrome(product))
      {
        largestPalindrome = i * j;
      }

    }
  }

  std::cout << "The largest palindrome is: " << largestPalindrome << std::endl;
  return 0;
}

bool isPalindrome(const int originalNum)
{

  int 
    x          = originalNum,
    reverseNum = 0;

  while(x >= 1)
  {
    reverseNum = (reverseNum * 10) + (x % 10);
    x /= 10;
  }

  return (reverseNum == originalNum);
}