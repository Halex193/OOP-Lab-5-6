#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QGridLayout>
#include <headers/adminmenu.h>
#include <QtCore/QDebug>

#include "headers/adminmenu.h"

AdminMenu::AdminMenu(Controller &controller, QWidget *parent) :
        QMainWindow(parent),
        controller{controller}
{
    initializeUI();
    connectAll();
}

void AdminMenu::initializeUI()
{
    QVBoxLayout *verticalLayout = new QVBoxLayout{};
    QWidget *window = new QWidget();
    window->setLayout(verticalLayout);
    window->setMinimumSize(500, 0);
    setCentralWidget(window);
    verticalLayout->addWidget(new QLabel{"All tutorials"});
    listWidget = new QListWidget{};
    verticalLayout->addWidget(listWidget);
    QFormLayout *form = new QFormLayout{};
    verticalLayout->addLayout(form);

    titleTextBox = new QLineEdit{};
    presenterTextBox = new QLineEdit{};
    minutesTextBox = new QLineEdit{};
    secondsTextBox = new QLineEdit{};
    likesTextBox = new QLineEdit{};
    linkTextBox = new QLineEdit{};

    form->addRow("Title: ", titleTextBox);
    form->addRow("Presenter: ", presenterTextBox);
    form->addRow("Minutes: ", minutesTextBox);
    form->addRow("Seconds: ", secondsTextBox);
    form->addRow("Likes: ", likesTextBox);
    form->addRow("Link: ", linkTextBox);

    QHBoxLayout *horizontalLayout = new QHBoxLayout{};
    verticalLayout->addLayout(horizontalLayout);

    addButton = new QPushButton{"Add"};
    deleteButton = new QPushButton{"Delete"};
    updateButton = new QPushButton{"Update"};

    horizontalLayout->addWidget(addButton);
    horizontalLayout->addWidget(deleteButton);
    horizontalLayout->addWidget(updateButton);
    updateList();
}

void AdminMenu::updateList()
{
    listWidget->clear();
    for (auto &tutorial : controller.list())
    {
        listWidget->addItem(QString{tutorial->getTitle().c_str()});
    }
}

void AdminMenu::connectAll()
{
    QObject::connect(addButton, &QPushButton::clicked, this, &AdminMenu::addButtonClicked);
    QObject::connect(deleteButton, &QPushButton::clicked, this, &AdminMenu::deleteButtonClicked);
    QObject::connect(updateButton, &QPushButton::clicked, this, &AdminMenu::updateButtonClicked);
    QObject::connect(listWidget, &QListWidget::itemSelectionChanged, this, &AdminMenu::listWidgetSelectionChanged);
}

AdminMenu::~AdminMenu()
{
}

void AdminMenu::addButtonClicked()
{
    controller.add(titleTextBox->text().toStdString(), presenterTextBox->text().toStdString(),
                   Duration{minutesTextBox->text().toInt(), secondsTextBox->text().toInt()},
                   likesTextBox->text().toInt(), linkTextBox->text().toStdString());
    updateList();
}

void AdminMenu::deleteButtonClicked()
{
    controller.remove(titleTextBox->text().toStdString());
    updateList();
}

void AdminMenu::updateButtonClicked()
{
    controller.update(titleTextBox->text().toStdString(), presenterTextBox->text().toStdString(),
                   Duration{minutesTextBox->text().toInt(), secondsTextBox->text().toInt()},
                   likesTextBox->text().toInt(), linkTextBox->text().toStdString());
    updateList();
}

void AdminMenu::listWidgetSelectionChanged()
{
    int index = listWidget->currentRow();
    Tutorial *tutorial = controller.list()[index];
    titleTextBox->setText(QString{tutorial->getTitle().c_str()});
    presenterTextBox->setText(QString{tutorial->getPresenter().c_str()});
    minutesTextBox->setText(QString::number(tutorial->getDuration().minutes));
    secondsTextBox->setText(QString::number(tutorial->getDuration().seconds));
    likesTextBox->setText(QString::number(tutorial->getLikes()));
    linkTextBox->setText(QString{tutorial->getLink().c_str()});

}
