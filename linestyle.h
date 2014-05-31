#ifndef LINESTYLE_H
#define LINESTYLE_H

//#include "color.h"
#include <QColor>

class LineStyle
{
public:
    LineStyle();
    void setColor(QColor color);
    QColor getColor();
    void setWidth(int width);
    int getWidth();
    void setType(Qt::PenStyle type);
    Qt::PenStyle getType();
private:
    QColor color;
    int width;
    Qt::PenStyle type;
};

const LineStyle defaultLineStyle;

#endif // LINESTYLE_H
