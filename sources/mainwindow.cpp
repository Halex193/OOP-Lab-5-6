#include <headers/mainwindow.h>
#include <QtWidgets/QHBoxLayout>
#include <headers/adminmenu.h>
#include <headers/usermenu.h>
#include <headers/graphmenu.h>

MainWindow::MainWindow(Controller &controller, QWidget *parent) :
        QMainWindow(parent),
        controller{controller}
{
    initWindow();
    connectAll();
}

void MainWindow::connectAll() const
{
    QObject::connect(adminMenu, &QPushButton::clicked, this, &MainWindow::adminMenuButtonClicked);
    QObject::connect(userMenu, &QPushButton::clicked, this, &MainWindow::userMenuButtonClicked);
    QObject::connect(graphButton, &QPushButton::clicked, this, &MainWindow::graphButtonClicked);
}

void MainWindow::initWindow()
{
    QHBoxLayout *layout = new QHBoxLayout;
    adminMenu = new QPushButton("Admin menu");
    layout->addWidget(adminMenu);

    userMenu = new QPushButton("User menu");
    layout->addWidget(userMenu);

    graphButton = new QPushButton("Graph");
    layout->addWidget(graphButton);

    QWidget *central = new QWidget();
    setCentralWidget(central);
    centralWidget()->setLayout(layout);

    setWindowTitle("Welcome window");
    setFixedSize(400, 100);
}

void MainWindow::adminMenuButtonClicked()
{
    this->close();
    (new AdminMenu{controller})->show();
}

void MainWindow::graphButtonClicked()
{
    this->close();
    (new GraphMenu{controller})->show();
}

void MainWindow::userMenuButtonClicked()
{
    this->close();
    (new UserMenu{controller})->show();
}

MainWindow::~MainWindow() = default;
