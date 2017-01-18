#pragma once

#include <QTime>

#include "PreMotion.h"

class NoMotion : public PreMotion
{
public:
    explicit NoMotion(BaseTank* tank = NULL);
    ~NoMotion();

    void move(int newDirection);

protected:
    QTime time;
};
