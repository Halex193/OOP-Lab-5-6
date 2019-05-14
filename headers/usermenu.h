#ifndef USERMENU_H
#define USERMENU_H

#include <QMainWindow>
#include <headers/Controller.h>
namespace Ui {
class UserMenu;
}

class UserMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserMenu(Controller &controller, QWidget *parent = nullptr);
    ~UserMenu() override;

private:
    Ui::UserMenu *ui;
    const Tutorial *currentTutorial{};

    Controller &controller;

    void connectAll();

    void filterButtonClicked();

    void watchButtonClicked();

    void nextButtonClicked();

    void addToWatchList();
    void deleteButtonClicked();

    void updateWatchList() const;

    void closeEvent (QCloseEvent *event) override;
};

#endif // USERMENU_H
