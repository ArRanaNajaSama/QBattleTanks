#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <typeinfo>

#include "BaseTank.h"
#include "EnemyTank.h"

BaseTank::BaseTank()
{
    direction = 0;
    speed = 0;
    premotion = NULL;
}


BaseTank::BaseTank(int a, int b)
{
    direction = 0;
    speed = 0;
    premotion = NULL;
    setPos(a,b);
}

BaseTank::~BaseTank()
{
    delete premotion;
}

int BaseTank::getDirection() const
{
    return this->direction;
}

void BaseTank::setDirection(int newDirection)
{
    direction = newDirection;
}

void BaseTank::setTankRotation(int newDirection)
{
    this->direction = newDirection;
    this->setTransformOriginPoint(QPoint(this->rect().width()/2, this->rect().height()/2));
    setRotation(newDirection*90);
}

void BaseTank::shot()
{
    //create new bullet
    Bullet *bullet = new Bullet(direction);

    //set bullet's position
    int bulletX;
    int bulletY;
    switch (direction) {
    case 0:
        bulletX = x() + this->rect().center().x() - bullet->rect().width()/2;
        bulletY = y() - 2*bullet->rect().height();
        break;
    case 1:
        bulletX = x() + this->rect().width() + 3*bullet->rect().height();
        bulletY = y() + this->rect().center().y() - bullet->rect().width()/2;
        break;
    case 2:
        bulletX = x() + this->rect().center().x() + bullet->rect().width()/2;
        bulletY = y() + this->rect().height() + 2*bullet->rect().height();
        break;
    case 3:
        bulletX = x() - 3*bullet->rect().width();
        bulletY = y() + this->rect().center().y() + bullet->rect().width()/2;
        break;
    }
    bullet->setPos(bulletX, bulletY);
    scene()->addItem(bullet);
}

void BaseTank::move(int tDirection)
{
//    BaseTank *bTank = NULL;
//    int dif;
//    QList<QGraphicsItem *> colliding_items = collidingItems();
//    if(direction == this->direction)
//        for (int i = 0, n = colliding_items.size(); i < n; ++i)
//        {
//            if (bTank = dynamic_cast<BaseTank*>(colliding_items[i]))
//            {
//                if(this->x() == bTank->x())
//                {
//                    dif = bTank->y() - this->y();
//                    if( (dif > 0 && this->direction == 2) || (dif < 0 && this->direction == 0))
//                        return;
//                }
//                else if(this->y() == bTank->y())
//                {
//                    dif = bTank->x() - this->x();
//                    if( (dif > 0 && this->direction == 1) || (dif < 0 && this->direction == 3) )
//                        return;
//                }
//            }
//        }

//    // prevent collision;
//    QList<QGraphicsItem *> colliding_items = collidingItems();
//    for (int i = 0, n = colliding_items.size(); i < n; ++i)
//    {
//        if (typeid(*(colliding_items[i])) == typeid(EnemyTank))
//        {
//            //change direction
//            int random = rand()%4;
//            setDirection(random);
//        }
//    }

    premotion->move(tDirection);
}

void BaseTank::setMotion(PreMotion *newMotion)
{
    premotion = newMotion;
}

