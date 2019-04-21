//
// Created by Horatiu on 20-Mar-19.
//

#ifndef LAB5_6_REPOSITORY_H
#define LAB5_6_REPOSITORY_H

#include <vector>
#include "Tutorial.h"

class Repository
{
private:
    vector<Tutorial *> tutorials;
    vector<string> watchlist;
    const string tutorialsFile;

    /**
     * Searches for a stored Tutorial and returns its position in the repository
     */
    int search(Tutorial *tutorial) const;

    Tutorial* search(const string &tutorialTitle) const;

    virtual void readTutorials();

    virtual void writeTutorials() const;

    void destroyTutorials();

    virtual void saveWatchList();
public:

    explicit Repository(const string &tutorialsFile);

    /**
     * Retrieves all the Tutorials stored in the repository
     * @return
     */
    const vector<Tutorial *> &getTutorials();

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

    /**
     * Adds a tutorial to the watchlist
     * @return true if the Tutorial was added
     *         false if the tutorial already exists in the watchlist
     */
    bool addToWatchList(const Tutorial *tutorial);

    /**
     * Removes a tutorial from the watchlist
     * @param title The title of the tutorial to be removed
     * @return The tutorial that was removed, or nullptr if the tutorial did not exist
     */
    Tutorial* removeFromWatchList(const string &title);

    /**
     * Gets the list of Tutorials currently in the watchlist
     * @return A vector containing the tutorials
     */
    const vector<Tutorial *> getWatchlist() const;

    ~Repository();
};


#endif //LAB5_6_REPOSITORY_H
