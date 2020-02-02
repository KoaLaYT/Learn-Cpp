#ifndef INTARRAY_H_20200202
#define INTARRAY_H_20200202

#include <cassert>
#include <iostream>

class IntArray {
public:
  IntArray() = delete;
  IntArray(int len) : m_arr{new int[len]}, m_len{len} {}

  IntArray(const IntArray &a) : m_arr{new int[a.m_len]}, m_len{a.m_len} {
    for (int i{0}; i < a.m_len; ++i) {
      m_arr[i] = a[i];
    }
  }

  ~IntArray() { delete[] m_arr; }

  int &operator[](int index) {
    assert(index >= 0 && index < m_len);

    return m_arr[index];
  }

  const int &operator[](int index) const {
    assert(index >= 0 && index < m_len);

    return m_arr[index];
  }

  IntArray &operator=(const IntArray &a) {
    if (&a == this)
      return *this;

    delete[] m_arr;

    m_arr = new int[a.m_len];
    for (int i{0}; i < a.m_len; ++i) {
      m_arr[i] = a[i];
    }
    m_len = a.m_len;

    return *this;
  }

  friend std::ostream &operator<<(std::ostream &out, IntArray &a);

private:
  int *m_arr;
  int m_len;
};

#endif

