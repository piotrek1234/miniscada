#include "linestyle.h"

LineStyle::LineStyle()
{
}

void LineStyle::setColor(QColor color)
{
    this->color = color;
}

QColor LineStyle::getColor()
{
    return this->color;
}

void LineStyle::setWidth(int width)
{
    this->width = width;
}

int LineStyle::getWidth()
{
    return this->width;
}

void LineStyle::setType(Qt::PenStyle type)
{
    this->type = type;
}

Qt::PenStyle LineStyle::getType()
{
    return this->type;
}
