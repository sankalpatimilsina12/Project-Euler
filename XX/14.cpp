/*
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains
10 terms. Although it has not been proved yet (Collatz Problem), it is thought
that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <iostream>

int main()
{
  const int LIMIT = 1000000;

  long longestChainNum = 0;
  int countChain = 0;

  for(int i = 2; i < LIMIT; i++)
  {
    int tempCount = 0;
    long tempNum = i;

    while(tempNum != 1)
    {
      if(tempNum % 2 == 0)
        tempNum /= 2;
      else
        tempNum = 3 * tempNum + 1;
      
      tempCount++;
    }

    (tempCount > countChain) ? (longestChainNum = i, countChain = tempCount) : 1;
  }

  std::cout << "The number " << longestChainNum << " produces the longest chain." << std::endl;
  return 0;
}