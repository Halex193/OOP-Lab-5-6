//
// Created by Horatiu on 04-May-19.
//

#include <headers/Controller.h>
#include <headers/mainwindow.h>
#include <headers/GUI.h>
#include <QtWidgets/QApplication>
#include <headers/adminmenu.h>

GUI::GUI(Controller &controller) : UI(controller)
{}

void GUI::run(int argc, char **argv)
{
    QApplication a(argc, argv);
    MainWindow mainWindow{controller};
    mainWindow.show();
//    AdminMenu mainMenu{controller};
//    mainMenu.show();

    QApplication::exec();
}
