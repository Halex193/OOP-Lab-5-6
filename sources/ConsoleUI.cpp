//
// Created by Horatiu on 20-Mar-19.
//
#include <iostream>
#include "../headers/ConsoleUI.h"
#include "../headers/Tutorial.h"

using namespace std;

ConsoleUI::ConsoleUI(Controller &controller) : controller(controller)
{

}

void ConsoleUI::run()
{
    cout << "Master Java" << endl;
}
