//
// Created by Horatiu on 20-Mar-19.
//
#include <iostream>
#include <vector>
#include <sstream>
#include <limits>
#include "../headers/ConsoleUI.h"
#include "../headers/Tutorial.h"

using namespace std;

ConsoleUI::ConsoleUI(Controller &controller) : controller(controller)
{

}

void ConsoleUI::run()
{
    cout << "Master Java" << endl;
    cout << "Available commands: add, remove, update, list" << endl;

    while (true)
    {
        string command;
        cout << "> ";
        cin >> command;
        cinClear();
        if (command == "exit")
            break;
        try
        {
            if (command == "add")
            {
                string title = readString("Provide the title: ");
                string presenter = readString("Provide the presenter: ");
                Duration duration{};
                duration.minutes = readInt("Provide the number of minutes: ");
                duration.seconds = readInt("Provide the number of seconds: ");
                int likes = readInt("Provide the number of likes: ");
                string link = readString("Provide the link: ");
                controller.add(title, presenter, duration, likes, link);
                cout << "Tutorial added!" << endl;
            }
            else if (command == "remove")
            {
                string title = readString("Provide the title: ");
                controller.remove(title);
                cout << "Tutorial deleted!" << endl;
            }
            else if (command == "update")
            {
                string title = readString("Provide the title: ");
                string presenter = readString("Provide the presenter: ");
                Duration duration{};
                duration.minutes = readInt("Provide the number of minutes: ");
                duration.seconds = readInt("Provide the number of seconds: ");
                int likes = readInt("Provide the number of likes: ");
                string link = readString("Provide the link: ");
                controller.update(title, presenter, duration, likes, link);
                cout << "Tutorial updated!" << endl;
            }
            else if (command == "list")
            {
                const DynamicVector<Tutorial *> &tutorials = controller.list();
                if (tutorials.length() != 0)
                {
                    cout << "Tutorials: " << endl;
                    for (int i = 0; i < tutorials.length(); i++)
                    {
                        cout << tutorials.get(i)->toString() << endl;
                    }
                }
                else
                {
                    cout << "No tutorials to show" << endl;
                }
            }
            else
            {
                cout << "Command invalid!" << endl;
            }
        }
        catch (TutorialDoesNotExistException &exception)
        {
            cout << "The specified tutorial does not exist!" << endl;
        }
        catch (DuplicateTutorial &exception)
        {
            cout << "The specified tutorial already exists!" << endl;
        }
        catch (InvalidInput &exception)
        {
            cout << "Input invalid!" << endl;
        }
    }
}


string ConsoleUI::readString(const string& message)
{
    cout << message;
    string readString;
    if (!(getline(cin, readString)))
    {
        throw InvalidInput();
    }
    return readString;
}

int ConsoleUI::readInt(const string& message)
{
    cout << message;
    int readInt;
    if (!(cin >> readInt))
    {
        cinClear();
        throw InvalidInput();
    }
    cinClear();
    return readInt;
}

void ConsoleUI::cinClear()
{
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
