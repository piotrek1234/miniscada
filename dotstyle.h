#ifndef DOTSTYLE_H
#define DOTSTYLE_H

#include "color.h"

enum Shape{
    square,
    circle,
    triangle
};

class DotStyle
{
public:
    DotStyle();
    void setColor(Color color);
    Color getColor();
    void setShape(Shape shape);
    Shape getShape();
    void setSize(int size);
    int getSize();
private:
    Color color;
    Shape shape;
    int size;
};

#endif // DOTSTYLE_H
