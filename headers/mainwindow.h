#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <headers/Controller.h>

class MainWindow : public QMainWindow
{
private:
    QPushButton *adminMenu;
    QPushButton *userMenu;
    QPushButton *graphButton;
    Controller &controller;
public:
    explicit MainWindow(Controller &controller, QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    void initWindow();

    void connectAll() const;

private:

    void adminMenuButtonClicked();

    void userMenuButtonClicked();

    void graphButtonClicked();

};

#endif // MAINWINDOW_H
