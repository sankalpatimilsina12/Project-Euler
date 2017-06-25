/**
  In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

  1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
  It is possible to make £2 in the following way:

  1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
  How many different ways can £2 be made using any number of coins?
*/

#include <iostream>

int main() {
  long count = 0;
  for(int h = 0; h <= 200; h += 200)
    for(int g = 0; g + h <= 200; g += 100)
      for(int f = 0; f + g + h <= 200; f += 50)
        for(int e = 0; e + f + g + h <= 200; e += 20)
          for(int d = 0; d + e + f + g + h <= 200; d += 10)
            for(int c = 0; c + d + e + f + g + h<= 200; c += 5)
              for(int b = 0; b + c + d + e + f + g + h <= 200; b += 2)
                for(int a = 0; a + b + c + d + e + f + g + h <= 200; a++)
                  if(a + b + c + d + e + f + g + h == 200)
                    count++;
                
  std::cout << "The total different ways of making £2 is: " << count << std::endl;
  return 0;
}
