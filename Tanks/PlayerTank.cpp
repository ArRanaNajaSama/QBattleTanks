#include <QKeyEvent>
#include <QDebug>

#include "PlayerTank.h"
#include "Motion.h"

PlayerTank::PlayerTank() : BaseTank()
{
    premotion = new Motion(this);
}

PlayerTank::PlayerTank(int a, int b) : BaseTank(a, b)
{
    premotion = new Motion(this);
}

PlayerTank::~PlayerTank()
{
}

void PlayerTank::keyPressEvent(QKeyEvent *event)
{
    // moving tank by keys;
    if (event->key() == Qt::Key_Up)
    {
        qDebug() << "Up is pressed";
        move(0);
    }
    else if (event->key() == Qt::Key_Down)
    {
        qDebug() << "Down is pressed";
        move(2);
    }
    else if (event->key() == Qt::Key_Right)
    {
        qDebug() << "Right is pressed";
        move(1);
    }
    else if (event->key() == Qt::Key_Left)
    {
        qDebug() << "Left is pressed";
        move(3);
    }

    // fire the bullet
    else if (event->key() == Qt::Key_Space)
    {
        shot();
    }
}

