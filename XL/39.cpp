/**
  If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three 
  solutions for p = 120.

  {20,48,52}, {24,45,51}, {30,40,50}

  For which value of p ≤ 1000, is the number of solutions maximised?
*/

#include <iostream>
#include <cmath>

int main() {
  int countSolutions = 0, pMax;
  for(int peri = 121; peri <= 1000; peri++) {
    int tempCountSolutions = 0;
    for(int p = 1; p < peri / 3; p++)
      for(int b = p + 1; ; b++) {
        float h = sqrt(p * p + b * b);
        if(p + b + h > peri)
          break;
        else if(p + b + h == peri)
          tempCountSolutions++;
      }
    (tempCountSolutions > countSolutions) ? (pMax = peri, countSolutions = tempCountSolutions) : 1;
  }
  std::cout << "The value of p for maximized solutions is: " << pMax << std::endl;
  return 0;
}