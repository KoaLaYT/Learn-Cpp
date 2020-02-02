#ifndef AVERAGE_H_20200202
#define AVERAGE_H_20200202

#include <cstdint>
#include <iostream>

class Average {
public:
  Average &operator+=(int val) {
    m_sum += val;
    m_amount += 1;

    return *this;
  }

  friend std::ostream &operator<<(std::ostream &out, const Average &a);

private:
  std::int_least32_t m_sum{0};
  std::int_least8_t m_amount{0};
};

#endif
