#include "Average.h"

std::ostream &operator<<(std::ostream &out, const Average &a) {
  const double avg{static_cast<double>(a.m_sum) / a.m_amount};
  out << avg;

  return out;
}
