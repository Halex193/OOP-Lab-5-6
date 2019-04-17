//
// Created by Horatiu on 20-Mar-19.
//

#include "../headers/Repository.h"
#include "../headers/exceptions.h"
#include <iostream>
#include <fstream>

Repository::Repository(const string &tutorialsFile) : tutorialsFile(tutorialsFile)
{
//    readTutorials();
}

const vector<Tutorial *> &Repository::getTutorials()
{
    readTutorials();
    return tutorials;
}

void Repository::add(Tutorial *tutorial)
{
    readTutorials();
    if (search(tutorial) != -1)
    {
        delete tutorial;
        throw DuplicateTutorial();
    }
    tutorials.push_back(tutorial);
    writeTutorials();
}

void Repository::update(Tutorial *tutorial)
{
    readTutorials();
    int tutorialIndex = search(tutorial);
    if (tutorialIndex == -1)
    {
        delete tutorial;
        throw TutorialDoesNotExistException();
    }
    delete tutorials[tutorialIndex];
    tutorials[tutorialIndex] = tutorial;
    writeTutorials();

}

void Repository::remove(Tutorial *tutorial)
{
    readTutorials();
    int tutorialIndex = search(tutorial);
    if (tutorialIndex == -1)
    {
        delete tutorial;
        throw TutorialDoesNotExistException();
    }
    delete tutorial;
    delete tutorials[tutorialIndex];
    tutorials.erase(tutorials.begin() + tutorialIndex);
    writeTutorials();
}

Tutorial *Repository::search(const string &tutorialTitle) const
{
    for (auto &tutorial : tutorials)
    {
        if (tutorial->getTitle() == tutorialTitle)
        {
            return tutorial;
        }
    }
    return nullptr;
}

int Repository::search(Tutorial *tutorial) const
{
    for (int i = 0; i < tutorials.size(); i++)
    {
        Tutorial *storedTutorial = tutorials[i];
        if (*storedTutorial == *tutorial)
        {
            return i;
        }
    }
    return -1;
}

const vector<Tutorial *> Repository::getWatchlist() const
{
    vector<Tutorial *> tutorialList{};
    for (const auto &title : watchlist)
    {
        Tutorial *tutorial = search(title);
        if (tutorial != nullptr)
        {
            tutorialList.push_back(tutorial);
        }
    }
    return tutorialList;
}

bool Repository::addToWatchList(const Tutorial *tutorial)
{
    for (const auto &title : watchlist)
    {
        if (title == tutorial->getTitle())
        {
            return false;
        }
    }
    watchlist.push_back(tutorial->getTitle());
    saveWatchList();
    return true;
}

Tutorial *Repository::removeFromWatchList(const string &title)
{
    for (int i = 0; i < watchlist.size(); i++)
    {
        if (watchlist[i] == title)
        {
            watchlist.erase(watchlist.begin() + i);
            Tutorial *searchedTutorial = new Tutorial(title);
            int index = search(searchedTutorial);
            delete searchedTutorial;
            saveWatchList();
            if (index != -1)
            {
                return tutorials[index];
            }
            return nullptr;
        }
    }
    return nullptr;
}

void Repository::readTutorials()
{
    ifstream inStream{tutorialsFile};
    bool c = inStream.is_open();
    destroyTutorials();
    Tutorial *tutorial = new Tutorial{string{}};
    while (inStream >> *tutorial)
    {
        tutorials.push_back(tutorial);
        tutorial = new Tutorial{string{}};
    }
    delete tutorial;
    inStream.close();
}

void Repository::writeTutorials() const
{
    ofstream outStream{tutorialsFile};
    for (auto &tutorial : tutorials)
    {
        outStream << *tutorial << "\n";
    }
    outStream.close();
}

void Repository::destroyTutorials()
{
    for (auto &tutorial : tutorials)
    {
        delete tutorial;
    }
    tutorials.clear();
}

void Repository::saveWatchList()
{

}

Repository::~Repository()
{
    destroyTutorials();
}
