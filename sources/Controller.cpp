#include <utility>
#include <algorithm>

using namespace std;

//
// Created by Horatiu on 20-Mar-19.
//

#include "../headers/Controller.h"

Controller::Controller(Repository &repository) : repository(repository), tutorialIndex(0)
{
    populateRepository();
}

void Controller::add(const string &title, const string &presenter, Duration duration, int likes, const string &link)
{
    repository.add(new Tutorial(title, presenter, duration, likes, link));
}

const vector<Tutorial *> &Controller::list() const
{
    return repository.getTutorials();
}

void
Controller::update(const string &title, const string &presenter, Duration duration, int likes, const string &link)
{
    repository.update(new Tutorial(title, presenter, duration, likes, link));
}

void Controller::remove(const string &title)
{
    repository.remove(new Tutorial(title));
}

void Controller::populateRepository()
{
    repository.add(new Tutorial(
            "Learn Java 8 - Full Tutorial for Beginners",
            "Marcus Biel",
            Duration{572, 31},
            0,
            "https://www.youtube.com/watch?v=grEKMHGYyns"
    ));

    repository.add(new Tutorial(
            "Java Programming Tutorial - 17 - Constructors",
            "thenewboston",
            Duration{5, 45},
            0,
            "https://www.youtube.com/watch?v=tPFuVRbUTwA"
    ));

    repository.add(new Tutorial(
            "Java Programming",
            "Derek Banas",
            Duration{34, 29},
            0,
            "https://www.youtube.com/watch?v=WPvGqX-TXP0"
    ));

    repository.add(new Tutorial(
            "Java Tutorial",
            "Derek Banas",
            Duration{138, 42},
            0,
            "https://www.youtube.com/watch?v=n-xAqcBCws4"
    ));

    repository.add(new Tutorial(
            "Java Programming Tutorial - 27 - Introduction to Arrays",
            "thenewboston",
            Duration{7, 25},
            0,
            "https://www.youtube.com/watch?v=L06uGnF4IpY"
    ));

    repository.add(new Tutorial(
            "Learn Java Programming with Beginners Tutorial",
            "Guru99",
            Duration{35, 5},
            0,
            "https://www.youtube.com/watch?v=uWYPVz_i7W4"
    ));

    repository.add(new Tutorial(
            "Java Video Tutorial 14",
            "Derek Banas",
            Duration{13, 4},
            0,
            "https://www.youtube.com/watch?v=Lsdaztp3_lw"
    ));
    repository.add(new Tutorial(
            "Java Programming Tutorial 1 - Introduction to Java",
            "Caleb Curry",
            Duration{7, 35},
            7,
            "https://www.youtube.com/watch?v=2dZiMBwX_5Q"
    ));
    repository.add(new Tutorial(
            "Programming Flappy Bird in Java!",
            "jaryt Bustard",
            Duration{62, 56},
            15,
            "https://www.youtube.com/watch?v=I1qTZaUcFX0"
    ));
    repository.add(new Tutorial(
            "Learn Java in 1 minute!!!",
            "Udrea Horatiu",
            Duration{1, 0},
            1000,
            "https://www.youtube.com/watch?v=dQw4w9WgXcQ"
    ));
    repository.add(new Tutorial(
            "Tutorial",
            "No one",
            Duration{1, 1},
            1,
            "https://www.youtube.com/watch?v=QH2-TGUlwu4"
    ));


}

const Tutorial *Controller::next()
{
    const vector<Tutorial *> &tutorials = activeTutorials;
    Tutorial *tutorial = tutorials[tutorialIndex];
    tutorialIndex++;
    if (tutorialIndex == tutorials.size())
    {
        tutorialIndex = 0;
    }
    return tutorial;
}

bool Controller::addToWatchList(const Tutorial *tutorial)
{
    return repository.addToWatchList(tutorial);
}

bool Controller::begin(const string &presenter)
{
    const vector<Tutorial *> &tutorials = repository.getTutorials();
    if (presenter.empty())
    {
        activeTutorials = tutorials;
    }
    else
    {
        activeTutorials = vector<Tutorial *>{};
        copy_if(tutorials.begin(), tutorials.end(), back_inserter(activeTutorials),
                [presenter](const Tutorial *tutorial)
                { return tutorial->getPresenter() == presenter; }
        );
    }

    if (activeTutorials.empty())
    {
        return false;
    }
    tutorialIndex = 0;
    return true;
}

Tutorial *Controller::removeFromWatchList(const string &title)
{
    return repository.removeFromWatchList(title);
}

vector<Tutorial *> Controller::watchList()
{
    return repository.getWatchlist();
}
