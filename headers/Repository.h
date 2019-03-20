//
// Created by Horatiu on 20-Mar-19.
//

#ifndef LAB5_6_REPOSITORY_H
#define LAB5_6_REPOSITORY_H

#include "DynamicVector.h"
#include "Tutorial.h"

class Repository
{
private:
    DynamicVector<Tutorial *> tutorials;

    int search(Tutorial *tutorial);

public:
    const DynamicVector<Tutorial *> &getTutorials() const;

    void add(Tutorial *tutorial);

    void update(Tutorial *tutorial);

    void remove(Tutorial *tutorial);

    ~Repository();
};


#endif //LAB5_6_REPOSITORY_H
