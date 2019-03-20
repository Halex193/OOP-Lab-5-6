//
// Created by Horatiu on 20-Mar-19.
//

#ifndef LAB5_6_CONTROLLER_H
#define LAB5_6_CONTROLLER_H


#include "Repository.h"

class Controller
{
private:
    Repository &repository;
public:
    explicit Controller(Repository &repository);
};


#endif //LAB5_6_CONTROLLER_H
