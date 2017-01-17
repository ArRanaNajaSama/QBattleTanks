#include <QDebug>

#include "Tile.h"

Tile::Tile(int a, int b)
{
    x = a;
    y = b;

    //set position
    setPos(x*cell, y*cell);

    //draw item - QPixmap
}

void Tile::sayMyName()
{
    qDebug() << "Tile is tiled.";
}
