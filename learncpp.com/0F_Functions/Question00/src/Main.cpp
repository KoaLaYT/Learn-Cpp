/**
 * Chapter F :: Question 0
 *
 * a square guess game, to practice lambda function
 *
 * KoaLaYT  17:11 01/02/2020
 *
 */

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

int get_start() {
  std::cout << "Start where? ";

  int start{};
  std::cin >> start;

  // error handling omit
  return start;
}

int get_number() {
  std::cout << "How many? ";

  int number{};
  std::cin >> number;

  // error handling omit;
  return number;
}

int random2to4() {
  static std::mt19937 mt{
      static_cast<std::mt19937::result_type>(std::time(nullptr))};
  std::uniform_int_distribution rand{2, 4};
  return rand(mt);
}

void print_list(const std::vector<int> &list) {
  std::cout << "Cap: " << list.capacity() << " Len: " << list.size() << '\n';
  for (auto &el : list) {
    std::cout << el << ' ';
  }
  std::cout << '\n';
}

std::vector<int> generate_list(int start, int number) {
  std::vector<int> list(number);

  int factor = random2to4();

  for (int i{0}; i < number; ++i) {
    list[i] = start * start * factor;
    ++start;
  }

  std::cout << "I generate " << number
            << " square numbers. Do you know what each number is after "
               "multiplying it by "
            << factor << "?\n";

  return list;
}

int get_guess() {
  int input{};
  std::cin >> input;
  // error handling omit
  return input;
}

bool find_guess(std::vector<int> &list, const int guess) {
  auto found{std::find(list.begin(), list.end(), guess)};
  if (found != list.end()) {
    list.erase(found);
    if (list.size() > 0)
      std::cout << "Nice! " << list.size() << " numbers left.\n";
    return true;
  }
  return false;
}

int find_closest(const std::vector<int> &list, const int guess) {
  auto closest{std::min_element(
      list.begin(), list.end(), [=](const int &a, const int &b) {
        return std::abs(a - guess) < std::abs(b - guess);
      })};
  if ((*closest - guess) <= 4) {
    return *closest;
  } else {
    return -1;
  }
}

void square_game() {
  const int start{get_start()};
  const int number{get_number()};

  auto list{generate_list(start, number)};

  for (int i{0}; i < number; ++i) {
    const int guess{get_guess()};

    if (find_guess(list, guess)) {
      continue;
    } else {
      const int closest{find_closest(list, guess)};
      if (closest > 0)
        std::cout << guess << " is wrong! Try " << closest << " next time.\n";
      else
        std::cout << guess << " is wrong!\n";
      return;
    }
  }

  std::cout << "Nice! You have found all numbers. Good job!\n";
}

int main() { square_game(); }
