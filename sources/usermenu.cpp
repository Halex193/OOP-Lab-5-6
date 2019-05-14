#include <headers/Controller.h>
#include <QPushButton>
#include <QListWidget>
#include <headers/usermenu.h>

#include "headers/usermenu.h"
#include "ui_usermenu.h"
#include <QMessageBox>
#include <headers/mainwindow.h>

UserMenu::UserMenu(Controller &controller, QWidget *parent) :
        controller{controller},
        QMainWindow(parent),
        ui(new Ui::UserMenu),
        currentTutorial(nullptr)
{
    ui->setupUi(this);
    connectAll();
    filterButtonClicked();
}

UserMenu::~UserMenu()
{
    delete ui;
}

void UserMenu::connectAll()
{
    QObject::connect(ui->filterButton, &QPushButton::clicked, this, &UserMenu::filterButtonClicked);
    QObject::connect(ui->watchButton, &QPushButton::clicked, this, &UserMenu::watchButtonClicked);
    QObject::connect(ui->nextButton, &QPushButton::clicked, this, &UserMenu::nextButtonClicked);
    QObject::connect(ui->deleteButton, &QPushButton::clicked, this, &UserMenu::deleteButtonClicked);
    QObject::connect(ui->addToWatchListButton, &QPushButton::clicked, this, &UserMenu::addToWatchList);
}

void UserMenu::filterButtonClicked()
{
    controller.begin(ui->presenterLineEdit->text().toStdString());
    nextButtonClicked();
}

void UserMenu::watchButtonClicked()
{
    controller.show(currentTutorial);
}

void UserMenu::nextButtonClicked()
{
    currentTutorial = controller.next();
    ui->titleLineEdit->setText(QString{currentTutorial->getTitle().c_str()});
}

void UserMenu::addToWatchList()
{
    controller.addToWatchList(currentTutorial);
    updateWatchList();
}

void UserMenu::updateWatchList() const
{
    ui->watchlistWidget->clear();
    for (auto &tutorial : controller.watchList())
    {
        ui->watchlistWidget->addItem(QString{tutorial->getTitle().c_str()});
    }
}

void UserMenu::deleteButtonClicked()
{
    if (ui->watchlistWidget->currentItem() != nullptr)
    {
        Tutorial *tutorial = controller.removeFromWatchList(ui->watchlistWidget->currentItem()->text().toStdString());
        updateWatchList();
        QMessageBox::StandardButton result = QMessageBox::question(this, "Video removed",
                                                                   tr("Did you like the video?\n"),
                                                                   QMessageBox::No |
                                                                   QMessageBox::Yes,
                                                                   QMessageBox::No);
        if (result != QMessageBox::Yes)
        {
            tutorial->like();
        }
    }
}

void UserMenu::closeEvent (QCloseEvent *event)
{
    this->close();
    (new MainWindow{controller})->show();
}