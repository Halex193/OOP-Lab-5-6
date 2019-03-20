#include <utility>
using namespace std;

//
// Created by Horatiu on 20-Mar-19.
//

#include "../headers/Controller.h"

Controller::Controller(Repository &repository) : repository(repository)
{

}

void Controller::add(string title, string presenter, Duration duration, int likes, string link)
{
    repository.add(new Tutorial(move(title), move(presenter), duration, likes, move(link)));
}

const DynamicVector<Tutorial *> & Controller::list()
{
    return repository.getTutorials();
}

void Controller::update(string title, string presenter, Duration duration, int likes, string link)
{
    repository.update(new Tutorial(move(title), move(presenter), duration, likes, move(link)));
}

void Controller::remove(string title)
{
    repository.remove(new Tutorial(move(title), "", Duration{0,0}, 0, ""));
}
