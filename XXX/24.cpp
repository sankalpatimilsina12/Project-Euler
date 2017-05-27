/*
 A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation
 of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically,
 we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
 
 012   021   102   120   201   210
 
 What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 */

 #include <iostream>

 int getLargestIndex(std::string &);
 int getLargestIndex(std::string &, int);
 void swapIndices(std::string &, int, int);
 void reverseStringFromIndex(std::string &, int);

 int main() {

   /* Algorithm:
    1. Find largest x such that A[x] < A[x + 1]. If no such combination exists, it is the last lexicographic permutation.
    2. Find largest y greater than x such that A[x] < A[y].
    3. Swap A[x] and A[y].
    4. Reverse from [x + 1, ..., n]. 

    For ex:
    1. Say we have A{0, 1, 2, 3} as our current lexicographic permutation.
    2. The largest x such that A[x] < A[x + 1] is 2 ie. A[x] = 2 and A[x + 1] = 3;
    3. The largest y greater than x such that A[x] < A[y] is 3 ie. A[x] = 2 and A[y] = 3;
    4. Swapping A[x] and A[y] results in A{0, 1, 3, 2};
    5. Reversing from [x + 1, ..., n] results in A{0, 1, 3, 2};
    6. Thus, A{0, 1, 3, 2} is our next lexicographic permutation.
   */

   std::string digits = "0123456789";
   const long int LIMIT = 1000000;
   long int count = 1;

  if(digits.length() == 1)
    goto stdout;

  for(; count != LIMIT; count++) {
    int largestX = getLargestIndex(digits);
    bool isPermutationLast = (largestX == -1);
    if(!isPermutationLast) {
      int largestY = getLargestIndex(digits, largestX);
      swapIndices(digits, largestX, largestY);
      reverseStringFromIndex(digits, largestX + 1);
    }
    else
      break;
   }

  stdout: {
    if(count == LIMIT)
      std::cout << "The " << count << "th lexicographic permutation of the given digits is: " << digits << std::endl;
    else 
      std::cout << "The last maximum " << count << "th lexicographic permutation of the given digits is: " << digits << std::endl;
  }

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