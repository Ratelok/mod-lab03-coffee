// Copyright 2023 Fedorov
#ifndef INCLUDE_AUTOMATA_H_
#define AUTOMATA_H

#include <string>
#include <vector>

enum class STATES { OFF, ON, COIN, CHOICE, COOK, READY };

class Automata {
 public:
  Automata();
  void on();
  void off();
  void coin(int amount);
  std::vector<std::string> getMenu();
  STATES getState();
  void choice(int option);
  bool check(int price);
  void cancel();
  void cook();
  void finish();
  int getCash() const { return cash; }
  STATES getState() const { return state; }

 private:
  int cash;
  int option;
  std::vector<std::string> menu;
  std::vector<int> prices;
  STATES state;
};

#endif // INCLUDE_AUTOMATA_H_
