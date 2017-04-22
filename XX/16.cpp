/*
215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
*/

#include <iostream>
#include <string>

int main()
{
  std::string num = "2";

  for(int i = 2; i <= 1000; i++)
  {
    int tempInt = 0, carry = 0;
    std::string tempStr = "";

    /* Take the number and multiply each digit by 2. Individual multiplication of digits will be
     * stored in 'tempInt' and carry in the 'carry' and alongside the 'tempStr' will be updated 
     * every time to contain the multiplication.

     * Finally, update the num to contain the next higher result of number powered by 2.
     * Continue until power 1000 is reached.


     * For ex:
        If we have 16 now as num. Then,
        1. Multiply 6 by 2 which gives 12.
           12 will now be stored as 2 in tempInt(and tempStr as well) and 1 in carry.
        2. Multiply 1 by 2 plus the carry which gives 3.
        3. Append that to tempStr as well which now becomes 32.
        4. Finally, update the num equal to tempStr ie. 32.
    */

    for(int j = num.length() - 1; j >= 0; j--)
    {
      tempInt = (num[j] - '0') * 2 + carry;

      if(tempInt > 9) 
      {
        tempStr += (tempInt % 10) + '0';
        carry = tempInt / 10;

        if(j == 0)
          tempStr += carry + '0';
      }
      else
      {
        tempStr += tempInt + '0';
        carry = 0;
      }
    }
    
    // Update the num to contain new tempStr.
    num = "";
    for(int k = tempStr.length() - 1; k >= 0; k--)
    {
      num += tempStr[k];
    }
  }

  // Sum every digit of the num.
  int sum = 0;

  for(int i = 0; i < num.length(); i++)
    sum += (num[i] - '0');

  std::cout << "The sum is: " << sum << std::endl;
  return 0;
}