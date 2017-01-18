#include "Bullet.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <typeinfo>

#include "EnemyTank.h"
#include "BaseTank.h"
#include "Field/BaseElement.h"
#include "Field/Wall.h"
#include "Field/ArmoredWall.h"
#include "Field/Headquarters.h"
#include "Game.h"

extern Game* game;

Bullet::Bullet(int newBDirection)
{
    bDirection = newBDirection;

    //create rect
    setRect(0,0,10,10);

    //connect
    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(25);
}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Wall))
        {
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
        else if (typeid(*(colliding_items[i])) == typeid(ArmoredWall))
        {
            scene()->removeItem(this);
            delete this;
            return;
        }
        else if (typeid(*(colliding_items[i])) == typeid(EnemyTank))
        {
            game->destroyEnemyTank(dynamic_cast<BaseTank*>(colliding_items[i]));
            scene()->removeItem(this);
            delete this;
            return;
        }
        else if(typeid(*(colliding_items[i])) == typeid(PlayerTank))
        {
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;
            delete game;
            return;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Headquarters))
        {
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //move bullet in accordance with direction;
    switch(bDirection)
    {
    case 0:
        setPos(x(),y()-10);
        break;
    case 1:
        setPos(x()+10, y());
        break;
    case 2:
        setPos(x(), y()+10);
        break;
    case 3:
        setPos(x()-10, y());
        break;
    }

    // if bullet leaves the field- delete it
    if (pos().y() < 0 || pos().y() > scene()->height() ||
            pos().x() < 0 || pos().x() > scene()->width())
    {
        scene()->removeItem(this);
        delete this;
    }
}
