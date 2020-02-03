#ifndef FRUIT_H_20200203
#define FRUIT_H_20200203

#include <string>

class Fruit {
public:
  Fruit(const std::string &name, const std::string &color)
      : m_name{name}, m_color{color} {}

  const std::string &get_name() const { return m_name; }

  const std::string &get_color() const { return m_color; }

private:
  std::string m_name;
  std::string m_color;
};

#endif

