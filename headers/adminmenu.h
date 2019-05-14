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
    QPushButton *addButton{};
    QPushButton *deleteButton{};
    QPushButton *updateButton{};

    QLineEdit *titleTextBox{};
    QLineEdit *presenterTextBox{};
    QLineEdit *minutesTextBox{};
    QLineEdit *secondsTextBox{};
    QLineEdit *likesTextBox{};
    QLineEdit *linkTextBox{};
    QListWidget *listWidget{};

    Controller &controller;
public:
    explicit AdminMenu(Controller &controller, QWidget *parent = nullptr);

    ~AdminMenu() override;

private:

    void initializeUI();

    void connectAll();

private:

    void addButtonClicked();

    void deleteButtonClicked();

    void updateButtonClicked();

    void updateList();

    void listWidgetSelectionChanged();

    void closeEvent (QCloseEvent *event) override;
};

#endif // MAINMENU_H
