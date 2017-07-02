/**
  The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

  1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

  By converting each letter in a word to a number corresponding to its alphabetical position and adding these values 
  we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a 
  triangle number then we shall call the word a triangle word.

  Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common 
  English words, how many are triangle words?
*/

#include <iostream>
#include <fstream>
#include <streambuf>
#include <algorithm>
#include <vector>

int main() {
  // Read file into string.
  std::ifstream File("p042_words.txt");
  std::string Str((std::istreambuf_iterator<char>(File)),
                   std::istreambuf_iterator<char>());
  
  // Make a vector containing words.
  std::vector<std::string> Words;
  std::string tempStr = "";
  for(int i = 0; i <= Str.length(); i++) {        // We go upto Str.length instead of Str.length - 1 to find '\0'.
    if(Str[i] == ',' or Str[i] == '\0') {
      Words.push_back(tempStr);
      tempStr = "";
    }
    else 
      tempStr += Str[i];
  }

  // Calculate the words' values and the maximum value.
  std::vector<int> Values;
  int maxVal = 0;
  for(int i = 0; i < Words.size(); i++) {
    int value = 0;
    for(int j = 0; j < Words[i].length(); j++) {
      if(Words[i][j] == '"')
        continue;
      value += Words[i][j] - 'A' + 1;
    }
    (value > maxVal) ? (maxVal = value) : 1;
    Values.push_back(value);
  }

  // Generate the triangle numbers equal to or just greater than the maximum value.
  std::vector<int> triangleNum;
  for(int i = 1; ; i++) {
    int nextTriangleNum = 0.5 * i * (i + 1);
    triangleNum.push_back(nextTriangleNum);
    if(nextTriangleNum >= maxVal)
      break;
  }

  // Count how many values exist in the traingular number vector.
  int countTriangularWords = 0;
  for(int i = 0; i < Values.size(); i++)
    if(std::find(triangleNum.begin(), triangleNum.end(), Values[i]) != triangleNum.end())
      countTriangularWords++;
  
  std::cout << "The total triangular words is: " << countTriangularWords << std::endl;
  return 0;
}