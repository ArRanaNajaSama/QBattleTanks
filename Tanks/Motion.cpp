#include <QGraphicsScene>
#include <stdlib.h>

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
    int dx = 0;
    int dy = 0;
    switch(tDirection)
    {
    case 0: // UP
        if (tank->y() > 0)
        {
            dx = 0;
            dy = -1;
        } else
            return;
        break;
    case 1: // RIGHT
        if (tank->x() < (tank->scene()->width() - tank->rect().width()))
        {
            dx += 1;
            dy = 0;
        } else
            return;
        break;
    case 2: // DOWN
        if(tank->y() < (tank->scene()->height() - tank->rect().height()))
        {
            dx = 0;
            dy += 1;
        } else
            return;
        break;
    case 3: // LEFT
        if(tank->x() > 0)
        {
            dx -= 1;
            dy = 0;
        } else
            return;
        break;
    }

    int positionCheck = tank->checkPosition();
    if (positionCheck)
    {
        tank->setPos(tank->x() + tank->rect().width()*dx, tank->y() + tank->rect().height()*dy);
    }
}
