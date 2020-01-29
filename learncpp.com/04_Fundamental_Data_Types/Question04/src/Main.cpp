/**
 * Chapter 4 :: Question 4
 *
 * Simulate a ball being drop off by a tower,
 * prompt user to input the height of the tower,
 * and report the distance to ground every second (up to 5).
 *
 * KoaLaYT  01:00 30/01/2020
 *
 */

#include <iostream>

inline constexpr double gravity = 9.8;

double distance_at_sec(int sec) { return gravity * sec * sec / 2; }

int get_tower_height() {
  std::cout << "Enter the height of the tower in meters: ";

  int h{};
  std::cin >> h;

  return h;
}

int main() {
  int tower_height{get_tower_height()};

  for (int i = 0; i <= 5; i++) {
    std::cout << "At " << i << " seconds, the ball is ";

    double current_height{tower_height - distance_at_sec(i)};

    if (current_height > 0) {
      std::cout << "at height: " << current_height << " meters\n";
    } else {
      std::cout << "on the ground\n";
    }
  }
}
