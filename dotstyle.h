#ifndef DOTSTYLE_H
#define DOTSTYLE_H

#include <QColor>

enum Shape{
    square,
    circle,
    triangle
};

class DotStyle
{
public:
    DotStyle(QColor color = Qt::black, Shape shape = circle, int size = 2);
    void setColor(QColor color);
    QColor getColor();
    void setShape(Shape shape);
    Shape getShape();
    void setSize(int size);
    int getSize();
private:
    QColor color;
    Shape shape;
    int size;
};

#endif // DOTSTYLE_H
