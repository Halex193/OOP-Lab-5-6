#include <utility>
#include <sstream>

//
// Created by Horatiu on 20-Mar-19.
//

#include "../headers/Tutorial.h"

Tutorial::Tutorial(string& title, string& presenter, Duration duration, int likes, string& link)
        : title(title), presenter(presenter), duration(duration), likes(likes),
          link(link)
{}

void Tutorial::like()
{
    likes++;
}

const string &Tutorial::getTitle() const
{
    return title;
}

const string &Tutorial::getPresenter() const
{
    return presenter;
}

const Duration &Tutorial::getDuration() const
{
    return duration;
}

int Tutorial::getLikes() const
{
    return likes;
}

const string &Tutorial::getLink() const
{
    return link;
}

bool Tutorial::operator==(const Tutorial &tutorial)
{
    return title == tutorial.title;
}

string Tutorial::toString()
{
    std::ostringstream stringStream;
    stringStream << title << " "
                 << presenter << " "
                 << duration.minutes << ":"
                 << duration.seconds << " "
                 << likes << " "
                 << link;
    return stringStream.str();
}
