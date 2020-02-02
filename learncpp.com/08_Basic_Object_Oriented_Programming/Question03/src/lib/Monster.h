#ifndef MONSTER_H_20200202
#define MONSTER_H_20200202

#include <cstdlib>
#include <iostream>
#include <string>

class Monster {
public:
  enum MonsterType {
    Dragon,
    Goblin,
    Ogre,
    Orc,
    Skeleton,
    Troll,
    Vampire,
    Zombie,

    MAX_MONSTER_TYPES
  };

  Monster() = delete;
  Monster(MonsterType type, std::string name, std::string roar, int hit_points)
      : m_type{type}, m_name{name}, m_roar{roar}, m_hit_points{hit_points} {}

  std::string get_type() {
    switch (m_type) {
    case Dragon:
      return "dragon";
    case Goblin:
      return "goblin";
    case Ogre:
      return "ogre";
    case Orc:
      return "orc";
    case Skeleton:
      return "skeleton";
    case Troll:
      return "troll";
    case Vampire:
      return "vampire";
    case Zombie:
      return "zombie";
    default:
      return "???";
    }
  }

  void print() {
    std::cout << m_name << " the " << get_type() << " has " << m_hit_points
              << " hit points, and says " << m_roar << '\n';
  }

private:
  MonsterType m_type;
  std::string m_name;
  std::string m_roar;
  int m_hit_points;
};

class MonsterGenerator {
public:
  static Monster gen_monster() {
    std::rand();
    Monster::MonsterType type{static_cast<Monster::MonsterType>(
        get_random_number(0, Monster::MAX_MONSTER_TYPES - 1))};
    int hit_points = get_random_number(1, 100);

    static std::string s_names[] = {"Koalayt", "Amen", "Max",
                                    "Ginger",  "Abed", "Burning"};
    static std::string s_roars[] = {
        "*RUA*", "*Ceeeeeb*", "*You know what cooking*",
        "*Ah*",  "*Pub*",     "*Loser*"};

    std::string name = s_names[get_random_number(0, 5)];
    std::string roar = s_roars[get_random_number(0, 5)];
    return Monster{type, name, roar, hit_points};
  }

private:
  // Generate a random number between min and max (inclusive)
  // Assumes srand() has already been called
  static int get_random_number(int min, int max) {
    static const double fraction =
        1.0 /
        (static_cast<double>(RAND_MAX) +
         1.0); // static used for efficiency, so we only calculate this value
               // once evenly distribute the random number across our range
    return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
  }
};

#endif

