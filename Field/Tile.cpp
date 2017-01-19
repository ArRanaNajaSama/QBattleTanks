#include "Tile.h"

Tile::Tile(int a, int b)
{
    x = a;
    y = b;

    //set position
    setPos(x*cell, y*cell);

    //draw item
    setPixmap(QPixmap(":/images/images/tile.png"));
}
