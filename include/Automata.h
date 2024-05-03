#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <iostream>
#include <vector>
#include <string>

enum class STATES { OFF, WAIT, ACCEPT, CHECK, COOK, FINISH };

class Automata {
public:
    Automata();
    void on();
    void off();
    void coin();
    void etMenu();
    STATES getState();
    void choice();
    void check();
    void cancel();
    void cook();
    void finish();
private:
    int cash;
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES state;
};

#endif // AUTOMATA_H
