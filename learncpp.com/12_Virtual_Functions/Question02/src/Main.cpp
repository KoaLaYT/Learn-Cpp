/**
 * Chapter 12 :: Question 02
 *
 * to practice virtual function and dynamic_cast
 *
 * KoaLaYT  23:02  07/02/2020
 *
 */

#include "Circle.h"
#include "Triangle.h"

#include <vector>

int getLargestRadius(const std::vector<Shape *> &v) {
  int max{0};

  for (auto *s : v) {
    const Circle *c = dynamic_cast<Circle *>(s);
    if (c) {
      int r = c->getRadius();
      if (r > max)
        max = r;
    }
  }

  return max;
}

int main() {
  std::vector<Shape *> v;
  v.push_back(new Circle(Point(1, 2, 3), 7));
  v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
  v.push_back(new Circle(Point(4, 5, 6), 3));

  // print each shape in vector v on its own line here
  for (auto *s : v) {
    std::cout << *s << '\n';
  }

  std::cout << "The largest radius is: " << getLargestRadius(v)
            << '\n'; // write this function

  // delete each element in the vector here
  for (auto *s : v) {
    delete s;
  }

  return 0;
}
