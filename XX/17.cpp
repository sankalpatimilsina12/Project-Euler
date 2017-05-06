/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five,
then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one 
hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/

#include <iostream>

int main()
{
  const std::string words[][2] = {
    {"zero", "0"},  // Zero count for number zero occurence.
    {"one", "3"}, {"two", "3"}, {"three", "5"}, {"four", "4"}, {"five", "4"}, {"six", "3"}, {"seven", "5"}, {"eight", "5"}, {"nine", "4"},  {"ten", "3"},
    {"eleven", "6"}, {"twelve", "6"}, {"thirteen", "8"}, {"fourteen", "8"}, {"fifteen", "7"}, {"sixteen", "7"}, {"seventeen", "9"}, {"eighteen", "8"}, {"nineteen", "8"}, {"twenty", "6"},
    {"thirty", "6"}, {"forty", "5"}, {"fifty", "5"}, {"sixty", "5"}, {"seventy", "7"}, {"eighty", "6"}, {"ninety", "6"}
  };

  int count = 0;

  for(int i = 1; i <= 1000; i++)
  {
    int temp = i;
    int remainder = 0;

    if(i == 1000) {
      count += 11; // 'one thousand'
      break;
    }

    if(temp >= 100)
    {
      if(temp % 100 != 0)
        count += 3;                                        // 'and'

      count += 7;                                          // 'hundred'
      count += (words[temp / 100][1][0] - '0');            //  num. Say i = 200; num will be 2.
      temp = temp % 100;
    }

    if(temp > 20)
    {
      remainder = temp % 10; 
      temp /= 10;
      count += (words[20 + temp - 2][1][0] - '0');
      count += (words[remainder][1][0] - '0');
    }
    else
      count += (words[temp][1][0] - '0');
  }

  std::cout << "The total letters used is: " << count << std::endl;
  return 0;
}