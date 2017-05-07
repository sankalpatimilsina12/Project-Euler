/*
Each new term in the Fibonacci sequence is generated by adding the previous two terms.
By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million,
find the sum of the even-valued terms.
*/

#include <iostream>

int main()
{
  /* 
  For a typical 32-bit operating system, an int takes 4 bytes.
  Hence a signed int ranges from -2,147,483,648 to 2,147,483,647. 
  */

  const int LIMIT = 4000000;

  int 
      first  = 1,
      second = 2,
      third,
      sum = 0;

  while(second <= LIMIT)
  {
    /*
    Check if num is even. We can check from 'second'
    since it is first divisible even number.
    */
    if(second % 2 == 0)
      sum += second;

    /* Continue the fibonacci. */
    third  = first + second;
    first  = second;
    second = third;
  }

  std::cout << "The required sum is: " << sum << std::endl;
  return 0;
}