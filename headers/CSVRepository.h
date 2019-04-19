#ifndef LAB5_6_CSVREPOSITORY_H
#define LAB5_6_CSVREPOSITORY_H

#include "Repository.h"

class CSVRepository : public Repository
{
private:
    string watchlistFile;

    void saveWatchList() override;

public:
    CSVRepository(const string &tutorialsFile, const string &watchListFile);
};


#endif //LAB5_6_CSVREPOSITORY_H
