#pragma once

#include "BaseElement.h"

#define cell 50

class Wall : public BaseElement
{
public:
    Wall(int a, int b);

protected:
    int x;
    int y;
};
