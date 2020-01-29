/**
 * Chapter 2 :: Question 3
 *
 * Ask for two integer from user,
 * show the sum of them.
 *
 * Split code into a sub library
 *
 * KoaLaYT  20:54 29/01/2020
 */

#include "Io.h" // sub library

#include <iostream>

int main() {
  int fst{read_number()};
  int snd{read_number()};

  std::cout << "After adding " << fst << " and " << snd << '\n';
  write_answer(fst + snd);
}
