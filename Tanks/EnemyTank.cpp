#include <stdlib.h>
#include <QPainter>
#include <QPixmap>

#include "EnemyTank.h"
#include "Motion.h"

EnemyTank::EnemyTank() : BaseTank()
{
    //connect
    eTimer = new QTimer;
    connect(eTimer, SIGNAL(timeout()), this, SLOT(launch()));
    premotion = new Motion(this);
    eTimer->start(500);
}

EnemyTank::EnemyTank(int a, int b) : BaseTank(a,b)
{
    premotion = new Motion(this);
}

EnemyTank::~EnemyTank()
{
    delete eTimer;
}

void EnemyTank::launch()
{
    //generate random number
    int random = rand()%5;

    //shot
    if (random == 4)
    {
        shot();
        return;
    }

    //random movement
    else if (this->getDirection() != random)
    {
        move(random);
    }
}
