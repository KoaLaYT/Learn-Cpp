#ifndef FIXEDPOINT2_H_20200202
#define FIXEDPOINT2_H_20200202

#include <cassert>
#include <cmath> // std::round
#include <cstdint>
#include <cstdlib>
#include <iostream>

class FixedPoint2 {
public:
  FixedPoint2(int itgl = 0, int frac = 0) {
    assert(frac >= -99 && frac <= 99);

    // as long as one is negative
    // make both parts negative
    if (itgl < 0 || frac < 0) {
      m_itgl = -std::abs(itgl);
      m_frac = -std::abs(frac);
    } else {
      m_itgl = itgl;
      m_frac = frac;
    }
  }

  FixedPoint2(double d) {
    m_itgl = static_cast<int_least16_t>(d);
    m_frac = static_cast<int_least8_t>(std::round((d - m_itgl) * 100));
  }

  operator double() const { return m_itgl + static_cast<double>(m_frac) / 100; }

  FixedPoint2 operator-() { return {m_itgl * (-1), m_frac * (-1)}; }

  friend bool operator==(const FixedPoint2 &p1, const FixedPoint2 &p2);

private:
  std::int_least16_t m_itgl;
  std::int_least8_t m_frac;
};

FixedPoint2 operator+(const FixedPoint2 &p1, const FixedPoint2 &p2);
std::ostream &operator<<(std::ostream &out, const FixedPoint2 &p);
std::istream &operator>>(std::istream &in, FixedPoint2 &p);

#endif
