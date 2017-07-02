/**
  We shall say that an n-digit number is pandigital if it makes use of all 
  the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital 
  and is also prime.

  What is the largest n-digit pandigital prime that exists?
*/

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>

std::string toString(long);
bool isPandigital(std::string);
bool isPrime(long);

long largestPanDigitalPrime;
int main() {
  /**
    9-digit pandigital = 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 = 45
    8-digit pandigital = 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 = 36
    7-digit pandigital = ... = 28
    6-digit pandigital = ... = 21
    5-digit pandigital = ... = 15
    4-digit pandigital = ... = 10
    3-digit pandigital = ... = 6
    2-digit pandigital = ... = 3

    All except 4-digits and 7-digits pandigital numbers are divisible by 3.
    So, our limit is for 7-digits and 4-digits numbers only ie, 
        1234567 to 7654321 and 1234 to 4321.
    Combining and generalising, our limit is from 1234 to 7654321.

  */
  for(long i = 7654321; i >= 1234; i--) {
    if(isPandigital(toString(i)))
      if(isPrime(i)) {
        largestPanDigitalPrime = i;
        break;
      }
      if(i == 1234567) i = 4321;
  }
  std::cout << "The largest n-digit pandigital prime is: " << largestPanDigitalPrime << std::endl;
  return 0;
}

std::string toString(long num) {
  std::ostringstream ss;
  ss << num;
  return ss.str();
}

bool isPandigital(std::string num) {
  std::sort(num.begin(), num.end());
  if(num[0] == '0')
    return false;
  for(int i = 0; i < num.length(); i++)
    if(num[i] - '0' != i + 1)
      return false;
  return true;
}

bool isPrime(long num) {
  for(long i = 2; i <= sqrt(num); i++)
    if(num % i == 0)
      return false;
  return true;
}