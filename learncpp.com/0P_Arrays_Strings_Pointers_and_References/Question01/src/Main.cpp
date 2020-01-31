/**
 * Chapter P :: Question 1
 *
 * Simple usage about enum and std::array
 *
 * KoaLaYT  20:30 31/01/2020
 *
 */

#include <array>
#include <iostream>
#include <numeric>

namespace Item {
enum { Health_Potion, Torch, Arrow, Max_Items };
}

using Inventory_t = std::array<int, Item::Max_Items>;

int count_total_items(const Inventory_t &items) {
  return std::reduce(items.begin(), items.end());
}

int main() {
  Inventory_t items{2, 5, 10};

  std::cout << "The player has " << count_total_items(items)
            << " items in total\n";
  std::cout << "And has " << items[Item::Torch] << " torches\n";
}
