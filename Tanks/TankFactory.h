#pragma once

#include "BaseTank.h"

enum TankID {PlayerID, EnemyID};

class TankFactory
{
public:
    //factory method;
    static BaseTank *makeTank(TankID);
};
