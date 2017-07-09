/**
  The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, 
  is unusual in two ways: 
    (i) each of the three terms are prime, and, 
    (ii) each of the 4-digit numbers are permutations of one another.

  There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, 
  but there is one other 4-digit increasing sequence.

  What 12-digit number do you form by concatenating the three terms in this sequence?
*/

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cmath>

bool isPrime(int);
bool isPermutations(int, int);
std::string toString(int);

int main() {
  // Find the primes.
  std::vector<int> Primes;
  for(int i = 1234; i <= 9876; i++)
    if(isPrime(i))
      Primes.push_back(i);
  
  // Find the permutations of the primes with common difference.
  std::vector<int> permutationsWithCommonDifference;
  for(int i = 0; i < Primes.size() - 1; i++) {
    for(int j = i + 1; j < Primes.size(); j++) {
      int commonDiff = Primes[j] - Primes[i];
      int nextFirst = Primes[i] + commonDiff;
      int nextSecond = Primes[i] + 2 * commonDiff;
      if(nextFirst > 9876 or nextSecond > 9876 or 
         !isPrime(nextFirst) or !isPrime(nextSecond))
          continue;
      if(isPermutations(Primes[i], nextFirst) and isPermutations(Primes[i], nextSecond)) {
        permutationsWithCommonDifference.push_back(Primes[i]);
        permutationsWithCommonDifference.push_back(nextFirst);
        permutationsWithCommonDifference.push_back(nextSecond);
      }
    }
  }

  // Print the next three terms that is not the one in question.
  std::string num;
  for(int i = 3; i < permutationsWithCommonDifference.size(); i++)
    num += toString(permutationsWithCommonDifference[i]);

  std::cout << num << std::endl;
  return 0;
}

bool isPrime(int num) {
  for(int i = 2; i <= sqrt(num); i++)
    if(num % i == 0)
      return false;
  return true;
}

/**
  This function checks if the functional arguments are permutations
  to one another.
*/
bool isPermutations(int num1, int num2) {
  std::ostringstream ss;
  ss << num1;
  std::string num1str = ss.str();
  ss.str(std::string());
  ss << num2;
  std::string num2str = ss.str();

  std::sort(num1str.begin(), num1str.end());
  std::sort(num2str.begin(), num2str.end());
  return (num1str == num2str);
}

std::string toString(int num) {
  std::ostringstream ss;
  ss << num;
  return ss.str();
}