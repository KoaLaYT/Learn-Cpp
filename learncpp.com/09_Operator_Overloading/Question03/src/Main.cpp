/**
 * Chapter 9 :: Question 3
 *
 * a practice about copy constructor and assignment operator overload
 *
 * KoaLaYT  18:39  02/02/2020
 *
 */

#include "IntArray.h"
#include <iostream>

IntArray fillArray() {
  IntArray a(5);

  a[0] = 5;
  a[1] = 8;
  a[2] = 2;
  a[3] = 3;
  a[4] = 6;

  return a;
}

int main() {
  IntArray a{fillArray()};
  std::cout << a << '\n';

  auto &ref{
      a}; // we're using this reference to avoid compiler self-assignment errors
  a = ref;

  IntArray b(1);
  b = a;

  std::cout << b << '\n';

  return 0;
}
