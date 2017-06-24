/**
  Surprisingly there are only three numbers that can be written as the sum of fourth
  powers of their digits:

  1634 = 1^4 + 6^4 + 3^4 + 4^4
  8208 = 8^4 + 2^4 + 0^4 + 8^4
  9474 = 9^4 + 4^4 + 7^4 + 4^4
  As 1 = 1^4 is not a sum it is not included.

  The sum of these numbers is 1634 + 8208 + 9474 = 19316.

  Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

#include <iostream>
#include <vector>

/**
  For 6-digit num: Max possible value: 999999. So, fifth power of every digit and its sum is: 6 * 9 ^ 5 = 354294.
  For 7-digit num: Max possible value: 9999999. So, fifth power of every digits and its sum is: 7 * 9 ^ 5 = 413343.
  From, the 7-digit onwards the individual digits powered to 5 and their sum can never be equal or greater than
  the corresponding 7-digit number.

  Hence, our bound is upto 6-digit number, ie. 354294.
*/

int main() {
  const long LIMIT = 354294;
  std::vector<long> Numbers;

  for(long i = 10; i <= LIMIT; i++) {
    long tempI = i, sum = 0;
    while(tempI) {
      long tempJ = 1;
      for(int j = 0; j < 5; j++) {
        tempJ *= tempI % 10;
      }
      sum += tempJ;
      tempI /= 10;
    }
    if(i == sum)
      Numbers.push_back(i);
  }

  // Find the sum of the numbers in the vector.
  long sum = 0;
  for(int i = 0; i < Numbers.size(); i++)
    sum += Numbers[i];
  
  std::cout << "The sum is: " << sum << std::endl;
  return 0;
}
