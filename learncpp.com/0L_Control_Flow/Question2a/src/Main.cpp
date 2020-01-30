/**
 * Chapter L :: Question 2a
 *
 * A guessing game, with decent error handling
 *
 * KoalaYT  23:41 30/01/2020
 *
 */

#include "random.h"

#include <iostream>
#include <limits>

inline constexpr int max_tries{7};
using Random = effolkronium::random_static;

int get_guess(int i) {
  while (true) {
    std::cout << "Guess #" << i << ": ";

    int input{};
    std::cin >> input;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Please input an integer!\n";
    } else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return input;
    }
  }
}

void start_game() {
  std::cout << "Let's play a game. "
               "I'm thinking of a number. "
               "You have "
            << max_tries << " tries to guess what it is.\n";

  const int secret_number = Random::get(0, 100);
  // std::cout << "Cheat: " << secret_number << '\n';

  int tries{0};
  int guess{};
  while (tries < max_tries) {
    guess = get_guess(tries + 1);

    if (guess > secret_number) {
      std::cout << "Your guess is too high.\n";
    } else if (guess < secret_number) {
      std::cout << "Your guess is too low.\n";
    } else {
      std::cout << "Correct! You win!\n";
      return;
    }

    ++tries;
  }

  std::cout << "Sorry, you lose. The correct number was " << secret_number
            << '\n';
}

bool ask_replay() {
  while (true) {
    std::cout << "Would you like to play again (y/n)? ";

    char res{};
    std::cin >> res;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (res == 'y')
      return true;
    if (res == 'n')
      return false;
  }
}

int main() {
  do {
    start_game();
  } while (ask_replay());

  std::cout << "Thank you for playing\n";
}
