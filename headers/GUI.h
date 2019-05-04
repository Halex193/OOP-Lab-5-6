//
// Created by Horatiu on 04-May-19.
//

#ifndef LAB5_6_GUI_H
#define LAB5_6_GUI_H


#include "UI.h"

class GUI : public UI
{
public:
    explicit GUI(Controller &controller);

    void run(int argc, char **argv) override;
};


#endif //LAB5_6_GUI_H
