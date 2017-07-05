/**
  It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime 
  and twice a square.

  9 = 7 + 2×1^2
  15 = 7 + 2×2^2
  21 = 3 + 2×3^2
  25 = 7 + 2×3^2
  27 = 19 + 2×2^2
  33 = 31 + 2×1^2

  It turns out that the conjecture was false.

  What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
*/

#include <iostream>
#include <cmath>

bool isComposite(int);
bool isPrime(int);

int main() {
  /**
   If composite number was not formed for any value of prime (plus the values) less than the composite number,
   this number is the smallest number which doesnot follow Christian's method.
  */
  bool flag = false;
  int i;
  for(i = 9; ; i += 2) {
    if(isComposite(i)) {
      for(int j = 2; j < i; j++) {
        if(isPrime(j)) {
          for(int k = 1; ; k++) {
            int sum = j + 2 * k * k;
            if(sum == i) {
              flag = true;
              break;
            }
            else if(sum > i) {
              flag = false;
              break;
            }
          }
        }
        if(flag)
          break;
      }
    }
    if(!flag)
      break;
  }
  std::cout << "The required smallest odd composite number is: " << i << std::endl;
  return 0;
}

bool isComposite(int num) {
  for(int i = 2; i <= sqrt(num); i++)
    if(num % i == 0)
      return true;
  return false;
}

bool isPrime(int num) {
  for(int i = 2; i <= sqrt(num); i++)
    if(num % i == 0)
      return false;
  return true;
}
