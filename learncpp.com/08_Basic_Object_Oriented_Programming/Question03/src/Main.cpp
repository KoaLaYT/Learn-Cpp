/**
 * Chapter 8 :: Question 3
 *
 * a monster class: practice static member functions
 *
 * KoaLaYT  14:41  02/02/2020
 *
 */

#include "Monster.h"
#include <cstdlib>

int main() {
  std::srand(static_cast<unsigned int>(time(0)));

  Monster skele{MonsterGenerator::gen_monster()};
  skele.print();

  return 0;
}
