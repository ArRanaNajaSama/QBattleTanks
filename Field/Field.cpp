#include <QGraphicsScene>
#include <QGraphicsView>

#include "Field.h"

extern QGraphicsScene *scene;
extern QGraphicsView *view;

Field::Field(int a, int b, QVector <int> init)
{
    width = a;
    height = b;
    fieldMatrix = init;

    //go through fieldMatrix and in acc with its data fill elements;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            switch(fieldMatrix[i+j*width]){
            case 1:
                elements.push_back(BaseElement::makeElement(wallID,j,i));
                scene->addItem(elements.back());
                break;
            case 2:
                elements.push_back(BaseElement::makeElement(armoredWallID,j,i));
                scene->addItem(elements.back());
                break;
            case 3:
                elements.push_back(BaseElement::makeElement(headquartersID,j,i));
                scene->addItem(elements.back());
                break;
            default:
                elements.push_back(NULL);
                break;
            }
        }
    }
}

Field::~Field()
{

}

int Field::check(int a, int b)
{
    if (fieldMatrix[a+b*width] != 0)
    {
        return 0;
    }
    else
        return 1;
}

void Field::destroy(BaseElement* base)
{
    for(int i = 0 ; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (elements[i+j*width] == base){
                scene->removeItem(elements[i+j*width]);
                delete elements[i+j*width];
                elements[i+j*width]=NULL;
                fieldMatrix[j+i*width] = 0;
            }
        }
    }
}

void Field::destroy(int i, int j)
{
    scene->removeItem(elements[i+j*width]);
    delete elements[i+j*width];
    elements[i+j*width]=NULL;
    fieldMatrix[j+i*width] = 0;
}
