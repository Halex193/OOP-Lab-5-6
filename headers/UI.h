//
// Created by Horatiu on 04-May-19.
//

#ifndef LAB5_6_UI_H
#define LAB5_6_UI_H


class UI
{
protected:
    Controller &controller;
public:
    explicit UI(Controller &controller) : controller{controller}{}

    virtual void run(int argc, char **argv) = 0;

    virtual ~UI() = default;;
};


#endif //LAB5_6_UI_H
