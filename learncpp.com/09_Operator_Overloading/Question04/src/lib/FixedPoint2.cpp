#include "FixedPoint2.h"

std::ostream &operator<<(std::ostream &out, const FixedPoint2 &p) {
  out << static_cast<double>(p);

  return out;
}

std::istream &operator>>(std::istream &in, FixedPoint2 &p) {
  double d{};
  in >> d;

  p = FixedPoint2{d};

  return in;
}

FixedPoint2 operator+(const FixedPoint2 &p1, const FixedPoint2 &p2) {
  return {static_cast<double>(p1) + static_cast<double>(p2)};
}

bool operator==(const FixedPoint2 &p1, const FixedPoint2 &p2) {
  return (p1.m_itgl == p2.m_itgl) && (p1.m_frac == p2.m_frac);
}
