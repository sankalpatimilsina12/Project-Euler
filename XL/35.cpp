/**
  The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719,
  are themselves prime.

  There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

  How many circular primes are there below one million?
*/

#include <iostream>
#include <cmath>

int getLength(long);
bool isPrime(long);

int main() {
  const long LIMIT = 1000000;
  int countCircularPrime = 0;

  // For every prime number find every rotation possible and check to see if all of them are also primes.
  for(long i = 2; i < LIMIT; i++) {
    long tempI = i;
    long newRotation = 0;
    if(isPrime(i)) {
      while(newRotation != i) {
        newRotation = (tempI % 10) * pow(10, getLength(tempI) - 1) + (tempI / 10);
        if(!isPrime(newRotation))
          break;
        else
          tempI = newRotation;
      }
      if(newRotation == i)
        countCircularPrime++;
    }
  }

  std::cout << "The total circular primes is: " << countCircularPrime << std::endl;
  return 0;
}

int getLength(long num) {
  int count = 0;
  while(num) {
    count++;
    num /= 10;
  }
  return count;
}

bool isPrime(long num) {
  for(long i = 2; i <= sqrt(num); i++)
    if(num % i == 0)
      return false;
  return true;
}