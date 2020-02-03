#ifndef APPLE_H_20200203
#define APPLE_H_20200203

#include "Fruit.h"

class Apple : public Fruit {
public:
  Apple(const std::string &color) : Fruit{"apple", color} {}

  Apple(const std::string &name, const std::string &color)
      : Fruit{name, color} {}
};

#endif

