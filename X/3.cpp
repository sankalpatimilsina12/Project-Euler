/*
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
*/

#include <iostream>
#include <cmath>

bool checkPrime(int);

int main()
{
  const long long int NUM = 600851475143;

  int largestPrimeFactor = 0;

  for(int i = 2; i <= sqrt(NUM); i++)
    if(NUM % i == 0 and checkPrime(i))
      largestPrimeFactor = i;

  std::cout << "The largest prime factor of " << NUM << " is: " << largestPrimeFactor << std::endl;
  return 0;
}

bool checkPrime(int i)
{
  for(int j = 2; j <= sqrt(i); j++)
    if(i % j == 0)
      return false;

  return true;
}