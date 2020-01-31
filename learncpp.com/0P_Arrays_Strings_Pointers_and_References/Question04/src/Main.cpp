/**
 * Chapter P :: Question 4
 *
 * a function to print c-style string
 *
 * KoaLaYT  21:11 31/01/2020
 *
 */

#include <iostream>

void print_c_string(const char *cstr) {
  while (*cstr) {
    std::cout << *cstr;
    ++cstr;
  }
  std::cout << '\n';
}

int main() {
  const char *str{"Hello, world!"};
  print_c_string(str);
}
