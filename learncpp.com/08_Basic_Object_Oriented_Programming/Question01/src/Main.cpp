/**
 * Chapter 8 :: Question 1
 *
 * a simple Point2d class
 *
 * KoaLaYT  13:51  02/02/2020
 *
 */

#include "Point2d.h"

int main() {
  Point2d first;
  Point2d second{3.0, 4.0};

  first.print();
  second.print();

  std::cout << "Distance between two points: " << first.distance_to(second)
            << '\n';

  std::cout << "Distance between two points: " << distance_from(first, second)
            << '\n';

  return 0;
}
