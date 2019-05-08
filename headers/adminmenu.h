#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QMainWindow>

class AdminMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMenu(QWidget *parent = nullptr);
    ~AdminMenu() override;

private:
    AdminMenu *ui;
};

#endif // ADMINMENU_H
