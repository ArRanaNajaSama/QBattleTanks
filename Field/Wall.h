#pragma once

#include "BaseElement.h"

#define cell 50

class Wall : public BaseElement
{
public:
    Wall(int a, int b);
    void sayMyName();

protected:
    int x;
    int y;
};
