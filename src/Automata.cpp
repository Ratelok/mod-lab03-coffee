#include "Automata.h"
#include <iostream>

Automata::Automata() : cash(0), state(STATES::OFF) {
  // Загрузка меню и цен (замените на подгрузку из файла)
  menu = {"Чай", "Кофе", "Молоко"};
  prices = {10, 15, 20};
}

void Automata::on() {
  if (state == STATES::OFF) {
    state = STATES::ON;
    std::cout << "Автомат включен!" << std::endl;
  }
}

void Automata::off() {
  if (state != STATES::OFF) {
    state = STATES::OFF;
    std::cout << "Автомат выключен!" << std::endl;
  }
}

void Automata::coin(int amount) {
  if (state == STATES::ON) {
    cash += amount;
    std::cout << "Внесено: " << amount << ". Текущий баланс: " << cash << std::endl;
  }
}

std::vector<std::string> Automata::getMenu() {
  return menu;
}

STATES Automata::getState() {
  return state;
}

void Automata::choice(int option) {
  if (state == STATES::ON && option >= 0 && option < menu.size()) {
    state = STATES::CHOICE;
    std::cout << "Выбран напиток: " << menu[option] << std::endl;
  }
}

bool Automata::check() {
  if (state == STATES::CHOICE) {
    if (cash >= prices[option]) {
      state = STATES::COOK;
      std::cout << "Достаточно средств. Приготовление..." << std::endl;
      return true;
    } else {
      std::cout << "Недостаточно средств!" << std::endl;
      return false;
    }
  }
  return false;
}

void Automata::cancel() {
  if (state != STATES::OFF) {
    std::cout << "Операция отменена. Возврат средств: " << cash << std::endl;
    cash = 0;
    state = STATES::ON;
  }
}

void Automata::cook() {
  if (state == STATES::COOK) {
    // Имитация приготовления
    std::cout << "Напиток готов!" << std::endl;
    state = STATES::OFF;;
  }
}

void Automata::finish() {
  if (state == STATES::OFF) {
    std::cout << "Спасибо за покупку!" << std::endl;
    cash = 0;
    state = STATES::ON;
  }
}
