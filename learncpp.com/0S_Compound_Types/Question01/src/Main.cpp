/**
 * Chapter S :: Question 1
 *
 * build a user defined type `Monster` by using:
 * a enum class type,
 * and a struct.
 *
 * KoaLaYT  18:48 30/01/2020
 *
 */

#include <iostream>
#include <string>
#include <string_view>

enum class MonsterType { Ogre, Dragon, Orc, Giant_Spider, Slime };

struct Monster {
  MonsterType type;
  std::string name;
  int health;
};

std::string_view get_monster_type(const Monster &m) {
  switch (m.type) {
  case MonsterType::Ogre:
    return "Ogre";
  case MonsterType::Dragon:
    return "Dragon";
  case MonsterType::Orc:
    return "Orc";
  case MonsterType::Giant_Spider:
    return "Giant Spider";
  case MonsterType::Slime:
    return "Slime";
  default:
    return "???";
  }
}

void print_monster(const Monster &m) {
  std::cout << "This " << get_monster_type(m) << " is named " << m.name
            << " and has " << m.health << " health.\n";
}

int main() {
  const Monster m1{MonsterType::Ogre, "Torg", 145};
  const Monster m2{MonsterType::Slime, "Blurp", 23};

  print_monster(m1);
  print_monster(m2);

  return 0;
}
