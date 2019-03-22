#include <utility>

using namespace std;

//
// Created by Horatiu on 20-Mar-19.
//

#include "../headers/Controller.h"

Controller::Controller(Repository &repository) : repository(repository)
{

}

void Controller::add(string &title, string &presenter, Duration duration, int likes, string &link)
{
    repository.add(new Tutorial(title, presenter, duration, likes, link));
}

const DynamicVector<Tutorial *> &Controller::list() const
{
    return repository.getTutorials();
}

void Controller::update(string &title, string &presenter, Duration duration, int likes, string &link)
{
    repository.update(new Tutorial(title, presenter, duration, likes, link));
}

void Controller::remove(string &title)
{
    string emptyString;
    repository.remove(new Tutorial(title, emptyString, Duration{0, 0}, 0, emptyString));
}
