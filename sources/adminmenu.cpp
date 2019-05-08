#include <headers/adminmenu.h>

AdminMenu::AdminMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new AdminMenu)
{

}

AdminMenu::~AdminMenu()
{
    delete ui;
}
