#include "../headers/HTMLRepository.h"
#include <regex>
#include <fstream>
#include <sstream>

HTMLRepository::HTMLRepository(const string &tutorialsFile, const string &watchListDirectory) : Repository(
        tutorialsFile), watchListDirectory(watchListDirectory)
{
    saveWatchList();
}

void HTMLRepository::saveWatchList()
{
    const vector<Tutorial *> &watchList = getWatchlist();
    stringstream rows;
    if (!watchList.empty())
    {
        stringstream rowTemplateStringStream;
        ifstream rowTemplateFile{watchListDirectory + rowTemplatePath};
        rowTemplateStringStream << rowTemplateFile.rdbuf();
        rowTemplateFile.close();
        string rowTemplate = rowTemplateStringStream.str();

        for (auto &tutorial : watchList)
        {
            string tutorialRow = rowTemplate;
            tutorialRow = std::regex_replace(tutorialRow, std::regex("\\{%title%\\}"), tutorial->getTitle());
            tutorialRow = std::regex_replace(tutorialRow, std::regex("\\{%presenter%\\}"), tutorial->getPresenter());
            tutorialRow = std::regex_replace(tutorialRow, std::regex("\\{%duration%\\}"),
                                             to_string(tutorial->getDuration().minutes) + ":" +
                                             to_string(tutorial->getDuration().seconds));
            tutorialRow = std::regex_replace(tutorialRow, std::regex("\\{%link%\\}"), tutorial->getLink());
            rows << tutorialRow << "\n";
        }
    }
    stringstream tableTemplateStringStream;
    ifstream tableTemplateFile{watchListDirectory + tableTemplatePath};
    tableTemplateStringStream << tableTemplateFile.rdbuf();
    tableTemplateFile.close();
    string tableTemplate = tableTemplateStringStream.str();


    string ceva = rows.str();
    string table = std::regex_replace(tableTemplate, std::regex("\\{%rows%\\}"), rows.str());

    ofstream watchListFile{watchListDirectory + watchListPath};
    watchListFile << table;
    watchListFile.close();
}
