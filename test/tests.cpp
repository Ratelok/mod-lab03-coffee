// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, Init) {
    Automata automata;
    ASSERT_EQ(automata.getState(), STATES::OFF);
}

TEST(AutomataTest, On) {
    Automata automata;
    automata.on();
    ASSERT_EQ(automata.getState(), STATES::WAIT);
}

TEST(AutomataTest, Off) {
    Automata automata;
    automata.on();
    automata.off();
    ASSERT_EQ(automata.getState(), STATES::OFF);
}

TEST(AutomataTest, Coin) {
    Automata automata;
    automata.on();
    automata.coin();
    ASSERT_EQ(automata.getState(), STATES::ACCEPT);
}

TEST(AutomataTest, EtMenu) {
    Automata automata;
    automata.on();
    automata.etMenu();
    ASSERT_EQ(automata.getState(), STATES::WAIT);
}

TEST(AutomataTest, Choice) {
    Automata automata;
    automata.on();
    automata.coin();
    automata.coin();
    automata.choice();
    ASSERT_EQ(automata.getState(), STATES::CHECK);
}

TEST(AutomataTest, Check) {
    Automata automata;
    automata.on();
    automata.coin();
    automata.coin();
    automata.choice();
    automata.check();
    ASSERT_EQ(automata.getState(), STATES::COOK);
}

TEST(AutomataTest, Cancel) {
    Automata automata;
    automata.on();
    automata.coin();
    automata.cancel();
    ASSERT_EQ(automata.getState(), STATES::WAIT);
}

TEST(AutomataTest, Cook) {
    Automata automata;
    automata.on();
    automata.coin();
    automata.coin();
    automata.choice();
    automata.check();
    automata.cook();
    ASSERT_EQ(automata.getState(), STATES::FINISH);
}

TEST(AutomataTest, Finish) {
    Automata automata;
    automata.on();
    automata.coin();
    automata.coin();
    automata.choice();
    automata.check();
    automata.cook();
    automata.finish();
    ASSERT_EQ(automata.getState(), STATES::WAIT);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
