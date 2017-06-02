/*
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators
2 to 10 are given:

1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10 = 0.1

Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/

#include <iostream>

int main() {
  const int LIMIT = 1000;
  int largestRecurrenceCount = 0, largestDenom;

  for(int i = 2; i < LIMIT; i++) {
    /*
      Generate the remainders and check for recurrence in divisions. Any number 'n' will have maximum recurrence
      limit only upto 'n - 1' places if any. After that, we can stop checking for recurrence and
      proceed to next number.
    */

    int rem = 1;

    for(int j = 0; j < i; j++) {
      rem %= i;
      if(rem == 1 and j > 0) { // When rem = 1 again, the values will start repeating.
        (j > largestRecurrenceCount) ? (largestRecurrenceCount = j, largestDenom = i) : 1;
        break;
      }
      rem *= 10;
    }
  }

  std::cout << "The value of d for largest recurring cycle for d < " << LIMIT << " is: " << largestDenom << std::endl;
  return 0;
}