#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <headers/Controller.h>

class AdminMenu : public QMainWindow
{
Q_OBJECT
private:
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *updateButton;
    QPushButton *filterButton;

    QLineEdit *titleTextBox;
    QLineEdit *presenterTextBox;
    QLineEdit *minutesTextBox;
    QLineEdit *secondsTextBox;
    QLineEdit *likesTextBox;
    QLineEdit *linkTextBox;
    QListWidget *listWidget;

    Controller &controller;
public:
    explicit AdminMenu(Controller &controller, QWidget *parent = nullptr);

    ~AdminMenu();

private:

    void initializeUI();

    void connectAll();

private:

    void addButtonClicked();

    void deleteButtonClicked();

    void updateButtonClicked();

    void updateList();

    void listWidgetSelectionChanged();
};

#endif // MAINMENU_H
