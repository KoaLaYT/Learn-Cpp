#include "Player.h"
#include "Monster.h"
#include <iostream>

char getChoice() {
  while (true) {
    std::cout << "(R)un or (F)ight: ";
    char input{};

    std::cin >> input;

    if (input == 'r' || input == 'R') {
      return 'r';
    }
    if (input == 'f' || input == 'F') {
      return 'f';
    }
  }
}

bool takeChance() {
  int chance = Random::get(0, 1);
  if (chance) {
    std::cout << "You failed to flee.\n";
    return false;
  } else {
    std::cout << "You successfully fled.\n";
    return true;
  }
}

void claimVictory(Player &p, Monster &m) {
  std::cout << "You killed the " << m.getName() << ".\n";
  p.levelUp();
  std::cout << "You are now level " << p.getLevel() << ".\n";
  p.addGold(m.getGold());
  std::cout << "You found " << m.getGold() << " gold.\n";
  return;
}

void Player::fightMonster() {
  Monster m{Monster::getRandomMonster()};
  std::cout << "You have encountered a " << m.getName() << " (" << m.getSymbol()
            << ").\n";

  while (true) {
    char choice{getChoice()};
    if (choice == 'r') {
      bool canRun{takeChance()};
      if (!canRun) {
        attackByMonster(m);
      }
      if (isDead() || canRun) {
        // this round is over
        return;
      }
    } else if (choice == 'f') {
      attackMonster(m);
      if (m.isDead()) {
        claimVictory(*this, m);
        return;
      } else {
        attackByMonster(m);
        if (isDead()) {
          return;
        }
      }
    }
  }
}

void Player::attackMonster(Monster &m) {
  std::cout << "You hit the " << m.getName() << " for " << getDamage()
            << " damage.\n";

  m.reduceHealth(getDamage());

  return;
}

void Player::attackByMonster(Monster &m) {
  std::cout << "The " << m.getName() << " hit you for " << m.getDamage()
            << " damage.\n";

  reduceHealth(m.getDamage());

  return;
}
