#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <typeinfo>

#include "BaseTank.h"
#include "EnemyTank.h"
#include "Game.h"
#include "Field/Wall.h"

extern Game *game;

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

void BaseTank::move(int newDirection)
{
    // prevent collision;
    this->setDirection(newDirection);
    premotion->move(direction);

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
    int bulletX;
    int bulletY;
    switch (this->getDirection())
    {
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


int BaseTank::checkPosition()
{
    int realX = pos().x()+rect().width()/2;
    int realY = pos().y()+rect().height()/2;

    int k = realX / rect().width();
    int m = realY / rect().height();
    switch (direction) {
    case 1:
        k++;
        break;
    case 2:
        m++;
        break;
    case 3:
        k--;
        break;
    default:
        m--;
        break;
    }
    return game->check(m,k);
}

void BaseTank::setMotion(PreMotion *newMotion)
{
    premotion = newMotion;
}

