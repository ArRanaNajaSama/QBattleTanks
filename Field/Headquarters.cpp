#include <QDebug>

#include "Headquarters.h"

Headquarters::Headquarters(int a, int b)
{
    x = a;
    y = b;

    //set position of the HQ
    setPos(x*cell, y*cell);

    //draw item
    setRect(0,0,50,50);
}

void Headquarters::sayMyName()
{
    qDebug() << "HQ is created.";
}
