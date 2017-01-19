#include "TankFactory.h"
#include "EnemyTank.h"
#include "PlayerTank.h"

BaseTank *TankFactory::makeTank(TankID id)
{
    if (id == PlayerID)
    {
        return new PlayerTank();
    }
    else if (id == EnemyID)
    {
        return new EnemyTank();
    } else {
        return nullptr;
    }
}
