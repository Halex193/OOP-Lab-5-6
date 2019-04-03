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
    vector<Tutorial *> activeTutorials;
    int tutorialIndex;
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
    const vector<Tutorial *> &list() const;

    /**
     * Populates the repository with initial data
     */
    void populateRepository();

    /**
     * Sets up the active tutorials filtering them by the presenter
     * @param presenter The name of the presenter to be filtered by or empty string for all tutorials
     * @return true if there are tutorials to be shown
     *         false if the filtered list is empty
     */
    bool begin(const string &presenter);

    /**
     * Retrieves the next Tutorial from the active tutorials list
     * @return
     */
    const Tutorial *next();

    /**
     * Adds a tutorial to the watchlist
     */
    bool addToWatchList(const Tutorial *tutorial);

    /**
     * Remove a tutorial from the watchlist by its title
     * @param title The title of the tutorial
     * @return The tutorial that was removed or nullptr if the tutorial doesn't exit in the watchlist
     */
    Tutorial *removeFromWatchList(const string &title);

    /**
     * Get the current watchlist
     */
    vector<Tutorial *> watchList();
};


#endif //LAB5_6_CONTROLLER_H
