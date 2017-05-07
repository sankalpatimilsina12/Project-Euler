/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

#include <iostream>
#include <cmath>

bool isPrime(int);

int main()
{
  const int LIMIT = 2000000;
  long long int sum = 0;

  for(int i = 2; i < LIMIT; i++)
    if(isPrime(i))
      sum += i;

  std::cout << "The sum is: " << sum << std::endl;
  return 0;
}

bool isPrime(int x)
{
  for(int i = 2; i <= sqrt(x); i++)
    if(x % i == 0)
      return false;

  return true;
}
