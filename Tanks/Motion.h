#pragma once

#include "BaseTank.h"
#include "PreMotion.h"

class Motion : public PreMotion
{
public:
    explicit Motion(BaseTank *baseTank = nullptr);
    ~Motion();

    void move(int tDirection);
};
