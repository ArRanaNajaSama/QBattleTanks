#pragma once

#include "BaseTank.h"

class BaseTank;

class PreMotion
{
public:
    explicit PreMotion(BaseTank* tank = nullptr);
    virtual ~PreMotion();

    void virtual move(int newDirection) = 0;

protected:
    BaseTank* tank;
};
