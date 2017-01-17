#include "Motion.h"

Motion::Motion(BaseTank *baseTank) : PreMotion()
{
    tank = baseTank;
}

Motion::~Motion()
{
}

void Motion::move(int tDirection)
{
    // rotate our tank in acc with it's direction;
//    if (tank->getDirection() != tDirection)
//    {
//        tank->setRotation(tDirection);
//    }

    // move tanks around the field;
    int dx = 0;
    int dy = 0;
    switch(tDirection)
    {
    case 0:
        if (tank->y()-10 > 0)
        {
//            dx = 0;
//            dy = -1;
            tank->setPos(tank->x(), tank->y()-10);

        } else
            return;
        break;
    case 1:
        if (tank->x()+10 < 800)
        {
//            dx = 1;
//            dy = 0;
            tank->setPos(tank->x()+10, tank->y());
        } else
            return;
        break;
    case 2:
        if(tank->y()+10 < 400)
        {
//            dx = 0;
//            dy = 1;
            tank->setPos(tank->x(), tank->y()+10);
        } else
            return;
        break;
    case 3:
        if(tank->x()-10 > 0)
        {
//            dx = -1;
//            dy = 0;
            tank->setPos(tank->x()-10, tank->y());
        } else
            return;
        break;
    }
}


