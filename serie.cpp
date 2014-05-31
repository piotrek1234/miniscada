#include "serie.h"

Serie::Serie()
{
}

void Serie::addPoint(double value)
{
    points.push_back(value);
    if(points.size()>length)
        points.erase(points.begin());
}

void Serie::clear()
{
    points.clear();
}

double Serie::getPoint(int id)
{
    return points.at(id);
}

void Serie::setLength(int length)
{
    this->length = length;
}

int Serie::getLength()
{
    return this->length;
}

void Serie::setTick(double tick)
{
    this->tick = tick;
}

double Serie::getTick()
{
    return this->tick;
}

void Serie::setLineStyle(LineStyle style)
{
    this->lineStyle = style;
}

LineStyle Serie::getLineStyle()
{
    return this->lineStyle;
}

void Serie::setPointsConnectingStyle(ConnectingStyle style)
{
    this->pointsConnectingStyle = style;
}

ConnectingStyle Serie::getPointsConnectingStyle()
{
    return this->pointsConnectingStyle;
}

bool Serie::getPointsConnected()
{
    return this->pointsConnected;
}

void Serie::setPointsConnected(bool connected)
{
    this->pointsConnected = connected;
}

void Serie::setDotsVisibility(bool visible)
{
    this->showDots = visible;
}

bool Serie::getDotsVisibility()
{
    return this->showDots;
}

void Serie::setDotStyle(DotStyle style)
{
    this->dotsStyle = style;
}

DotStyle Serie::getDotStyle()
{
    return this->dotsStyle;
}
