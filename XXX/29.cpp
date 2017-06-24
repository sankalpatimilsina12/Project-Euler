/**
  Consider all integer combinations of a^b for 2 ≤ a ≤ 5 and 2 ≤ b ≤ 5:

  2^2=4, 2^3=8, 2^4=16, 2^5=32
  3^2=9, 3^3=27, 3^4=81, 3^5=243
  4^2=16, 4^3=64, 4^4=256, 4^5=1024
  5^2=25, 5^3=125, 5^4=625, 5^5=3125

  If they are then placed in numerical order, with any repeats removed, we get the 
  following sequence of 15 distinct terms:

  4, 8, 9, 16, 25 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125

  How many distinct terms are in the sequence generated by a^b for 2 ≤ a ≤ 100 and 2 ≤ b ≤ 100?
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

std::string getPowered(int, int);       // Returns the string representation of a number to its power.

int main() {
  std::vector<std::string> Numbers;
  for(int a = 2; a <= 100; a++)
    for(int b = 2; b <= 100; b++) {
      Numbers.push_back(getPowered(a, b));
    }
  // Count only the unique numbers in the vector.
  std::sort(Numbers.begin(), Numbers.end());
  int count = 0;
  for(int i = 0; i < Numbers.size() - 1; i++)
    if(Numbers[i] != Numbers[i + 1])
      count++;
  
  count++;    // For the last number.
  std::cout << "The total distinct terms are: " << count << std::endl;
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
    // Update the number.
    strNum = "";
    for(int j = tempStr.length() - 1; j >= 0; j--)
      strNum += tempStr[j];
  }

  return strNum;
}