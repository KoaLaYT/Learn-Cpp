#include <cmath>
#include <iostream>
#include <string>

#include "HelloConfig.h"
#ifdef USE_MYMATH
#include "MathFunctions/MathFunctions.h"
#endif

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Please input a positive number\n";
    return 1;
  }
  std::cout << "hello, world\n";
  std::cout << "version: " << Hello_VERSION_MAJOR << '.' << Hello_VERSION_MINOR
            << '\n';

  double input = std::stod(argv[1]);

#ifdef USE_MYMATH
  double result = mysqrt(input);
#else
  double result = std::sqrt(input);
#endif

  std::cout << "The root of " << input << " is " << result << '\n';
}
