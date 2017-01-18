#pragma once

#include <QTime>

#include "BaseTank.h"
#include "PreMotion.h"

class Motion : public PreMotion
{
public:
    explicit Motion(BaseTank *baseTank = NULL);
    ~Motion();

    void move(int tDirection);
};
