/**
  The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 
  in some order, but it also has a rather interesting sub-string divisibility property.

  Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

  d2d3d4=406 is divisible by 2
  d3d4d5=063 is divisible by 3
  d4d5d6=635 is divisible by 5
  d5d6d7=357 is divisible by 7
  d6d7d8=572 is divisible by 11
  d7d8d9=728 is divisible by 13
  d8d9d10=289 is divisible by 17
  Find the sum of all 0 to 9 pandigital numbers with this property.
*/


#include <iostream>

int getLargestIndex(std::string &);
int getLargestIndex(std::string &, int);
void swapIndices(std::string &, int, int);
void reverseStringFromIndex(std::string &, int);
long long toDigits(std::string);       // Converts given numeric string to the corresponding number.

int main() {
  /**
    Generate lexicographic combinations of 0-9 digits.
    For each, check if sub-string digits are divisible by primes.
  */
  std::string digits = "0123456789";
  int primes[] = {2, 3, 5, 7, 11, 13, 17};
  long long sum = 0;
  while(true) {
    int largestX = getLargestIndex(digits);
    bool isPermutationLast = (largestX == -1);
    if(!isPermutationLast) {
      // Generate new 0 to 9 pandigital combination.
      int largestY = getLargestIndex(digits, largestX);
      swapIndices(digits, largestX, largestY);
      reverseStringFromIndex(digits, largestX + 1);
      // Check for the divisibility by primes.
      int i;
      for(i = 0; i < sizeof(primes) / sizeof(int); i++)
        if(toDigits(digits.substr(i + 1, 3)) % primes[i] != 0)
          break;
      if(i == sizeof(primes) / sizeof(int))
        sum += toDigits(digits);
    }
    else
      break;
  }
  std::cout << "The sum is: " << sum << std::endl;
  return 0;
}

int getLargestIndex(std::string &digits) {
  int i;
  for(i = digits.length() - 2; i >= 0; i--)
    if(digits[i] < digits[i + 1])
      break;
  return i;
}

int getLargestIndex(std::string &digits, int xIndex) {
  int i;
  for(i = digits.length() - 1; i > xIndex; i--)
    if(digits[xIndex] < digits[i])
      break;
  return i;
}

void swapIndices(std::string &digits, int xIndex, int yIndex) {
  char temp = digits[xIndex];
  digits[xIndex] = digits[yIndex];
  digits[yIndex] = temp;
  return;
}

void reverseStringFromIndex(std::string &digits, int xIndex) {
  std::string temp = "";
  for(int i = digits.length() - 1; i >= xIndex; i--)  
    temp += digits[i];
  for(int i = xIndex, j = 0; i < digits.length(); i++, j++)
    digits[i] = temp[j]; 
  return;
}

long long toDigits(std::string numStr) {
  long long digits = numStr[0] - '0';
  for(int i = 1; i < numStr.length(); i++)
    digits = digits * 10 + numStr[i] - '0'; 
  return digits;
}