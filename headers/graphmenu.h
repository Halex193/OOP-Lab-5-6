#ifndef GRAPHMENU_H
#define GRAPHMENU_H

#include <QMainWindow>
#include "Controller.h"

namespace Ui {
class GraphMenu;
}

class GraphMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphMenu(Controller &controller, QWidget *parent = nullptr);
    ~GraphMenu() override;

private:
    Ui::GraphMenu *ui;
    Controller &controller;

    void closeEvent(QCloseEvent *event) override;
};

#endif // GRAPHMENU_H
