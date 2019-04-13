#include "../headers/SQLRepository.h"

void SQLRepository::saveWatchList()
{

}

SQLRepository::SQLRepository(const string &tutorialsFile, const string &watchListTable) : Repository(tutorialsFile),
                                                                                          watchListTable(watchListTable)
{}
