/**
 * Chapter 14 :: Question1
 *
 * practice exception
 *
 * KoaLaYT  22:27 11/02/2020
 *
 */

#include "Fraction.h"

#include <exception>
#include <iostream>
#include <limits>

int get_num(const std::string &&type) {
  while (true) {
    std::cout << "Enter the " << type << ": ";
    int num{};
    std::cin >> num;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Please input a integer!\n";
    } else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return num;
    }
  }
}

int main() {
  int num{get_num("numerator")};
  int den{get_num("denominator")};

  try {
    Fraction f{num, den};
  } catch (std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
