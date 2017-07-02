/**
  An irrational decimal fraction is created by concatenating the positive integers:

  0.123456789101112131415161718192021...

  It can be seen that the 12th digit of the fractional part is 1.

  If dn represents the nth digit of the fractional part, find the value of the following expression.

  d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
*/

#include <iostream>
#include <sstream>
#include <cmath>

std::string toString(long);

int main() {
  // Go on appending integers to the fraction string and take values at every increasing power of 10.
  int mulProduct = 1;
  std::string fraction;
  for(long i = 1, tenthPower = 0; tenthPower != 6; i++) {
    fraction += toString(i);
    if(i / pow(10, tenthPower) == 1) {
      mulProduct *= fraction[(int)pow(10, tenthPower) - 1] - '0';
      tenthPower++;
    }
  }
  std::cout << "The value is: " << mulProduct << std::endl;
  return 0;
}

std::string toString(long num) {
  std::ostringstream ss;
  ss << num;
  return ss.str();
}