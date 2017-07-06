/**
  The first two consecutive numbers to have two distinct prime factors are:

  14 = 2 × 7
  15 = 3 × 5

  The first three consecutive numbers to have three distinct prime factors are:

  644 = 2² × 7 × 23
  645 = 3 × 5 × 43
  646 = 2 × 17 × 19.

  Find the first four consecutive integers to have four distinct prime factors each. 
  What is the first of these numbers?
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int getTotalDistinctPrimeFactors(long);

int main() {
  int consecCount = 0;
  long i;
  for(i = 2 * 3 * 7 * 11; consecCount != 4; i++) {
    if(getTotalDistinctPrimeFactors(i) == 4)
      consecCount++;
    else
      consecCount = 0;
  }

  std::cout << "The required first number is: " << i - 4 << std::endl;
  return 0;
}

int getTotalDistinctPrimeFactors(long num) {
  std::vector<int> Multipliers;
  for(int i = 2; i <= sqrt(num); ) {
    if(num % i == 0) {
      num /= i;
      Multipliers.push_back(i);
    } else i++;
  }
  if(num != 1)
    Multipliers.push_back(num);

  std::sort(Multipliers.begin(), Multipliers.end());
  int count = 0;
  for(int i = 0; i < Multipliers.size() - 1; i++)
    if(Multipliers[i] != Multipliers[i + 1])
      count++;
  count++;        // For the last number.
  return count;
}