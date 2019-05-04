//
// Created by Horatiu on 20-Mar-19.
//
#include <iostream>
#include <vector>
#include <sstream>
#include <limits>
#include "../headers/ConsoleUI.h"
#include "../headers/Tutorial.h"
#include "../headers/exceptions.h"

using namespace std;

ConsoleUI::ConsoleUI(Controller &controller) : UI(controller){}

void ConsoleUI::run(int argc, char **argv)
{
    cout << "Master Java" << endl;
    bool modeValid = false;
    while (!modeValid)
    {
        cout << "Choose mode: user or admin: ";
        string mode;
        cin >> mode;
        if (mode == "exit")
        {
            return;
        }
        else if (mode == "user")
        {
            userUI();
            modeValid = true;
        }
        else if (mode == "admin")
        {
            administratorUI();
            modeValid = true;
        }
        else
        {
            cout << "Mode invalid!" << endl;
        }
    }

}

void ConsoleUI::userUI()
{
    cout << "User interface. Available commands: tutorials, watchlist, remove" << endl;

    while (true)
    {
        string command;
        cout << "> ";
        cin >> command;
        cinIgnore();
        if (command == "exit")
            return;
        try
        {
            if (command == "tutorials")
            {
                string presenter = readString("Choose the name of the presenter (blank for every tutorial): ");
                if (!controller.begin(presenter))
                {
                    cout << "Tutorial list is empty!" << endl;
                }
                else
                {
                    while (true)
                    {
                        const Tutorial *tutorial = controller.next();
                        cout << tutorial->toString() << endl << endl;
                        controller.show(tutorial);
                        string watch = readString("Type 'watch' if you want to add the video to the watchlist: ");
                        if (watch == "watch")
                        {
                            if(controller.addToWatchList(tutorial))
                            {
                                cout << "Tutorial was added to the watchlist" << endl;
                            }
                            else
                            {
                                cout << "Tutorial is already on the watchlist" << endl;
                            }
                        }
                        else
                        {
                            cout << "Tutorial was not added to the watchlist" << endl;
                        }
                        string exit = readString("Type 'exit' to return to the menu: ");
                        if (exit == "exit")
                        {
                            break;
                        }
                        cout << endl;
                    }
                }
            }
            else if (command == "remove")
            {
                string title = readString("Choose the title of the video to remove from the watchlist: ");
                Tutorial *tutorial = controller.removeFromWatchList(title);
                if (tutorial != nullptr)
                {
                    string like = readString("If you liked the tutorial, type 'like': ");
                    if (like == "like")
                    {
                        tutorial->like();
                    }
                }
                else
                {
                    cout << "Tutorial does not exist in te watchlist!" << endl;
                }
            }
            else if (command == "watchlist")
            {
                const vector<Tutorial *> &tutorials = controller.watchList();
                if (!tutorials.empty())
                {
                    cout << "Tutorials on watch list: " << endl;
                    for (auto tutorial : tutorials)
                    {
                        cout << tutorial->toString() << endl;
                    }
                    controller.showWatchList();
                }
                else
                {
                    cout << "No tutorials on the watch list" << endl;
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
        catch (InvalidInput &exception)
        {
            cout << "Input invalid!" << endl;
        }
    }
}

void ConsoleUI::administratorUI()
{
    cout << "Admin interface. Available commands: add, remove, update, list" << endl;

    while (true)
    {
        string command;
        cout << "> ";
        cin >> command;
        cinIgnore();
        if (command == "exit")
            return;
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
                const vector<Tutorial *> &tutorials = controller.list();
                if (!tutorials.empty())
                {
                    cout << "Tutorials: " << endl;
                    for (auto tutorial : tutorials)
                    {
                        cout << tutorial->toString() << endl;
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


string ConsoleUI::readString(const string &message)
{
    cout << message;
    string readString;
    if (!(getline(cin, readString)))
    {
        cin.clear();
        throw InvalidInput();
    }
    return readString;
}

int ConsoleUI::readInt(const string &message)
{
    cout << message;
    int readInt;
    if (!(cin >> readInt))
    {
        cin.clear();
        cinIgnore();
        throw InvalidInput();
    }
    cinIgnore();
    return readInt;
}

void ConsoleUI::cinIgnore()
{
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

