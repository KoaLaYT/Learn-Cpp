#ifndef FRACTION_H_2020_02_11
#define FRACTION_H_2020_02_11

#include <stdexcept>

class Fraction {
public:
  Fraction(int num, int den) : m_num{num}, m_den{den} {
    if (den == 0)
      throw std::runtime_error{"Invalid denominator"};
  }

private:
  int m_num;
  int m_den;
};

#endif
