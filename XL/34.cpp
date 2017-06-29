/**
  145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

  Find the sum of all numbers which are equal to the sum of the factorial of their digits.

  Note: as 1! = 1 and 2! = 2 are not sums they are not included.
*/

#include <iostream>

long getFactorial(long);

int main() {
  /**
    9! = 362880. 
    For 999999, sum of the factorial of the digits is = 6 * 9! = 2177280.
    For 9999999, sum of the factorial of the digits is = 7 * 9! = 2540160.
    For 99999999, sum of the factorial of the digits is = 8 * 9! = 2903040.

    In a similar way, if the digits are increased by one, the sum will increase by 9!, which is 362880, so can never
    equal the corresponding number. So, our valid bound is upto 7 digit ie. 2540160.
  */
  
  const long LIMIT = 2540160;
  long numSum = 0;

  for(long i = 10; i <= LIMIT; i++) {
    long tempI = i;
    long sumOfFactorial = 0;
    while(tempI) {
      sumOfFactorial += getFactorial(tempI % 10);
      tempI /= 10;
    }
    if(sumOfFactorial == i)
      numSum += i;
  }

  std::cout << "The sum is: " << numSum << std::endl;
  return 0;
}

long getFactorial(long num) {
  if(num == 0 or num == 1)
    return 1;

  return num * getFactorial(num - 1);
}

