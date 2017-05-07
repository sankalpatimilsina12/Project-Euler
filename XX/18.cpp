/*
By starting at the top of the triangle below and moving to adjacent numbers on the row below,
the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route.
However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot
be solved by brute force, and requires a clever method! ;o)
*/

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  std::string Num =
      "75"
      "95 64"
      "17 47 82"
      "18 35 87 10"
      "20 04 82 47 65"
      "19 01 23 75 03 34"
      "88 02 77 73 07 63 67"
      "99 65 04 28 06 16 70 92"
      "41 41 26 56 83 40 80 70 33"
      "41 48 72 33 47 32 37 16 94 29"
      "53 71 44 65 25 43 91 52 97 51 14"
      "70 11 33 28 77 73 17 78 39 68 17 57"
      "91 71 52 38 17 14 91 43 58 50 27 29 48"
      "63 66 04 68 89 53 67 30 73 16 69 87 40 31"
      "04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";

  const int NUM_ROWS = 15;

  // Remove spaces
  Num.erase(std::remove(Num.begin(), Num.end(), ' '), Num.end());

  // Make vector of every row inside a vector
  std::vector<std::vector<int> >Rows(NUM_ROWS);

  for(int i = 0, currentIndex = 0; currentIndex < Num.length(); currentIndex += (i + 1) * 2, i++) {
    std::string tempStr = Num.substr(currentIndex, (i + 1) * 2);

    for(int j = 0; j < tempStr.length(); j += 2)
      Rows[i].push_back((tempStr[j] - '0') * 10 + (tempStr[j + 1] - '0'));
  }

  /* Bottom - Top Approach. At first, take the first element of the second last row and add separately with the elements
   * directy below and to the right of the below element to find max of the addition. The max value of the addition is 
   * then used to replace the first element of the second row ie. our considered element. Do this for all elements of 
   * the second last row.
   * When the second last row is completed, we move to row above it and repeat the same process. This, way the
   * max result/path narrows as we move up. The uppermost value will thus contain the maximum value for the tree.

   * For ex.
   * Initially, we do (63 + 4) and (63 + 62). The second one is greater. Thus, 62 is replaced by the second result. Now,
   * we do (66 + 62) and (66 + 98) where again the second result is greater. Thus, 66 is replaced by the second result. We
   * continue this process till end of this second last row.
   * When this row is completed we take the third last row and again repeat the same process with the updated value of the
   * second last row.
  */

  for(int i = Rows.size() - 1; i > 0; i--)
    for(int j = 0; j < Rows[i - 1].size(); j++)
      Rows[i - 1][j] = (Rows[i][j] > Rows[i][j + 1]) ? (Rows[i - 1][j] + Rows[i][j]) : (Rows[i - 1][j] + Rows[i][j + 1]);

  std::cout << "The maximum total of the triangle is: " << Rows[0][0] << std::endl;
  return 0;
}
