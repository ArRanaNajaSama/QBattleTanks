#include <QGraphicsScene>

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
    if (tank->getDirection() != tDirection)
    {
        tank->setRotation(tDirection);
    }

    // move tanks around the field;
    switch(tDirection)
    {
    case 0: // UP
        if (tank->y() > 0)
        {
            tank->setPos(tank->x(), tank->y()-10);

        } else
            return;
        break;
    case 1: // RIGHT
        if (tank->x() < (tank->scene()->width() - tank->rect().width()))
        {
            tank->setPos(tank->x()+10, tank->y());
        } else
            return;
        break;
    case 2: // DOWN
        if(tank->y() < (tank->scene()->height() - tank->rect().height()))
        {
            tank->setPos(tank->x(), tank->y()+10);
        } else
            return;
        break;
    case 3: // LEFT
        if(tank->x() > 0)
        {
            tank->setPos(tank->x()-10, tank->y());
        } else
            return;
        break;
    }
}


