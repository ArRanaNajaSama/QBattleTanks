#include <typeinfo>

#include "BaseTank.h"
#include "Bullet.h"
#include "Game.h"

extern Game *game;

BaseTank::BaseTank()
{
    direction = 0;
    premotion = nullptr;
}


BaseTank::BaseTank(int a, int b)
{
    direction = 0;
    premotion = nullptr;
    setPos(a,b);
}

BaseTank::~BaseTank()
{
    //delete premotion;
}

int BaseTank::getDirection()
{
    return this->direction;
}

void BaseTank::setDirection(int newDirection)
{
    direction = newDirection;
}

void BaseTank::move(int newDirection)
{

    this->setDirection(newDirection);

    // prevent collisions between tanks;
    BaseTank *bTank = nullptr;
    int difference = 0;
    QList<QGraphicsItem *> colliding_items = collidingItems();
    if(getDirection() == this->getDirection())
        for (int i = 0, n = colliding_items.size(); i < n; ++i)
        {
            if (bTank = dynamic_cast<BaseTank*>(colliding_items[i]))
            {
                if(this->x() == bTank->x())
                {
                    difference = bTank->y() - this->y();
                    if( (difference > 0 && this->getDirection() == 2) || (difference < 0 && this->getDirection() == 0))
                        return;
                }
                else if(this->y() == bTank->y())
                {
                    difference = bTank->x() - this->x();
                    if( (difference > 0 && this->getDirection() == 1) || (difference < 0 && this->getDirection() == 3) )
                        return;
                }
            }
        }
    premotion->move(getDirection());
}

void BaseTank::setTankRotation(int newDirection)
{
    this->setDirection(newDirection);
    this->setTransformOriginPoint(QPoint(this->rect().width()/2, this->rect().height()/2));
    this->setRotation(newDirection*90);
}

void BaseTank::shot()
{
    //create new bullet
    Bullet *bullet = new Bullet(getDirection());

    //set bullet's position
    int bX;
    int bY;
    switch (this->getDirection())
    {
    case 0:
        bX = x() + this->rect().center().x() - bullet->rect().width()/2;
        bY = y() - 2*bullet->rect().height();
        break;
    case 1:
        bX = x() + this->rect().width() + 3*bullet->rect().height();
        bY = y() + this->rect().center().y() - bullet->rect().width()/2;
        break;
    case 2:
        bX = x() + this->rect().center().x() + bullet->rect().width()/2;
        bY = y() + this->rect().height() + 2*bullet->rect().height();
        break;
    case 3:
        bX = x() - 3*bullet->rect().width();
        bY = y() + this->rect().center().y() + bullet->rect().width()/2;
        break;
    }
    bullet->setPos(bX, bY);
    game->scene->addItem(bullet);
}


int BaseTank::checkPosition()
{
    int rX = x()+rect().width()/2;
    int rY = y()+rect().height()/2;

    int a = rX / rect().width();
    int b = rY / rect().height();
    switch (getDirection())
    {
    case 1:
        a++;
        break;
    case 2:
        b++;
        break;
    case 3:
        a--;
        break;
    default:
        b--;
        break;
    }
    return game->check(b,a);
}
