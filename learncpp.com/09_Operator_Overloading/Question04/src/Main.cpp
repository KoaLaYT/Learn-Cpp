/**
 * Chapter 9 :: Question 4
 *
 * implement a two point fixed floating number
 *
 * KoaLaYT  20:37  02/02/2020
 *
 */

#include "FixedPoint2.h"

void testAddition() {
  // h/t to reader Sharjeel Safdar for this function
  std::cout << std::boolalpha;
  std::cout << (FixedPoint2{0.75} + FixedPoint2{1.23} == FixedPoint2{1.98})
            << '\n'; // both positive, no decimal overflow
  std::cout << (FixedPoint2{0.75} + FixedPoint2{1.50} == FixedPoint2{2.25})
            << '\n'; // both positive, with decimal overflow
  std::cout << (FixedPoint2{-0.75} + FixedPoint2{-1.23} == FixedPoint2{-1.98})
            << '\n'; // both negative, no decimal overflow
  std::cout << (FixedPoint2{-0.75} + FixedPoint2{-1.50} == FixedPoint2{-2.25})
            << '\n'; // both negative, with decimal overflow
  std::cout << (FixedPoint2{0.75} + FixedPoint2{-1.23} == FixedPoint2{-0.48})
            << '\n'; // second negative, no decimal overflow
  std::cout << (FixedPoint2{0.75} + FixedPoint2{-1.50} == FixedPoint2{-0.75})
            << '\n'; // second negative, possible decimal overflow
  std::cout << (FixedPoint2{-0.75} + FixedPoint2{1.23} == FixedPoint2{0.48})
            << '\n'; // first negative, no decimal overflow
  std::cout << (FixedPoint2{-0.75} + FixedPoint2{1.50} == FixedPoint2{0.75})
            << '\n'; // first negative, possible decimal overflow
}

int main() {
  testAddition();

  FixedPoint2 a{-0.48};
  std::cout << a << '\n';

  std::cout << -a << '\n';

  std::cout << "Enter a number: "; // enter 5.678
  std::cin >> a;

  std::cout << "You entered: " << a << '\n';

  return 0;
}
