/**
 * Chapter 2 :: Question 2
 *
 * Ask for two integer from user,
 * show the sum of them.
 *
 * Split code into two files without header files
 *
 * KoaLaYT  20:29 29/01/2020
 */

#include <iostream>

int read_number();
void write_answer(int ans);

int main() {
  int fst{read_number()};
  int snd{read_number()};

  std::cout << "After adding " << fst << " and " << snd << '\n';
  write_answer(fst + snd);
}
