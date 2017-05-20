/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names,
begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value
by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is
the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <vector>

int main() {
  // Read file into string.
  std::ifstream File("p022_names.txt");
  std::string Str((std::istreambuf_iterator<char>(File)),
                   std::istreambuf_iterator<char>());

  // Make a vector containing names.
  std::vector<std::string> Names;
  std::string tempStr = "";
  for(int i = 0; i <= Str.length(); i++) {        // We go upto Str.length instead of Str.length - 1 to find '\0'.
    if(Str[i] == ',' or Str[i] == '\0') {
      Names.push_back(tempStr);
      tempStr = "";
    }
    else 
      tempStr += Str[i];
  }

  // Sort the names in ascending order.
  for(int i = 0; i < Names.size() - 1; i++)
    for(int j = i + 1; j < Names.size(); j++)
      for(int k = 0; k < Names[i].length(); k++)
        if(Names[i][k] != Names[j][k]) {
          if(Names[i][k] > Names[j][k])
            Names[i].swap(Names[j]);
          break;
        }

  // Map alphabets to position.
  std::string Alphabets[][3] = {
    {"A", "01"}, {"B", "02"}, {"C", "03"}, {"D", "04"}, {"E", "05"}, {"F", "06"}, {"G", "07"}, {"H", "08"}, {"I", "09"},
    {"J", "10"}, {"K", "11"}, {"L", "12"}, {"M", "13"}, {"N", "14"}, {"O", "15"}, {"P", "16"}, {"Q", "17"}, {"R", "18"},
    {"S", "19"}, {"T", "20"}, {"U", "21"}, {"V", "22"}, {"W", "23"}, {"X", "24"}, {"Y", "25"}, {"Z", "26"}
  };

  // Calculate the name scores.
  long int sum = 0;

  for(int i = 0; i < Names.size(); i++) {
    int alpSum = 0;  

    for(int j = 0; j < Names[i].length(); j++) {
      if(Names[i][j] == '"')  
        continue;

      alpSum += (Alphabets[Names[i][j] - 'A'][1][0] - '0') * 10 + Alphabets[Names[i][j] - 'A'][1][1] - '0';
    }

    sum += alpSum * (i + 1);
  }

  std::cout << "The total of all the name scores is: " << sum << std::endl;
  return 0;
}