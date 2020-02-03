#ifndef BANANA_H_20200203
#define BANANA_H_20200203

#include "Fruit.h"

class Banana : public Fruit {
public:
  Banana() : Fruit{"banana", "yellow"} {}
};

#endif

