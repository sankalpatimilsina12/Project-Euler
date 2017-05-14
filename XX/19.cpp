/*
You are given the following information, but you may prefer to do some research for yourself.

* 1 Jan 1900 was a Monday.
* Thirty days has September,
  April, June and November.
  All the rest have thirty-one,
  Saving February alone,
  Which has twenty-eight, rain or shine.
  And on leap years, twenty-nine.
* A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/
#include <iostream>

int main()
{
  std::string Months[][3] = {
    {"Zero", "00"},
    {"Jan", "31"}, {"Feb", "28"}, {"Mar", "31"}, {"Apr", "30"}, {"May", "31"}, {"Jun", "30"},
    {"Jul", "31"}, {"Aug", "31"}, {"Sep", "30"}, {"Oct", "31"}, {"Nov", "30"}, {"Dec", "31"},
    {"Feb-Leap", "29"}
  };

  int
      Day = 2,  // Monday in 1 Jan 1900
      Year = 1900,
      sundayCount = 0;

  for(Year = 1900; Year <= 2000; Year++)
    for(int j = 1; j <= 12; j++) {
      int temp;
      
      if(j == 2 and (Year % 4 == 0) and (Year % 100 != 0 or Year % 400 == 0))
        temp = (Months[13][1][0] - '0') * 10 + Months[13][1][1] - '0';
      else 
        temp = (Months[j][1][0] - '0') * 10 + Months[j][1][1] - '0';

      Day += temp;
      Day %= 7;
      if(!Day)
        Day = 7;
      
      switch(Year) {
        case 1900:
            break;
        default:
            if(Day == 1)
              sundayCount++;
            break;
      }
    }

  std::cout << "The total Sundays is: " << sundayCount << std::endl;
  return 0;
}