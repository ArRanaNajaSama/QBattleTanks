#include <QDebug>

#include "Wall.h"

Wall::Wall(int a, int b)
{
    x = a;
    y = b;

    //set position
    setPos(x*cell, y*cell);

    //draw item
    setPixmap(QPixmap(":/images/images/wall.png"));
}

void Wall::sayMyName()
{
    qDebug() << "Wall is here!";
}

