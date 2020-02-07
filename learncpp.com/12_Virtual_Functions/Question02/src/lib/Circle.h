#ifndef CIRCLE_H_20200207
#define CIRCLE_H_20200207

#include "Point.h"
#include "Shape.h"

class Circle : public Shape {
public:
  Circle(Point p, int r) : m_center{p}, m_radius{r} {}

  virtual std::ostream &print(std::ostream &out) const override {
    out << "Circle(" << m_center << ", "
        << "radius " << m_radius << ')';
    return out;
  }

  int getRadius() const { return m_radius; }

private:
  Point m_center;
  int m_radius;
};

#endif
