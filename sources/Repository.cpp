//
// Created by Horatiu on 20-Mar-19.
//

#include "../headers/Repository.h"

const DynamicVector<Tutorial*> &Repository::getTutorials() const
{
    return tutorials;
}

void Repository::add(Tutorial *tutorial)
{
    tutorials.add(tutorial);
}

void Repository::update(Tutorial *tutorial)
{
    for (int i = 0; i < tutorials.length(); i++)
    {
        Tutorial *storedTutorial = tutorials.get(i);
        if (*storedTutorial == *tutorial)
        {
            delete storedTutorial;
            tutorials.set(tutorial, i);
            return;
        }
    }
    delete tutorial;
    throw TutorialDoesNotExistException();
}

void Repository::remove(Tutorial *tutorial)
{
    for (int i = 0; i < tutorials.length(); i++)
    {
        Tutorial *storedTutorial = tutorials.get(i);
        if (*storedTutorial == *tutorial)
        {
            delete storedTutorial;
            tutorials.remove(i);
            delete tutorial;
            return;
        }
    }
    delete tutorial;
    throw TutorialDoesNotExistException();
}
