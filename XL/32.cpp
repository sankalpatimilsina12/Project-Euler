/**
  We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once;
  for example, the 5-digit number, 15234, is 1 through 5 pandigital.

  The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product
  is 1 through 9 pandigital.

  Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9
  pandigital.

  HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int getLength(int);
bool checkPandigital(int, int, int);

int main() {
  /**
    Two possible multiplicand, multiplier combination:
      i. 1 digit multiplicand and 4 digit multiplier or vice versa giving 4 digit product.
      ii. 2 digit multiplicand and 3 digit multiplier or vice versa giving 4 digit product.

    For the first case, it is 1 through 99 and 1111 through 9999.
    For the second case, it is 11 through 99 and 111 through 999.

    Combining and generalizing, we can say, the cases are 1 through 99 and 111 through 9999.
  */
  std::vector<int> pandigitalProducts;

  for(int i = 1; i < 100; i++)
    for(int j = 111; j < 10000; j++) {
      if(getLength(i) + getLength(j) + getLength(i * j) == 9) {
        if(checkPandigital(i, j, i * j)) 
          pandigitalProducts.push_back(i * j);
      }
      else if(getLength(i) + getLength(j) + getLength(i * j) > 9)
        break;
    }
  
  long sum = 0;
  std::sort(pandigitalProducts.begin(), pandigitalProducts.end());
  for(int i = 0; i < pandigitalProducts.size() - 1; i++)
    if(pandigitalProducts[i] != pandigitalProducts[i + 1])
      sum += pandigitalProducts[i];
  
  sum += pandigitalProducts[pandigitalProducts.size() - 1];   // Include the last product.

  std::cout << "The sum is: " << sum << std::endl;
  return 0;
}

int getLength(int num) {
  int count = 0;
  while(num) {
    count++;
    num /= 10;
  }
  return count;
}

/** 
    This function checks whether the combination of multiplicand, multiplier and product
    is 1 through 9 pandigital.
*/
bool checkPandigital(int multiplicand, int multiplier, int product) {
  std::vector<int> digitContainer;
  while(multiplicand) {
    digitContainer.push_back(multiplicand % 10);
    multiplicand /= 10;
  }
  while(multiplier) {
    digitContainer.push_back(multiplier % 10);
    multiplier /= 10;
  }
  while(product) {
    digitContainer.push_back(product % 10);
    product /= 10;
  }
  std::sort(digitContainer.begin(), digitContainer.end());

  int count = 0;
  for(int i = 0; i < digitContainer.size() - 1; i++)
    if((digitContainer[i] != digitContainer[i + 1]) and digitContainer[i] != 0)
      count++;
  if(digitContainer[digitContainer.size() - 1] != 0) // For the last number.
    count++; 

  if(count == 9)
    return true;

  return false;
}