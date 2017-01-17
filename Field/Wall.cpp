#include <QDebug>

#include "Wall.h"

Wall::Wall(int a, int b)
{
    x = a;
    y = b;

    //set position
    setPos(x*cell, y*cell);

    //draw item

}

void Wall::sayMyName()
{
    qDebug() << "Wall is here!";
}

