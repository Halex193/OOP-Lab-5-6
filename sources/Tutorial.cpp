#include <sstream>
#include "../headers/fileUtils.h"

//
// Created by Horatiu on 20-Mar-19.
//

#include "../headers/Tutorial.h"

Tutorial::Tutorial(const string &title, const string &presenter, Duration duration, int likes, const string &link)
        : title(title), presenter(presenter), duration(duration), likes(likes),
          link(link)
{}

Tutorial::Tutorial(const string &title) : title(title), presenter(string()), duration(Duration{0, 0}), likes(0),
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

ostream &operator<<(ostream &out, const Tutorial &tutorial)
{
    out << "\"" << tutorial.title << "\",\""
        << tutorial.presenter << "\","
        << tutorial.duration.minutes << ","
        << tutorial.duration.seconds << ","
        << tutorial.likes << ","
        << tutorial.link;
    return out;
}

istream &operator>>(istream &in, Tutorial &tutorial)
{
    string row;
    getline(in, row);
    if (row.empty())
    {
        in >> ws;
        return in;
    }
    vector<string> fields = readCSVRow(row);
    tutorial.title = fields[0];
    tutorial.presenter = fields[1];
    tutorial.duration.minutes = stoi(fields[2]);
    tutorial.duration.seconds = stoi(fields[3]);
    tutorial.likes = stoi(fields[4]);
    tutorial.link = fields[5];
    return in;
}
