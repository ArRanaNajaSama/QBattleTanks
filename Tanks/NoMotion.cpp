#include "NoMotion.h"
#include "Motion.h"

#define TIMEOUT 5000

NoMotion::NoMotion(BaseTank *_tank) : PreMotion()
{
    tank =_tank;
    time = QTime::currentTime();
}

NoMotion::~NoMotion()
{
}

void NoMotion::move(int newDirection)
{
    if (tank->getDirection()!= newDirection)
    {
        tank->setTankRotation(newDirection);
        return;
    }

    if (time.msecsTo(QTime::currentTime()) > TIMEOUT)
    {
        PreMotion* newMove = new Motion(tank);
        tank->setMotion(newMove);
        delete this;
    }
}
