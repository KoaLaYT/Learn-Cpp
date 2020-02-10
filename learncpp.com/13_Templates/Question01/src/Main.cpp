/**
 * Chapter 13 :: Question 1-3
 *
 * a simple exercise about template class
 *
 * KoaLaYT  19:43 10/02/2020
 *
 */

#include "Pair.h"

#include <iostream>

int main() {
  StringValuePair<int> svp("Hello", 5);
  std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

  return 0;
}
