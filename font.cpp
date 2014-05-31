#include "font.h"


Font::Font()
{
}

void Font::setName(QString name)
{
    this->name = name;
}

QString Font::getName()
{
    return this->name;
}

void Font::setSize(int size)
{
    this->size = size;
}

int Font::getSize()
{
    return this->size;
}

void Font::setColor(QColor color)
{
    this->color = color;
}

QColor Font::getColor()
{
    return this->color;
}
