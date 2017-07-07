/**
  The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

  Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
*/

#include <iostream>
#include <sstream>

std::string getPowered(int, int);

int main() {
  /**
    To find the last ten digits of the required series, we only take last 10 digits of every powered combination and
    add them together. Say, for example, 11 ^ 11 gives 285,311,670,611 which is 12 digits but during addition,
    we only take last 10 digits, ie. 5,311,670,611 since other digits are insignificant to the answer.
  */
  std::string sumStr("0");
  for(int i = 1; i <= 1000; i++) {
    std::string tempPowerStr = getPowered(i, i);
    std::string tempSumStr;
    // Make length of sumStr and tempStr same.
    sumStr = std::string(tempPowerStr.length() - sumStr.length(), '0') + sumStr;
    int carry = 0, sum;
    for(int j = tempPowerStr.length() - 1; j >= 0; j--) {
      sum = tempPowerStr[j] - '0' + sumStr[j] - '0' + carry; 
      carry = sum / 10;
      tempSumStr += (sum % 10 + '0');
      if(!j)
        while(carry) {
          tempSumStr += (carry % 10 + '0');
          carry /= 10;
        }
    }
    if(tempSumStr.length() > 10)
      tempSumStr = tempSumStr.substr(0, 10);
    // Update sumStr.
    sumStr = "";
    for(int j = tempSumStr.length() - 1; j >= 0; j--)
      sumStr += tempSumStr[j];
  }
  std::cout << sumStr << std::endl;
  return 0;
}
std::string getPowered(int a, int b) {
  /**
    * Convert each number to its string representation.
    * Multiply each digit of the number from right towards left with all the carry considerations.
    * Repeat this for the 'b' number of times where b is the power to be raised of the number 'a'.
  */

  // Covert number to string.
  std::ostringstream ss;
  ss << a;
  std::string strNum = ss.str();

  for(int i = 1; i < b; i++) {
    int carry = 0;
    std::string tempStr;
    bool flag = false;
    // Mulitply the current number by 'a'.
    for(int j = strNum.length() - 1; j >= 0; j--) {
      int prod = (strNum[j] - '0') * a + carry;
      tempStr += (prod % 10 + '0');
      carry = prod / 10;
      if(!j)
        while(carry) {
          tempStr += (carry % 10 + '0');
          carry /= 10;
        }
    }
    if(tempStr.length() > 10)
      tempStr = tempStr.substr(0, 10);
    // Update the number.
    strNum = "";
    for(int j = tempStr.length() - 1; j >= 0; j--)
      strNum += tempStr[j];
  }
  return strNum;
}