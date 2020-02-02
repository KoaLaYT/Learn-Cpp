#include "IntArray.h"

std::ostream &operator<<(std::ostream &out, IntArray &a) {
  for (int i{0}; i < a.m_len; ++i) {
    out << a[i] << ' ';
  }
  return out;
}

