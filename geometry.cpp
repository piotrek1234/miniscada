#include "geometry.h"

Geometry::Geometry()
{
    this->x = 0;
    this->y = 0;
    this->width = 0;
    this->height = 0;
}

Geometry::Geometry(const Geometry &geometry)
{
    this->x = geometry.x;
    this->y = geometry.y;
    this->width = geometry.width;
    this->height = geometry.height;
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

void Geometry::setWH(int width, int height)
{
    this->width = width;
    this->height = height;
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
