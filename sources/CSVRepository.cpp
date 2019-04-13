#include "../headers/CSVRepository.h"
#include <fstream>

CSVRepository::CSVRepository(const string &tutorialsFile, const string &watchListFile) : Repository(tutorialsFile), watchlistFile(watchListFile)
{
    saveWatchList();
}

void CSVRepository::saveWatchList()
{
    ofstream outStream{watchlistFile};
    vector<Tutorial *> watchList = getWatchlist();
    for (auto &tutorial : watchList)
    {
        outStream << *tutorial << "\n";
    }
    outStream.close();
}
