#include <QtWidgets>
#include <headers/mainwindow.h>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent)
{
    QHBoxLayout *layout = new QHBoxLayout;
    QPushButton *adminMenuButton = new QPushButton("Admin menu");
    layout->addWidget(adminMenuButton);

    QPushButton *userMenuButton = new QPushButton("User menu");
    layout->addWidget(userMenuButton);
    QPushButton *graphButton = new QPushButton("Graph");
    layout->addWidget(graphButton);

    QWidget *central = new QWidget();
    setCentralWidget(central);
    centralWidget()->setLayout(layout);

    setWindowTitle("Main menu");
    setFixedSize(400, 100);
    connect(adminMenuButton, SIGNAL(clicked()), this, SLOT(adminMenuButtonClicked()));
}

void MainWindow::adminMenuButtonClicked()
{

}

MainWindow::~MainWindow() = default;
