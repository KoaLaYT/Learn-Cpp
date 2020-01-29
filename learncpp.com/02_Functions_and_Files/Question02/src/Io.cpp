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

