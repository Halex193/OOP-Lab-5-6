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

    /**
     * Searches for a stored Tutorial and returns its position in the repository
     */
    int search(Tutorial *tutorial) const;

public:
    /**
     * Retrieves all the Tutorials stored in the repository
     * @return
     */
    const DynamicVector<Tutorial *> &getTutorials() const;

    /**
     * Adds a tutorial in the repository
     * Throws DuplicateTutorial if the Tutorial is already stored in the repository
     * @param tutorial
     */
    void add(Tutorial *tutorial);

    /**
     * Updates a tutorial stored in the repository
     * Throws TutorialDoesNotExistException if the tutorial is not stored in the repository
     * @param tutorial
     */
    void update(Tutorial *tutorial);

    /**
     * Removes a tutorial stored in the repository
     * Throws TutorialDoesNotExistException if the tutorial is not stored in the repository
     * @param tutorial
     */
    void remove(Tutorial *tutorial);

    ~Repository();
};


#endif //LAB5_6_REPOSITORY_H
