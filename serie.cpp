#include "serie.h"

/**
 * @brief Serie::Serie
 */
Serie::Serie()
{
    this->dotsStyle = DotStyle();
    this->lineStyle = LineStyle();
    this->length = 2;
    this->pointsConnected = true;
    this->showDots = false;
    this->pointsConnectingStyle = line;
    this->axisId = 0;
}

/**
 * @brief Serie::addPoint
 * @param value wartość punktu
 */
void Serie::addPoint(double value)
{
    points.push_back(value);
    if(points.size()>length)
        points.erase(points.begin());
}

/**
 * @brief Serie::clear
 *czyści punkty
 */
void Serie::clear()
{
    points.clear();
}

/**
 * @brief Serie::getPoint
 * @param id numer punktu do pobrania
 * @return wartość punktu
 */
double Serie::getPoint(int id)
{
    return points.at(id);
}

/**
 * @brief Serie::setLength
 * @param length rozmiar bufora
 */
void Serie::setLength(int length)
{
    this->length = length;
}

/**
 * @brief Serie::getLength
 * @return rozmiar bufora
 */
int Serie::getLength()
{
    if(points.size()<length)
        return points.size();
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

/**
 * @brief Serie::setLineStyle
 * @param style styl linii
 */
void Serie::setLineStyle(LineStyle style)
{
    this->lineStyle = style;
}

/**
 * @brief Serie::getLineStyle
 * @return styl linii
 */
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

/**
 * @brief Serie::setAxisId
 * @param id numer osi, do której dopasowane będą wartości
 */
void Serie::setAxisId(int id)
{
    this->axisId = id;
}

/**
 * @brief Serie::getAxisId
 * @return numer osi, do której dopasowane będą wartości
 */
int Serie::getAxisId()
{
    return this->axisId;
}
