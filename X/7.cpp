/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

#include <iostream>
#include <cmath>

bool isPrime(int);

int main()
{
  const int POSITION = 10001;
  int 
    primeCount     = 0,
    i;

  for(i = 2; primeCount < POSITION; i++)
  {
    if(isPrime(i))
    {
      primeCount++;
    }
  }

  i--;  // This needs to be done because the value of i will increase by 1 after the loop.

  std::cout << "The " << POSITION << "st prime number is: " << i << std::endl;
  return 0;
}

bool isPrime(int x)
{
  for(int i = 2; i <= sqrt(x); i++)
  {
    if(x % i == 0)
      return false;
  }

  return true;
}