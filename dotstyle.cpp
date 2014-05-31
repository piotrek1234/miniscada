#include "dotstyle.h"

DotStyle::DotStyle()
{
}

void DotStyle::setColor(Color color)
{
    this->color = color;
}

Color DotStyle::getColor()
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
