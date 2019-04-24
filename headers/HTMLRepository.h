#ifndef LAB5_6_HTMLREPOSITORY_H
#define LAB5_6_HTMLREPOSITORY_H

#include "Repository.h"

class HTMLRepository : public Repository
{
public:
    string watchListDirectory;
    const string rowTemplatePath = "/templates/rowTemplate.html";
    const string tableTemplatePath = "/templates/tableTemplate.html";
    const string watchListPath = "/watchList.html";

    void saveWatchList() override;

public:
    HTMLRepository(const string &tutorialsFile, const string &watchListHTMLDirectory);
};


#endif //LAB5_6_HTMLREPOSITORY_H
