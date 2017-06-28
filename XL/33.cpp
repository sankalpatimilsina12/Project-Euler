/**
  The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify 
  it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

  We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

  There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing 
  two digits in the numerator and denominator.

  If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
*/

#include <iostream>
#include <vector>

void getCommonRemoved(int &, int &);

int main() {
  int numerator = 1, denom = 1;

  // Find the numerator product and denominator product of the four non-trivial fractions.
  for(int i = 10; i < 100; i++)
    for(int j = i + 1; j < 100; j++) {
      int tempI = i, tempJ = j;
      getCommonRemoved(tempI, tempJ);                               // Remove common digit if present.
      if(tempI != i)                                                // Check if there was common.
        if((float)i / (float)j == (float)tempI / (float)tempJ) {
          numerator *= tempI;
          denom *= tempJ;
        }
    }

  // Reduce the numerator to denominator to the lowest fraction.
  for(int i = 2; i <= numerator / 2 + 1; i++)
    if(numerator % i == 0 and denom % i == 0) {
      numerator /= i;
      denom /= i;
      i = 1;               // Start from 2 again.
    }
  
  std::cout << "The value of the denominator is: " << denom << std::endl;
  return 0;
}

void getCommonRemoved(int &n, int &d) {
  if(n % 10 == 0 and d % 10 == 0)         // Trivial case. Eg. (20 / 30) = (2 / 3). However, it is not considered.
    return;

  std::vector<int> numerator;
  std::vector<int> denom;

  int tempN = n, tempD = d;

  while(tempN) {
    numerator.push_back(tempN % 10);
    tempN /= 10;
  }
  while(tempD) {
    denom.push_back(tempD % 10);
    tempD /= 10;
  }

  bool flag = false;
  for(int i = 0; i < numerator.size(); i++) {
    for(int j = 0; j < denom.size(); j++) 
      if(numerator[i] == denom[j]) {
        n = numerator[!i];
        d = denom[!j];
        flag = true;
      }
    if(flag)
      break;
  }
  return;
}