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
    tutorials.add(tutorial);
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
