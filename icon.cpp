#include "icon.h"
#include <stdlib.h>

Icon::Icon()
{
    this->color = QColor((float)qrand()/RAND_MAX*255, (float)qrand()/RAND_MAX*255, (float)qrand()/RAND_MAX*255);
    this->geometry = Geometry(0, 0, 10, 10);
}

Icon::Icon(QColor color, Geometry geometry)
{
    this->color = color;
    this->geometry = geometry;
}

/*Icon::Icon(Geometry geometry, QColor color)
{
    this->geometry = Geometry(geometry);
    this->color = color;
}*/

void Icon::setGeometry(Geometry geometry)
{
    this->geometry = geometry;
}

Geometry &Icon::getGeometry()
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
