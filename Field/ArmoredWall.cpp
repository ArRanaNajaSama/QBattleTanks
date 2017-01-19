#include "ArmoredWall.h"

ArmoredWall::ArmoredWall(int a, int b)
{
    x = a;
    y = b;

    //set position
    setPos(x*cell, y*cell);

    //draw item
    setPixmap(QPixmap(":/images/images/armored.png"));
}
