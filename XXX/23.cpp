/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called
abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two
abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as
the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is
known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include <iostream>
#include <vector>

int propDivSum(int);

int main() {
  const int LIMIT = 28123;

  // Find all the abundant numbers.
  std::vector<int> Abun;
  for(int i = 12; i <= LIMIT; i++)
    if(propDivSum(i) > i)
      Abun.push_back(i);

  // Find all the possible sums combination of abundant numbers.
  std::vector<bool> abunSums(LIMIT, false);
  for(int i = 0; i <= Abun[i] / 2; i++) {
    for(int j = i; j < Abun.size(); j++)
      if(Abun[i] + Abun[j] <= LIMIT)  
        abunSums[Abun[i] + Abun[j]] = true;
  }

  // Find the non-abundant sum.
  long int sum = 0;
  for(int i = 1; i <= LIMIT; i++)
    if(!abunSums[i])  
      sum += i;  

  std::cout << "The sum is: " << sum << std::endl;
  return 0; 
}

int propDivSum(int num) {
  int sum = 0;

  for(int i = 1; i <= num / 2; i++)
    if(num % i == 0)
      sum += i;

  return sum;
}