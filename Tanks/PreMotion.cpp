#include "PreMotion.h"

PreMotion::PreMotion(BaseTank* _tank)
{
    tank = _tank;
}

PreMotion::~PreMotion()
{
    if (tank)
        delete tank;
}



