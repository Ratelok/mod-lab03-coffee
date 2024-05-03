// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

class AutomataTest : public ::testing::Test {
protected:
  Automata automata;
};

TEST_F(AutomataTest, Init) {}

TEST_F(AutomataTest, On) {
  automata.on();
}

TEST_F(AutomataTest, Off) {
  automata.on();
  automata.off();
}

TEST_F(AutomataTest, Coin) {
  automata.on();
  automata.coin();
}

TEST_F(AutomataTest, EtMenu) {
  automata.on();
  automata.etMenu();
}

TEST_F(AutomataTest, Choice) {
  automata.on();
  automata.coin();
  automata.choice(1);
}

TEST_F(AutomataTest, Check) {
  automata.on();
  automata.coin();
  automata.choice(1);
  automata.check();
}

TEST_F(AutomataTest, Cancel) {
  automata.on();
  automata.coin();
  automata.cancel();
}

TEST_F(AutomataTest, Cook) {
  automata.on();
  automata.coin();
  automata.choice(1);
  automata.check();
  automata.cook();
}

TEST_F(AutomataTest, Finish) {
  automata.on();
  automata.coin();
  automata.choice(1);
  automata.check();
  automata.cook();
  automata.finish();
}

