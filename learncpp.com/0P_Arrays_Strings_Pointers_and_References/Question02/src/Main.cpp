/**
 * Chapter P :: Question 2
 *
 * Prompt user to input student infos,
 * and then list them by grade.
 *
 * KoaLaYT  20:56 31/01/2020
 *
 */

#include <iostream>
#include <limits>
#include <vector>

struct Student {
  std::string name;
  int grade;
};

int get_number() {
  while (true) {
    std::cout << "How many students would you like to enter? ";

    int input{};
    std::cin >> input;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Please input an integer!\n";
    } else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if (input <= 0) {
        std::cout << "Please input an POSITIVE integer!\n";
      } else {
        return input;
      }
    }
  }
}

std::string get_name(int index) {
  std::cout << "Student #" << index+1 << " name: ";
  std::string name{};
  std::getline(std::cin, name);

  return name;
}

int get_grade(int index) {
  while (true) {
    std::cout << "Student #" << index+1 << " grade (0 - 100): ";

    int input{};
    std::cin >> input;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Please input an integer!\n";
    } else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if (input < 0 || input > 100) {
        std::cout << "Please input an integer between 0 to 100\n";
      } else {
        return input;
      }
    }
  }
}

void get_students(std::vector<Student> &students, int size) {
  for (int i{0}; i < size; ++i) {
    students[i].name = get_name(i);
    students[i].grade = get_grade(i);
  }
}

bool sort_by_grade(const Student &s1, const Student &s2) { return s1.grade > s2.grade; }

void print_students(const std::vector<Student> &students) {
  std::cout << '\n';
  for (auto &s : students) {
    std::cout << s.name << " got a grade of " << s.grade << '\n';
  }
}

int main() {
  int nums{get_number()};

  std::vector<Student> students(nums);

  get_students(students, nums);

  std::sort(students.begin(), students.end(), sort_by_grade);

  print_students(students);
}
