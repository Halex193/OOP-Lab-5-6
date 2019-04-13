#ifndef LAB5_6_SQLREPOSITORY_H
#define LAB5_6_SQLREPOSITORY_H


#include "Repository.h"

class SQLRepository : public Repository
{
private:
    string watchListTable;

    void saveWatchList() override;

public:
    SQLRepository(const string &tutorialsFile, const string &watchListTable);
};


#endif //LAB5_6_SQLREPOSITORY_H
