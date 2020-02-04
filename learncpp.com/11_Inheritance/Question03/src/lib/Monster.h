#ifndef MONSTER_H_20200204
#define MONSTER_H_20200204

#include "Creature.h"
#include "random.h"
#include <array>
#include <string_view>

using Random = effolkronium::random_static;

class Monster : public Creature {
public:
  enum Type {
    DRAGON,
    ORC,
    SLIME,

    MAX_TYPES
  };

  Monster(Type type)
      : Creature{monsterData[type].name.data(), monsterData[type].symbol,
                 monsterData[type].health, monsterData[type].damage,
                 monsterData[type].gold} {}

  static Monster getRandomMonster() {
    return {static_cast<Type>(Random::get(0, Type::MAX_TYPES - 1))};
  }

private:
  struct MonsterData {
    std::string_view name;
    char symbol;
    int health;
    int damage;
    int gold;
  };

  static constexpr std::array<MonsterData, Type::MAX_TYPES> monsterData{
      {{"dragon", 'D', 20, 4, 100},
       {"orc", 'o', 4, 2, 25},
       {"slime", 's', 1, 1, 10}}};
};

#endif
