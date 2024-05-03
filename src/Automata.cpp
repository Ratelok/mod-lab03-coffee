#include "Automata.h"

Automata::Automata() {
    cash = 0;
    menu = {"Чай", "Кофе", "Молоко"};
    prices = {10, 15, 20};
    state = STATES::OFF;
}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        std::cout << "Включено" << std::endl;
    }
}

void Automata::off() {
    if (state != STATES::OFF) {
        state = STATES::OFF;
        std::cout << "Выключено" << std::endl;
    }
}

void Automata::coin() {
    if (state == STATES::WAIT) {
        cash += 10;
        std::cout << "Монета принята" << std::endl;
        state = STATES::ACCEPT;
    }
}

void Automata::etMenu() {
    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        std::cout << "Меню:" << std::endl;
        for (int i = 0; i < menu.size(); i++) {
            std::cout << i + 1 << ". " << menu[i] << " - " << prices[i] << " руб." << std::endl;
        }
    }
}

STATES Automata::getState() {
    return state;
}

void Automata::choice() {
    if (state == STATES::ACCEPT) {
        int choice;
        std::cout << "Выберите напиток (1-" << menu.size() << "): ";
        std::cin >> choice;
        if (choice > 0 && choice <= menu.size()) {
            if (cash >= prices[choice - 1]) {
                cash -= prices[choice - 1];
                state = STATES::CHECK;
            } else {
                std::cout << "Недостаточно средств" << std::endl;
            }
        } else {
            std::cout << "Неверный выбор" << std::endl;
        }
    }
}

void Automata::check() {
    if (state == STATES::CHECK) {
        if (cash > 0) {
            std::cout << "Сдача: " << cash << " руб." << std::endl;
        }
        state = STATES::COOK;
    }
}

void Automata::cancel() {
    if (state == STATES::WAIT || state == STATES::ACCEPT || state == STATES::CHECK) {
        cash = 0;
        state = STATES::WAIT;
        std::cout << "Операция отменена" << std::endl;
    }
}

void Automata::cook() {
    if (state == STATES::COOK) {
        std::cout << "Напиток готовится..." << std::endl;
        state = STATES::FINISH;
    }
}

void Automata::finish() {
    if (state == STATES::FINISH) {
        std::cout << "Напиток готов" << std::endl;
        state = STATES::WAIT;
    }
}
