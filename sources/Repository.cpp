//
// Created by Horatiu on 20-Mar-19.
//

#include "../headers/Repository.h"

const DynamicVector<Tutorial *> &Repository::getTutorials() const
{
    return tutorials;
}

void Repository::add(Tutorial *tutorial)
{
    if (search(tutorial) != -1)
    {
        throw DuplicateTutorial();
    }
    tutorials = tutorial + tutorials;
}

void Repository::update(Tutorial *tutorial)
{
    int tutorialIndex = search(tutorial);
    if (tutorialIndex == -1)
    {
        delete tutorial;
        throw TutorialDoesNotExistException();
    }
    delete tutorials.get(tutorialIndex);
    tutorials.set(tutorial, tutorialIndex);

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
    delete tutorials.get(tutorialIndex);
    tutorials.remove(tutorialIndex);
}

Repository::~Repository()
{
    for (int i = 0; i < tutorials.length(); i++)
    {
        delete tutorials.get(i);
    }
}

int Repository::search(Tutorial *tutorial) const
{
    for (int i = 0; i < tutorials.length(); i++)
    {
        Tutorial *storedTutorial = tutorials.get(i);
        if (*storedTutorial == *tutorial)
        {
            return i;
        }
    }
    return -1;
}

const DynamicVector<Tutorial*> Repository::getWatchlist() const
{
    DynamicVector<Tutorial*> tutorialList{};
    for (int i = 0; i < watchlist.length(); i++)
    {
        Tutorial *tutorial = new Tutorial(watchlist.get(i));
        int index = search(tutorial);
        delete tutorial;
        tutorialList = tutorialList + tutorials.get(index);
    }
    return tutorialList;
}

bool Repository::addToWatchList(const Tutorial *tutorial)
{
    for (int i = 0; i < watchlist.length(); i++)
    {
        if (watchlist.get(i) == tutorial->getTitle())
        {
            return false;
        }
    }
    watchlist = watchlist + tutorial->getTitle();
    return true;
}

Tutorial* Repository::removeFromWatchList(const string &title)
{
    for (int i = 0; i < watchlist.length(); i++)
    {
        if (watchlist.get(i) == title)
        {
            watchlist.remove(i);
            Tutorial *searchedTutorial = new Tutorial(title);
            int index = search(searchedTutorial);
            delete searchedTutorial;
            if (index != -1)
            {
                return tutorials.get(i);
            }
            return nullptr;
        }
    }
    return nullptr;

}
