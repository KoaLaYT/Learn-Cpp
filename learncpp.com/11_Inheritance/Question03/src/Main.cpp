/**
 * Chapter 11 :: Question 3
 *
 * Fighting with a monster
 * use almost everything learned by bar
 *
 * KoaLaYT  23:15  04/02/2020
 *
 */

#include "Player.h"
#include <iostream>
#include <string>

Player initPlayer() {
  std::cout << "Enter you name: ";
  std::string name{};
  std::getline(std::cin, name);

  std::cout << "Welcome, " << name << '\n';

  return Player{name};
}

int main() {
  Player p{initPlayer()};

  while (!(p.hasWon() || p.isDead())) {
    p.fightMonster();
  }

  if (p.hasWon()) {
    std::cout << "You won! And you have " << p.getGold() << " golds!\n";
  }
  if (p.isDead()) {
    std::cout << "You died at level " << p.getLevel() << " and with "
              << p.getGold() << " gold.\n";
    std::cout << "Too bad you can't take it with you!\n";
  }
  return 0;
}
