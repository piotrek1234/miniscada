#include "geometry.h"

Geometry::Geometry()
{
}

Geometry::Geometry(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Geometry::setXY(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Geometry::getX()
{
    return this->x;
}

int Geometry::getY()
{
    return this->y;
}

void Geometry::setWidth(int width)
{
    this->width = width;
}

int Geometry::getWidth()
{
    return this->width;
}

void Geometry::setHeight(int height)
{
    this->height = height;
}

int Geometry::getHeight()
{
    return this->height;
}
