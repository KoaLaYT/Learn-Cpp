#ifndef POINT2D_H_20200202
#define POINT2D_H_20200202

#include <iostream>

class Point2d {
public:
  Point2d(double x = 0.0, double y = 0.0) : m_x{x}, m_y{y} {}
  void print() const { std::cout << "Point2d(" << m_x << ", " << m_y << ")\n"; }
  double distance_to(const Point2d &a) const;
  friend double distance_from(const Point2d &a, const Point2d &b);

private:
  double m_x;
  double m_y;
};

#endif
