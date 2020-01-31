/**
 * Chapter P :: Question 7
 *
 * A simplified blackjack game,
 * with little OOP design...
 *
 * KoaLaYT  22:49 31/01/2020
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
    return rank + 2;
  if (rank == 12) // Ace
    return 11;
  return 10; // Jack, Queen, King
}

int extract_card(const Deck &deck) {
  static int index{0}; // next card to extract

  return get_card_value(deck[index++]);
}

bool has_overflow(int score) {
  if (score > 21) {
    std::cout << score << "! Overflowed!\n";
    return true;
  }
  return false;
}

bool player_hit(int score) {
  while (true) {
    std::cout << "Your current score is: " << score << '\n';
    std::cout << "Would you like to (h)it or (s)tand? ";

    char input{};
    std::cin >> input;

    if (input == 'h')
      return true;
    if (input == 's')
      return false;

    std::cout << "Please input 'h' or 's'!\n";
  }
}

bool play_blackjack() {
  // inital deck
  Deck deck{create_deck()};
  shuffle_deck(deck);

  int dealer_score{extract_card(deck)};
  int player_score{extract_card(deck)};
  player_score += extract_card(deck); // player begin with two cards
  if (has_overflow(player_score))
    return false; // 2 Ace make player immediate lose...

  bool player_stand{false}; // tracking if player has standed
  bool dealer_stand{false}; // tracking if dealer has standed
  while (true) {
    // player turn
    if (!player_stand) {
      const bool is_hit = player_hit(player_score);
      if (is_hit) {
        player_score += extract_card(deck);
        if (has_overflow(player_score))
          return false;
      } else {
        std::cout << "Player stand!\n";
        player_stand = true;
      }
    }
    // dealer turn
    if (!dealer_stand) {
      dealer_score += extract_card(deck);
      std::cout << "dealer score is " << dealer_score << '\n';
    }
    if (has_overflow(dealer_score)) {
      return true;
    }
    if (!dealer_stand && dealer_score > 17) {
      std::cout << "Dealer stand!\n";
      dealer_stand = true;
    }
    if (dealer_stand && player_stand) {
      return player_score > dealer_score;
    }
  }
}

int main() {
  const bool res = play_blackjack();

  if (res) {
    std::cout << "The player won!\n";
  } else {
    std::cout << "The dealer won!\n";
  }
}
