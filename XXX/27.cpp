/*
Euler discovered the remarkable quadratic formula:
n^2 + n + 41
It turns out that the formula will produce 40 primes for the consecutive integer values 0 ≤ n ≤ 39.
However, when n = 40, 40^2 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41^2 + 41 + 41 
is clearly divisible by 41.

The incredible formula n^2 − 79n + 1601 was discovered, which produces 80 primes for the consecutive values 0 ≤ n ≤ 79. 
The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

n^2 + an + b, where |a| < 1000 and |b| ≤ 1000

where |n| is the modulus/absolute value of n
e.g. |11| = 11 and |−4| = 4
Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes
for consecutive values of n, starting with n = 0.
*/

#include <iostream>
#include <cmath>

bool isPrime(int);

int main() {
  int countPrime = 0, a, b;

  for(int i = 1; i < 1000; i++)
    for(int j = 1, n; j <= 1000; j++) {
      for(n = 0; ; n++) 
        if(!isPrime(n * n + i * n + j))
          break;
      (n > countPrime) ? (countPrime = n, a = i, b = j) : 1;
      for(n = 0; ; n++) 
        if(!isPrime(n * n + i * n - j))
          break;
      (n > countPrime) ? (countPrime = n, a = i, b = -j) : 1;
      for(n = 0; ; n++) 
        if(!isPrime(n * n - i * n + j))
          break;
      (n > countPrime) ? (countPrime = n, a = -i, b = j) : 1;
      for(n = 0; ; n++) 
        if(!isPrime(n * n - i * n - j))
          break;
      (n > countPrime) ? (countPrime = n, a = -i, b = -j) : 1;
    }

  std::cout << "The product a * b for maximum primes is: " << a * b << std::endl;
  return 0;
}

bool isPrime(int num) {
  if(num < 0 or num == 0 or num == 1)
    return false;

  for(int i = 2; i <= sqrt(num); i++)
    if(num % i == 0)
      return false;
  
  return true;
}