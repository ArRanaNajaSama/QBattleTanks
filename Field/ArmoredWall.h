#pragma once

#include "BaseElement.h"

#define cell 50

class ArmoredWall : public BaseElement
{
public:
    ArmoredWall(int a, int b);
    void sayMyName();

protected:
    int x;
    int y;
};
