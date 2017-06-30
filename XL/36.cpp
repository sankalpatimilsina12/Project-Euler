/*
  The decimal number, 585 = 1001001001(2) (binary), is palindromic in both bases.

  Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

  (Please note that the palindromic number, in either base, may not include leading zeros.)
*/

#include <iostream>
#include <sstream>

std::string toString(long);
std::string toBinary(long);
bool isPalindrome(std::string);

int main() {
  const long LIMIT = 1000000;
  long sum = 0;

  for(long i = 0; i < LIMIT; i++) {
    if(isPalindrome(toString(i)))
      if(isPalindrome(toBinary(i)))
        sum += i;
  }

  std::cout << "The sum is: " << sum << std::endl;
  return 0;
}

std::string toString(long num) {
  std::ostringstream ss;
  ss << num;
  return ss.str();
}

std::string toBinary(long num) {
  std::string binStr;

  while(num) {
    binStr += (num % 2) + '0';
    num /= 2;
  }

  return binStr;
}

bool isPalindrome(std::string num) {
  std::string revStr;

  for(int i = num.length() - 1; i >= 0; i--)
    revStr += num[i];

  return (num == revStr);
}