#include "BaseElement.h"

#define cell 50

class Headquarters : public BaseElement
{
public:
    Headquarters(int a, int b);
    void sayMyName();

protected:
    int x;
    int y;
};
