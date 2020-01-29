/**
 * learncpp.com
 * Chapter 1 :: Question 3
 *
 * Prompt user to input two integers,
 * then show the sum and sub of them.
 *
 * CAUTION: this simple program has no error handling!
 *
 * KoaLaYT  01:08 29/01/2020
 *
 */

#include <iostream>

int main() {
  // input first int
  std::cout << "Enter an integer: ";
  int fst{};
  std::cin >> fst;

  // input second int
  std::cout << "Enter another iterger: ";
  int snd{};
  std::cin >> snd;

  std::cout << fst << " + " << snd << " is " << fst + snd << '\n';
  std::cout << fst << " - " << snd << " is " << fst - snd << '\n';
}
