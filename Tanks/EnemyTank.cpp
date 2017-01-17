#include <stdlib.h>
#include <QTimer>

#include "EnemyTank.h"
#include "Motion.h"

EnemyTank::EnemyTank() : BaseTank()
{
    //connect
    QTimer *eTimer = new QTimer(this);
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
    if (this->direction != random)
    {
        move(random);
    }
    move(random);
}
