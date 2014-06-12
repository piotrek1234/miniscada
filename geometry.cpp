#include "geometry.h"

/**
 * @brief Geometry::Geometry
 *
 *Domyślny konstruktor Geometry, ustawia wszystkie pola na 0
 */
Geometry::Geometry()
{
    this->x = 0;
    this->y = 0;
    this->width = 0;
    this->height = 0;
}

/**
 * @brief Geometry::Geometry
 * @param geometry klasa do skopiowania
 */
Geometry::Geometry(const Geometry &geometry)
{
    this->x = geometry.x;
    this->y = geometry.y;
    this->width = geometry.width;
    this->height = geometry.height;
}

/**
 * @brief Geometry::Geometry
 * @param x pozycja pozioma
 * @param y pozycja pionowa
 * @param width szerokość
 * @param height wysokość
 */
Geometry::Geometry(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

/**
 * @brief Geometry::setXY
 * @param x pozycja pozioma
 * @param y pozycja pionowa
 */
void Geometry::setXY(int x, int y)
{
    this->x = x;
    this->y = y;
}

/**
 * @brief Geometry::getX
 * @return pozycja pozioma
 */
int Geometry::getX()
{
    return this->x;
}

/**
 * @brief Geometry::getY
 * @return pozycja pionowa
 */
int Geometry::getY()
{
    return this->y;
}

/**
 * @brief Geometry::setWidth
 * @param width szerokość
 */
void Geometry::setWidth(int width)
{
    this->width = width;
}

/**
 * @brief Geometry::getWidth
 * @return szerokość
 */
int Geometry::getWidth()
{
    return this->width;
}

/**
 * @brief Geometry::setHeight
 * @param height wysokość
 */
void Geometry::setHeight(int height)
{
    this->height = height;
}

/**
 * @brief Geometry::getHeight
 * @return wysokość
 */
int Geometry::getHeight()
{
    return this->height;
}
