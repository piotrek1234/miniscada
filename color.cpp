#include "color.h"

Color::Color()
{
}

void Color::setRGB(char R, char G, char B)
{
    this->R = R;
    this->G = G;
    this->B = B;
}

char Color::getR()
{
    return this->R;
}

char Color::getG()
{
    return this->G;
}

char Color::getB()
{
    return this->B;
}

void Color::setAlpha(char alpha)
{
    this->alpha = alpha;
}

char Color::getAlpha()
{
    return this->alpha;
}
