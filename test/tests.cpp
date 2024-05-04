// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"


TEST(AutomataTest, CoinTest) {
  Automata automata;
  automata.on();
  automata.coin(50);
  EXPECT_EQ(automata.getState(), STATES::ON);
  EXPECT_EQ(automata.cash, 50);
}

// Тест на корректное чтение меню
TEST(AutomataTest, GetMenu) {
  Automata automata;
  automata.on();
  std::string expectedMenu = "1. Чай - 10\n2. Кофе - 15\n3. Молоко - 20\n";

  // Вариант 2: Преобразование вектора в строку
  std::string actualMenu;
  for (const auto& item : automata.getMenu()) {
    actualMenu += item;
  }
  EXPECT_EQ(actualMenu, expectedMenu);
}

// Тест на проверку наличия достаточной суммы (успех)
TEST(AutomataTest, CheckEnough) {
  Automata automata;
  automata.on();
  automata.coin(20);
  EXPECT_TRUE(automata.check(15));
}

// Тест на проверку наличия достаточной суммы (неудача)
TEST(AutomataTest, CheckNotEnough) {
  Automata automata;
  automata.on();
  automata.coin(10);
  EXPECT_FALSE(automata.check(15));
}

// Тест на отмену сеанса и возврат средств
TEST(AutomataTest, Cancel) {
  Automata automata;
  automata.on();
  automata.coin(25);
  automata.cancel();
  EXPECT_EQ(automata.getCash(), 0);
  EXPECT_EQ(automata.getState(), STATES::OFF);
}

// Тест на имитацию процесса приготовления напитка
TEST(AutomataTest, Cook) {
  Automata automata;
  automata.on();
  automata.coin(15);
  automata.choice(2);
  automata.cook();
  EXPECT_EQ(automata.getState(), STATES::READY);
}

// Тест на завершение обслуживания и переход в состояние OFF
TEST(AutomataTest, Finish) {
  Automata automata;
  automata.on();
  automata.coin(10);
  automata.choice(1);
  automata.cook();
  automata.finish();
  EXPECT_EQ(automata.getState(), STATES::OFF);
}