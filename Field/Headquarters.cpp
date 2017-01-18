#include <QDebug>

#include "Headquarters.h"

Headquarters::Headquarters(int a, int b)
{
    x = a;
    y = b;

    //set position of the HQ
    setPos(x*cell, y*cell);

    //draw item
    setPixmap(QPixmap(":/images/images/HQ.png"));
}

void Headquarters::sayMyName()
{
    qDebug() << "HQ is created.";
}
