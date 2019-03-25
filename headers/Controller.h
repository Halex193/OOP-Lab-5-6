//
// Created by Horatiu on 20-Mar-19.
//

#ifndef LAB5_6_CONTROLLER_H
#define LAB5_6_CONTROLLER_H


#include <vector>
#include "Repository.h"

class Controller
{
private:
    Repository &repository;
public:
    explicit Controller(Repository &repository);

    void add(string &title, string &presenter, Duration duration, int likes, string &link);

    void update(string &title, string &presenter, Duration duration, int likes, string &link);

    void remove(string &title);

    const DynamicVector<Tutorial *> &list() const;

    void populateRepository();
};


#endif //LAB5_6_CONTROLLER_H
