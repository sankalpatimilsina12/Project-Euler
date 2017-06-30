/**
  The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove
  digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work
  from right to left: 3797, 379, 37, and 3.

  Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

  NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/

#include <iostream>
#include <cmath>

int getLength(long);
bool checkPrime(long);

int main() {
  int countPrimes = 0;
  long sum = 0;

  // For every prime num, truncate from both sides and see if the results are also primes.
  for(long i = 8; countPrimes != 11; i++) {
    if(checkPrime(i)) {
      int numLen = getLength(i);
      long tempILeft, tempIRight;
      while(--numLen) {
        tempILeft = i % (long)pow(10, numLen);
        tempIRight = i / (long)pow(10, numLen);
        if(!checkPrime(tempILeft) or !checkPrime(tempIRight))
          break;
      }
      if(!numLen) {
        countPrimes++;
        sum += i;
      }
    }
  }

  std::cout << "The sum is: " << sum << std::endl;
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

bool checkPrime(long num) {
  if(num == 0 or num == 1)
    return false;
  for(long i = 2; i <= sqrt(num); i++)
    if(num % i == 0)
      return false;
  return true;
}

