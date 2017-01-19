#pragma once

#include "BaseTank.h"

class PlayerTank : public BaseTank
{
public:
    explicit PlayerTank();
    explicit PlayerTank(int a, int b);
    ~PlayerTank();

    void keyPressEvent(QKeyEvent *event);
};
