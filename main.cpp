#include "headers/ConsoleUI.h"
#include "headers/Controller.h"
#include "headers/Repository.h"
#include "headers/CSVRepository.h"
#include "headers/HTMLRepository.h"
#include <iostream>
#include "headers/GUI.h"

using namespace std;

int main(int argc, char* argv[])
{
    const char *tutorialsFile = "data/tutorials.csv";
    const char *watchListCSVFile = "data/watchList.csv";
    const char *watchListHTMLDirectory = "data/watchList";

    const string defaultRepositoryType = "html";
    const string defaultUIType = "GUI";

    Repository *repository;
    string repositoryType;
    if (defaultRepositoryType.empty())
    {
        repositoryType = ConsoleUI::readString("Choose the repository type: ");
    }
    else
    {
        repositoryType = defaultRepositoryType;
    }

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
    UI *ui;
    string UIType;
    if (defaultUIType.empty())
    {
        UIType = ConsoleUI::readString("Choose the UI type: ");
    }
    else
    {
        UIType = defaultUIType;
    }

    if (UIType == "GUI")
    {
        ui = new GUI{controller};
    }
    else
    {
        ui = new ConsoleUI{controller};
    }
    ui->run(argc, argv);
    delete ui;
    delete repository;
    return 0;
}