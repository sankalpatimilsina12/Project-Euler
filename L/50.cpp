/**
  The prime 41, can be written as the sum of six consecutive primes:

  41 = 2 + 3 + 5 + 7 + 11 + 13
  This is the longest sum of consecutive primes that adds to a prime below one-hundred.

  The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, 
  and is equal to 953.

  Which prime, below one-million, can be written as the sum of the most consecutive primes?
*/

#include <iostream>
#include <cmath>

#define LIMIT 1000000

/**
  We start generating sequences starting from 2, 3, and so on. For every generated sequence, we update the
  largest sequence count to refect the largest count possible which could be from any starting prime. However, our
  limit of starting primes ends at the condition where the current starting prime combined with previous largest 
  sequence count ie. we go from current starting prime and go on adding next primes for 'largest sequence count' number
  of times and if this gives the sequence sum which reaches or exceeds our limit ie. one million, we stop generating
  further sequences.
*/

bool isPrime(long);
long getNextPrime(long);
int getSequenceCount(long);
long getSequenceSum(int, int);

int main() {
  int largestSequenceCount = 0, startPrime = 0;
  for(int i = 2; ; i = getNextPrime(i)) {
    if(getSequenceSum(i, largestSequenceCount) >= LIMIT)
      break;
    int sequenceCount = getSequenceCount(i);
    (sequenceCount > largestSequenceCount) ? (largestSequenceCount = sequenceCount, startPrime = i) : 1;
  }
  std::cout << getSequenceSum(startPrime, largestSequenceCount) << std::endl;
  return 0;
}

bool isPrime(long num) {
  for(long i = 2; i <= sqrt(num); i++)
    if(num % i == 0)
      return false;
  return true;
}

long getNextPrime(long num) {
  num++;
  for(int i = 2; i <= sqrt(num); i++)
    if(num % i == 0) {
      i = 1;
      num++;
    }
  return num;
}

/**
  This functions returns the total number of terms in the sequence of prime starting with
  the given prime.
  For eg. for the sequence of primes below 100, if starting prime is 2, the sequence is: 2, 3, 5, 7, 11, 13 adding
  to 41, which is the longest consecutive primes adding to a prime below 100. Hence, the sequence count returned is 6.
*/
int getSequenceCount(long startPrime) {
  long sum = startPrime; 
  int sequenceCount = 1, primeSequenceCount = 0;
  for(int i = startPrime; sum < LIMIT; ) {
    i = getNextPrime(i);
    sum += i;
    sequenceCount++;
    if(isPrime(sum) and sum < LIMIT) {
      primeSequenceCount = sequenceCount;
    }
  }
  return primeSequenceCount;
}

/**
  This function returns the sum of the sequence for a given starting prime and a given total number of
  terms in the sequence.
*/
long getSequenceSum(int startPrime, int sequenceCount) {
  long sum = startPrime;
  for(int i = startPrime; sequenceCount > 1; sequenceCount--) {
    i = getNextPrime(i);
    sum += i;
  }
  return sum;
}