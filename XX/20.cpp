/*
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

#include <iostream>

int main()
{
  std::string Num = "100";

  /*
   * Take the 'Num' string and multiply each digit by the number in the factorial series.
   * Once one multiplication is finished, update the 'Num' string to contain the product.
   * Repeat above steps by multiplying with another number in the factorial series.
   * Repeat until multiplier 1 is reached(assuming multipliers are gradually in decreasing order).

   * For ex:
     Initially Num is 100.
     Each digit of 100 is multiplied by 99 and the 'Num' is updated to contain the multiplication result.
     Similarly each digit of the result is multiplied by 98 and 'Num' is again updated to contain new multiplication result.
     We do this until multiplier 1 is reached to find the factorial.
  */

  for(int i = 99; i >= 1; i--) {
    int carry = 0;
    std::string tempStr = "";

    for(int j = Num.length() - 1; j >= 0; j--) {
      int product = (Num[j] - '0') * i + carry;
      carry = product / 10;
      tempStr += (product % 10) + '0';
      if(!j) 
        while(carry) {
          tempStr += (carry % 10) + '0';
          carry /= 10;
        }
    }

    // Update the Num
    Num = "";
    for(int j = tempStr.length() - 1; j >= 0; j--)
      Num += tempStr[j];
  }

  // Find the sum
  int sum = 0;
  for(int i = 0; i < Num.length() - 1; i++)
    sum += Num[i] - '0';

  std::cout << "The sum of the digits is: " << sum << std::endl;
  return 0;
}