#pragma once

#include <QObject>
#include <QGraphicsRectItem>

class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Bullet(int newBDirection);
    ~Bullet();

public slots:
    void move();

private:
    int bDirection;
    QTimer *timer;
};
