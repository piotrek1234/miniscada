#include "label.h"

Label::Label()
{
}

Label::Label(QString text, Geometry geometry, Icon icon, QFont font, Orientation orientation)
{
    this->text = text;
    this->geometry = geometry;
    this->icon = icon;
    this->font = font;
    this->orientation = orientation;
}

void Label::setText(QString text)
{
    this->text = text;
}

QString Label::getText()
{
    return this->text;
}

void Label::setFont(QFont font)
{
    this->font = font;
}

QFont Label::getFont()
{
    return this->font;
}

void Label::setGeometry(Geometry geometry)
{
    this->geometry = geometry;
}

Geometry &Label::getGeometry()
{
    return this->geometry;
}

void Label::setIcon(Icon icon)
{
    this->icon = icon;
}

Icon &Label::getIcon()
{
    return this->icon;
}

void Label::setOrientation(Orientation orientation)
{
    this->orientation = orientation;
}

Orientation Label::getOrientation()
{
    return this->orientation;
}

QPixmap &Label::getPixmap()
{
    return this->pixmap;
}

QPixmap Label::draw()
{
    QFontMetrics fm(this->getFont());
    int textWidth = fm.width(this->text);
    int textHeight = fm.height();

    int wys = this->icon.getGeometry().getHeight()>textHeight?this->icon.getGeometry().getHeight():textHeight;

    this->setGeometry(Geometry(0, 0, 15+textWidth+this->icon.getGeometry().getWidth(), 10+wys));

    QPixmap temp(this->getGeometry().getWidth(), this->getGeometry().getHeight());
    QPainter p;
    p.begin(&temp);
    p.fillRect(0, 0, temp.width(), temp.height(), Qt::white);
    p.setFont(this->getFont());
    p.fillRect(5, (this->getGeometry().getHeight()-this->icon.getGeometry().getHeight())/2, this->icon.getGeometry().getWidth(), this->icon.getGeometry().getWidth(), this->icon.getColor());
    p.drawText(10+this->icon.getGeometry().getWidth(), (this->getGeometry().getHeight()+textHeight)/2-5, this->text);

    p.end();

    return temp;
}

void Label::refresh()
{
    this->pixmap = this->draw();
}
