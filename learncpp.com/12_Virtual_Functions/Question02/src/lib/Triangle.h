#ifndef TRIANGLE_H_20200207
#define TRIANGLE_H_20200207

#include "Point.h"
#include "Shape.h"

class Triangle : public Shape {
public:
  Triangle(Point p1, Point p2, Point p3) : m_p1{p1}, m_p2{p2}, m_p3{p3} {}

  virtual std::ostream &print(std::ostream &out) const override {
    out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ')';
    return out;
  }

private:
  Point m_p1;
  Point m_p2;
  Point m_p3;
};

#endif
