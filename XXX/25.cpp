/*
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/

#include <iostream>

int main() {
  std::string
          first = "1",
          second = "1",
          third;

  int count = 2;                  // For first two terms(given). 

  while(third.length() != 1000) {
    std::string sumStr = "";
    int sum, carry = 0;

    // Make the length of 'first' and 'second' same.
    first = std::string(second.length() - first.length(), '0').append(first);

    for(int i = second.length() - 1; i >= 0; i--) {
      sum = first[i] - '0' + second[i] - '0' + carry;
      carry = sum / 10;
      sumStr += (sum % 10) + '0';
      if(!i and carry)
        sumStr += carry + '0';
    }

    third = "";
    for(int i = sumStr.length() - 1; i >= 0; i--)
      third += sumStr[i];
    
    first = second;
    second = third;

    count++;
  }

  std::cout << "The index of first term in Fibonacci to contain 1000 digits is: " << count << std::endl;
  return 0;
}