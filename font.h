#ifndef FONT_H
#define FONT_H

//#include "color.h"
#include <QColor>
#include <QString>

class Font
{
public:
    Font();
    void setName(QString name);
    QString getName();
    void setSize(int size);
    int getSize();
    void setColor(QColor color);
    QColor getColor();
private:
    QString name;
    int size;
    QColor color;
};

#endif // FONT_H
