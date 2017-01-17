#pragma once

#include <QGraphicsItem>
#include <QGraphicsRectItem>

enum BaseElementID {headquartersID, wallID, armoredWallID};

class BaseElement : public QGraphicsRectItem
{
//factory method
public:
    static BaseElement *makeElement(BaseElementID baseID, int a, int b);
    virtual void sayMyName() = 0;
    virtual ~BaseElement();
};
