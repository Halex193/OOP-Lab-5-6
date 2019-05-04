//
// Created by Horatiu on 20-Mar-19.
//

#ifndef LAB5_6_CONSOLEUI_H
#define LAB5_6_CONSOLEUI_H


#include "Controller.h"
#include "UI.h"

class ConsoleUI : public UI
{
public:

    explicit ConsoleUI(Controller &controller);

    void run(int argc, char **argv) override;

    static string readString(const string &message);

    static int readInt(const string &message);

    static void cinIgnore();

    void administratorUI();

    void userUI();
};


#endif //LAB5_6_CONSOLEUI_H
