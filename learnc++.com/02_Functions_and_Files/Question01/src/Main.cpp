/**
 * Chapter 2 :: Question 1
 *
 * Ask for two integer from user, 
 * show the sum of them.
 *
 * KoaLaYT  20:29 29/01/2020
 */

#include <iostream>

// read a user's input
// CAUTION: no error handling
int read_number() {
  std::cout << "Please input an integer: ";

  int input{};
  std::cin >> input;

  return input;
}

void write_answer(int ans) { std::cout << "The answer is: " << ans << '\n'; }

int main() {
  int fst{read_number()};
  int snd{read_number()};

  std::cout << "After adding " << fst << " and " << snd << '\n';
  write_answer(fst + snd);
}
