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

    /**
     * Adds a tutorial to the repository
     */
    void add(const string &title, const string &presenter, Duration duration, int likes, const string &link);

    /**
     * Update a tutorial from the repository
     */
    void update(const string &title, const string &presenter, Duration duration, int likes, const string &link);

    /**
     * Removes a tutorial from the database
     */
    void remove(const string &title);

    /**
     * Returns the list of all stored tutorials
     */
    const DynamicVector<Tutorial *> &list() const;

    /**
     * Populates the repository with initial data
     */
    void populateRepository();
};


#endif //LAB5_6_CONTROLLER_H
