#include <QtWidgets>
#include "../headers/mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent)
{
    QHBoxLayout *layout = new QHBoxLayout;
    QPushButton *adminMenu = new QPushButton("Admin menu");
    layout->addWidget(adminMenu);
    QPushButton *userMenu = new QPushButton("User menu");
    layout->addWidget(userMenu);
    QPushButton *graph = new QPushButton("Graph");
    layout->addWidget(graph);

    QWidget *central = new QWidget();
    setCentralWidget(central);
    centralWidget()->setLayout(layout);

    setWindowTitle("Main menu");
    setFixedSize(400, 100);
}

MainWindow::~MainWindow() = default;
