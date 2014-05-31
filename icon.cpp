#include "icon.h"

Icon::Icon()
{
}

Icon::Icon(QColor color, Geometry geometry)
{
    this->color = color;
    this->geometry = geometry;
}

Icon::Icon(Geometry geometry, QColor color)
{
    this->geometry = geometry;
    this->color = color;
}

void Icon::setGeometry(Geometry geometry)
{
    this->geometry = geometry;
}

Geometry Icon::getGeometry()
{
    return this->geometry;
}

void Icon::setColor(QColor color)
{
    this->color = color;
}

QColor Icon::getColor()
{
    return this->color;
}
