/**
 * Chapter 11 :: Question 02
 *
 * A class inheritance practice
 *
 * KoaLaYT  22:54  03/02/2020
 *
 */

#include "Apple.h"
#include "Banana.h"
#include "GrannySmith.h"

#include <iostream>

int main() {
  Apple a{"red"};
  Banana b;
  GrannySmith c;

  std::cout << "My " << a.get_name() << " is " << a.get_color() << ".\n";
  std::cout << "My " << b.get_name() << " is " << b.get_color() << ".\n";
  std::cout << "My " << c.get_name() << " is " << c.get_color() << ".\n";

  return 0;
}
