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
  automata.coin();
  automata.choice(1);
  ASSERT_EQ(automata.getState(), STATES::CHECK);
}

TEST_F(AutomataTest, Check) {
  automata.coin();
  automata.choice(1);
  automata.check();
  ASSERT_EQ(automata.getState(), STATES::COOK);
}

TEST_F(AutomataTest, Cancel) {
  automata.on();
  automata.coin();
  automata.cancel();
}

TEST_F(AutomataTest, Cook) {
  automata.coin();
  automata.choice(1);
  automata.check();
  automata.cook();
  ASSERT_EQ(automata.getState(), STATES::FINISH);
}


TEST_F(AutomataTest, Finish) {
  automata.coin();
  automata.choice(1);
  automata.check();
  automata.cook();
  automata.finish();
  ASSERT_EQ(automata.getState(), STATES::WAIT);
}
