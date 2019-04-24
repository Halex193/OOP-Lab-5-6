#include "headers/ConsoleUI.h"
#include "headers/Controller.h"
#include "headers/Repository.h"
#include "headers/CSVRepository.h"
#include "headers/HTMLRepository.h"
#include <iostream>
using namespace std;

int main()
{
    const char *tutorialsFile = "data/tutorials.csv";
    const char *watchListCSVFile = "data/watchList.csv";
    const char *watchListHTMLDirectory = "data/watchList";
    const char *tutorialsTable = "tutorials";

    Repository *repository;
    string repositoryType = ConsoleUI::readString("Choose the repository type: ");
    if (repositoryType == "csv")
    {
         repository = new CSVRepository{tutorialsFile, watchListCSVFile};
    }
    else if (repositoryType == "html")
    {
        repository = new HTMLRepository{tutorialsFile, watchListHTMLDirectory};
    }
    else
    {
        repository = new Repository{tutorialsFile};
    }
    Controller controller{*repository};
    ConsoleUI consoleUI{controller};
    consoleUI.run();
    delete repository;
    return 0;
}