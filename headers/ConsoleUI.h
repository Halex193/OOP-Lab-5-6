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

    static string readString(const string& message);

    static int readInt(const string& message);

    static void cinIgnore();

    void administratorUI();

    void userUI();
};


#endif //LAB5_6_CONSOLEUI_H
