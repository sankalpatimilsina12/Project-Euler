/**
  Take the number 192 and multiply it by each of 1, 2, and 3:

  192 × 1 = 192
  192 × 2 = 384
  192 × 3 = 576
  By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated 
  product of 192 and (1,2,3)

  The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, 
  which is the concatenated product of 9 and (1,2,3,4,5).

  What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer 
  with (1,2, ... , n) where n > 1?
*/

#include <iostream>
#include <sstream>
#include <algorithm>

std::string toString(long);
bool containsDuplicateOrZero(std::string);

int main() {
  /** 
    The problem here is to find the lower and upper bound to search:
      1. Since the question shows 918273645 can be already formed, the answer is surely equal to or greater than that.
      2. So, our upper and lower bound starts from 91..(n) to 98..(n).
      3.
       i. Since, the number is always multiplied by 1 at first, 91 and 98 digits surely come first in the bound.
       ii. So it is through 91 to 98, for the first case, which may produce 1-9 pandigital combination.
       ii. 912 to 987 for the second case.
       iii. 9123 to 9876 for the third case.
       iv. Above that, there will be more than 9 digits because the multiplier list is always greater than 1(ie. n > 1 
           which is given in the question) and if multiplied by 2 and concatenated it will exceed 9 digits.
      4. Combining and generalising, our bound is from 91 to 9876.
  */

  std::string largestNum;
  for(int i = 91; i <= 9876; i++) {
    std::string numStr;
    for(int j = 1; ; j++) {
      numStr += toString(i * j);
      if(containsDuplicateOrZero(numStr))
        break;
      else if(numStr.length() == 9) {
        (numStr > largestNum) ? (largestNum = numStr) : "";
      }
    }
    if(i == 98) i = 911;
    else if(i == 987) i = 9122;
  }
  std::cout << "The largest 1 to 9 pandigital number is: " << largestNum << std::endl;
  return 0;
}

std::string toString(long num) {
  std::ostringstream ss;
  ss << num;
  return ss.str();
} 

bool containsDuplicateOrZero(std::string num) {
  std::sort(num.begin(), num.end());
  if(num[0] == '0')
    return true;
  for(int i = 0; i < num.length() - 1; i++)
    if(num[i] == num[i + 1]) {
      return true;
    }
  return false;
}