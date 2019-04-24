#ifndef LAB5_6_SQLREPOSITORY_H
#define LAB5_6_SQLREPOSITORY_H

#include "Repository.h"

class SQLRepository : public Repository
{
private:
    const string hostName = "tcp://127.0.0.1:3306";

    const string userName = "root";

    const string password = "";

    const string schema = "Lab9";

    void readTutorials() override;

    void writeTutorials() const override;

public:
    explicit SQLRepository(const string &tutorialsTable);
};


#endif //LAB5_6_SQLREPOSITORY_H
