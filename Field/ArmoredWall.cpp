#include <QDebug>

#include "ArmoredWall.h"

ArmoredWall::ArmoredWall(int a, int b)
{
    x = a;
    y = b;

    //set position
    setPos(x*cell, y*cell);

    //draw item
    setRect(0,0,50,50);
}

void ArmoredWall::sayMyName()
{
    qDebug() << "Armored wall built!";
}
