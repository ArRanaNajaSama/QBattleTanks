#pragma once

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

enum BaseElementID {headquartersID, wallID, armoredWallID, tileID};

class BaseElement : public QGraphicsPixmapItem
{
//factory method
public:
    static BaseElement *makeElement(BaseElementID baseID, int a, int b);
    virtual void sayMyName() = 0;
    virtual ~BaseElement();
};
