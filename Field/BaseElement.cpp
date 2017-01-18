#include "BaseElement.h"
#include "ArmoredWall.h"
#include "Headquarters.h"
#include "Wall.h"
#include "Tile.h"

BaseElement *BaseElement::makeElement(BaseElementID baseID, int a, int b)
{
    //create new item
    BaseElement *creation;

    //assing element and type
    if (baseID == armoredWallID)
    {
        creation = new ArmoredWall(a,b);
    }
    else if (baseID == headquartersID)
    {
        creation = new Headquarters(a,b);
    }
    else if (baseID == wallID)
    {
        creation = new Wall(a,b);
    }
    else if (baseID == tileID)
    {
        creation = new Tile(a,b);
    }
    return creation;
}

BaseElement::~BaseElement()
{
}

