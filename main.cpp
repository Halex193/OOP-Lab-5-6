#include "headers/ConsoleUI.h"
#include "headers/Controller.h"
#include "headers/Repository.h"

int main()
{
    Repository repository{};
    Controller controller{repository};
    ConsoleUI consoleUI{controller};
    consoleUI.run();
    return 0;
}