#ifndef LAB5_6_SQLREPOSITORY_H
#define LAB5_6_SQLREPOSITORY_H


#include "Repository.h"

class SQLRepository : public Repository
{
private:
    void readTutorials() override;

    void writeTutorials() const override;

public:
    explicit SQLRepository(const string &tutorialsTable);
};


#endif //LAB5_6_SQLREPOSITORY_H
