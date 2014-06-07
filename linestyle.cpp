#include "linestyle.h"

//LineStyle::LineStyle()
//{
//    this->color = Qt::black;
//    this->width = 1;
//    this->type = Qt::SolidLine;
//}

LineStyle::LineStyle(int width, QColor color, Qt::PenStyle lineType)
{
    this->width = width;
    this->color = color;
    this->type = lineType;
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
