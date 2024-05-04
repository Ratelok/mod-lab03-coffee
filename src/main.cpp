#include "Automata.h"
#include <iostream>

int main() {
  Automata automata;
  automata.on();
  automata.coin(50);
  for (const auto& item : automata.getMenu()) {
    std::cout << item << std::endl;
  }
  automata.choice(1);
  automata.check(15);
  automata.cook();
  automata.finish();
  automata.off();
  return 0;
}
