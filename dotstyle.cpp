#include "dotstyle.h"

DotStyle::DotStyle(QColor color, Shape shape, int size)
{
    this->color = color;
    this->shape = shape;
    this->size = size;
}

void DotStyle::setColor(QColor color)
{
    this->color = color;
}

QColor DotStyle::getColor()
{
    return this->color;
}

void DotStyle::setShape(Shape shape)
{
    this->shape = shape;
}

Shape DotStyle::getShape()
{
    return this->shape;
}

void DotStyle::setSize(int size)
{
    this->size = size;
}

int DotStyle::getSize()
{
    return this->size;
}
