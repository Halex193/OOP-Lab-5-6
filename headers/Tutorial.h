//
// Created by Horatiu on 20-Mar-19.
//

#ifndef LAB5_6_TUTORIAL_H
#define LAB5_6_TUTORIAL_H

#include <string>

using namespace std;
struct Duration
{
    int minutes;
    int seconds;

};

class Tutorial
{
private:
    string title;
    string presenter;
    Duration duration;
    int likes;
    string link;
public:
    Tutorial(string& title, string& presenter, Duration duration, int likes, string& link);

    /**
     * Increases the number of likes by one
     */
    void like();

    const string &getTitle() const;

    const string &getPresenter() const;

    const Duration &getDuration() const;

    int getLikes() const;

    const string &getLink() const;

    bool operator ==(const Tutorial &tutorial);

    string toString();
};


#endif //LAB5_6_TUTORIAL_H
