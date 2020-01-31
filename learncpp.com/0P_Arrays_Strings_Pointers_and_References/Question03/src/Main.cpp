/**
 * Chapter P :: Question 3
 *
 * a swap function
 *
 * KoaLaYT 21:02 31/01/2020
 *
 */

#include <iostream>

void swap(int &a, int &b) {
  int temp{a};
  a = b;
  b = temp;
}

int main() {
  int a{3};
  int b{5};

  std::cout << "Before swap \t a: " << a << "\t b: " << b << '\n';

  swap(a, b);

  std::cout << "After swap \t a: " << a << "\t b: " << b << '\n';
}
