#include <utility>
#include <sstream>
#include <windows.h>

//
// Created by Horatiu on 20-Mar-19.
//

#include "../headers/Tutorial.h"

Tutorial::Tutorial(const string& title, const string& presenter, Duration duration, int likes, const string& link)
        : title(title), presenter(presenter), duration(duration), likes(likes),
          link(link)
{}

Tutorial::Tutorial(const string& title): title(title), presenter(string()), duration(Duration{0, 0}), likes(0),
        link(string())
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

string Tutorial::toString() const
{
    std::ostringstream stringStream;
    stringStream << title << " | "
                 << presenter << " | "
                 << duration.minutes << ":"
                 << duration.seconds << " | "
                 << likes << " | "
                 << link;
    return stringStream.str();
}

void Tutorial::show() const
{
    ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe", this->link.c_str(), NULL, SW_SHOWMAXIMIZED);
}
