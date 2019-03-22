//
// Created by Horatiu on 20-Mar-19.
//

#ifndef LAB5_6_CONSOLEUI_H
#define LAB5_6_CONSOLEUI_H


#include "Controller.h"

class ConsoleUI
{
private:
    Controller &controller;
public:
    explicit ConsoleUI(Controller &controller);

    void run();

    string readString();

    int readInt();

    void cinClear();

};


#endif //LAB5_6_CONSOLEUI_H
