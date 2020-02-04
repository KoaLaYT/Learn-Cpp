#ifndef PLAYER_H_20200203
#define PLAYER_H_20200203

#include "Creature.h"
#include "Monster.h"

constexpr int WonLevel{20};

class Player : public Creature {
public:
  Player(const std::string &name) : Creature{name, '@', 10, 1, 0}, m_level{1} {}

  int getLevel() const { return m_level; }

  void levelUp() {
    m_level += 1;
    m_damage += 1;
  }

  bool hasWon() { return m_level == WonLevel; }

  void fightMonster();

  void attackMonster(Monster &m);

  void attackByMonster(Monster &m);

private:
  int m_level;
};

#endif
