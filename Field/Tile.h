#pragma once

#include "BaseElement.h"

#define cell 50

class Tile : public BaseElement
{
public:
    Tile(int a, int b);
    void sayMyName();

protected:
    int x;
    int y;
};
