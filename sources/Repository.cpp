//
// Created by Horatiu on 20-Mar-19.
//

#include "../headers/Repository.h"
#include "../headers/exceptions.h"

const vector<Tutorial *> &Repository::getTutorials() const
{
    return tutorials;
}

void Repository::add(Tutorial *tutorial)
{
    if (search(tutorial) != -1)
    {
        throw DuplicateTutorial();
    }
    tutorials.push_back(tutorial);
}

void Repository::update(Tutorial *tutorial)
{
    int tutorialIndex = search(tutorial);
    if (tutorialIndex == -1)
    {
        delete tutorial;
        throw TutorialDoesNotExistException();
    }
    delete tutorials[tutorialIndex];
    tutorials[tutorialIndex] = tutorial;

}

void Repository::remove(Tutorial *tutorial)
{
    int tutorialIndex = search(tutorial);
    if (tutorialIndex == -1)
    {
        delete tutorial;
        throw TutorialDoesNotExistException();
    }
    delete tutorial;
    delete tutorials[tutorialIndex];
    tutorials.erase(tutorials.begin() + tutorialIndex);
}

Repository::~Repository()
{
    for (auto &tutorial : tutorials)
    {
        delete tutorial;
    }
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

const vector<Tutorial*> Repository::getWatchlist() const
{
    vector<Tutorial*> tutorialList{};
    for (const auto &title : watchlist)
    {
        Tutorial *tutorial = new Tutorial(title);
        int index = search(tutorial);
        delete tutorial;
        tutorialList.push_back(tutorials[index]);
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
    return true;
}

Tutorial* Repository::removeFromWatchList(const string &title)
{
    for (int i = 0; i < watchlist.size(); i++)
    {
        if (watchlist[i] == title)
        {
            watchlist.erase(watchlist.begin() + i);
            Tutorial *searchedTutorial = new Tutorial(title);
            int index = search(searchedTutorial);
            delete searchedTutorial;
            if (index != -1)
            {
                return tutorials[index];
            }
            return nullptr;
        }
    }
    return nullptr;

}
