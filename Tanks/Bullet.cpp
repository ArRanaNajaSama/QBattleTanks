#include "Bullet.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <typeinfo>

#include "EnemyTank.h"
#include "BaseTank.h"

Bullet::Bullet(int newBDirection)
{
    bDirection = newBDirection;
    this->setRotation(bDirection*90);

    //create rect
    setRect(0,0,10,10);

    //connect
    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(25);
}

void Bullet::move()
{
    // check for collisions and solve them
    // if bullet collides with enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(EnemyTank))
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

    if (pos().y() < 0 || pos().y() > scene()->height() ||
        pos().x() < 0 || pos().x() > scene()->width())
    {
        scene()->removeItem(this);
        delete this;
    }
}
