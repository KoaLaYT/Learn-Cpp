/**
 * Chapter 0L :: Question 1
 *
 * enhance the ball falling question
 *
 * KoaLaYT  22:47 30/01/2020
 *
 */

#include "constants.h"
#include <iostream>
#include <limits>

// gets initial height from user and returns it
double getInitialHeight() {
  while (true) {
    std::cout << "Enter the height of the tower in meters: ";
    double initialHeight;
    std::cin >> initialHeight;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail()) {
      std::cin.clear();
      std::cout << "This value I just don't understand, try again!\n";
    } else {
      return initialHeight;
    }
  }
}

// Returns height from ground after "secondsPassed" seconds
double calculateHeight(double initialHeight, int secondsPassed) {
  // Using formula: [ s = u * t + (a * t^2) / 2 ], here u(initial velocity) = 0
  double distanceFallen{(constants::gravity * secondsPassed * secondsPassed) /
                        2.0};
  double currentHeight{initialHeight - distanceFallen};

  return currentHeight;
}

// Prints height every second till ball has reached the ground
bool printHeight(double height, int secondsPassed) {
  if (height > 0.0) {
    std::cout << "At " << secondsPassed << " seconds, the ball is at height:\t"
              << height << " meters\n";
    return true;
  } else {
    std::cout << "At " << secondsPassed
              << " seconds, the ball is on the ground.\n";
    return false;
  }
}

bool calculateAndPrintHeight(double initialHeight, int secondsPassed) {
  double height{calculateHeight(initialHeight, secondsPassed)};
  return printHeight(height, secondsPassed);
}

int main() {
  const double initialHeight{getInitialHeight()};

  int sec{0};
  bool isFalling{};
  do {
    isFalling = calculateAndPrintHeight(initialHeight, sec++);
  } while (isFalling);

  return 0;
}

