/**
 * Chapter 4 :: Question 3
 *
 * prompt user to input two floating number,
 * and the operation, then caculate the result.
 *
 * CAUTION: no error handling
 *
 * KoaLaYT  00:41 30/01/2020
 *
 */

#include <iostream>

double read_number() {
  std::cout << "Enter a double value: ";

  double input{};
  std::cin >> input;

  return input;
}

char read_operator() {
  std::cout << "Enter one of the following: +, -, *, or /: ";

  char op{};
  std::cin >> op;

  return op;
}

bool check_validation(char op) {
  return op == '+' || op == '-' || op == '*' || op == '/';
}

double calculate(char op, double fst, double snd) {
  switch (op) {
  case '+':
    return fst + snd;
  case '-':
    return fst - snd;
  case '*':
    return fst * snd;
  case '/':
    return fst / snd;
  default:
    throw "Unknown operator";
  }
}

int main() {
  double fst{read_number()};
  double snd{read_number()};
  char op{read_operator()};

  if (!check_validation(op)) {
    // unknown operator
    return 1;
  }

  double res = calculate(op, fst, snd);

  std::cout << fst << ' ' << op << ' ' << snd << " is " << res << '\n';
}
