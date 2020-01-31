/**
 * Chapter P :: Question 6
 *
 * a cpp version of card represent
 *
 * KoaLaYT  21:58 31/01/2020
 *
 */

#include <algorithm>
#include <array>
#include <ctime>
#include <iostream>
#include <random>

enum class CardSuit { Club, Diamond, Heart, Spade };

enum class CardRank {
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack,
  Queen,
  King,
  Ace
};

struct Card {
  CardSuit suit;
  CardRank rank;
};

using Deck = std::array<Card, 52>;

char get_rank(const Card &card) {
  switch (card.rank) {
  case CardRank::Two:
    return '2';
  case CardRank::Three:
    return '3';
  case CardRank::Four:
    return '4';
  case CardRank::Five:
    return '5';
  case CardRank::Six:
    return '6';
  case CardRank::Seven:
    return '7';
  case CardRank::Eight:
    return '8';
  case CardRank::Nine:
    return '9';
  case CardRank::Ten:
    return 'T';
  case CardRank::Jack:
    return 'J';
  case CardRank::Queen:
    return 'Q';
  case CardRank::King:
    return 'K';
  case CardRank::Ace:
    return 'A';
  }
}

char get_suit(const Card &card) {
  switch (card.suit) {
  case CardSuit::Club:
    return 'C';
  case CardSuit::Diamond:
    return 'D';
  case CardSuit::Heart:
    return 'H';
  case CardSuit::Spade:
    return 'S';
  }
}

void print_card(const Card &card) {
  const char rank = get_rank(card);
  const char suit = get_suit(card);

  std::cout << rank << suit;
}

Deck create_deck() {
  Deck deck{};

  for (int i{0}; i < std::size(deck); ++i) {
    const int suit = i / 13;
    const int rank = i % 13;
    deck[i] = {static_cast<CardSuit>(suit), static_cast<CardRank>(rank)};
  }

  return deck;
}

void print_deck(const Deck &deck) {
  for (auto &card : deck) {
    print_card(card);
    std::cout << ' ';
  }
  std::cout << '\n';
}

void shuffle_deck(Deck &deck) {
  static std::mt19937 mt{
      static_cast<std::mt19937::result_type>(std::time(nullptr))};

  std::shuffle(deck.begin(), deck.end(), mt);
}

int get_card_value(const Card &card) {
  const int rank = static_cast<int>(card.rank);
  if (rank <= 8) // 2 - 10
    return rank+2;
  if (rank == 12) // Ace
    return 11;
  return 10; // Jack, Queen, King
}

int main() {
  Deck deck = create_deck();

  shuffle_deck(deck);

  print_deck(deck);

  std::cout << "First card on deck is: ";
  print_card(deck[0]);
  std::cout << " -> " << get_card_value(deck[0]) << '\n';
}
