#include "axis.h"

Axis::Axis()
{

}

void Axis::setLabel(Label label)
{
    this->label = label;
}

Label &Axis::getLabel()
{
    return this->label;
}

void Axis::setLineStyle(LineStyle style)
{
    this->lineStyle = style;
}

LineStyle &Axis::getLineStyle()
{
    return this->lineStyle;
}

void Axis::setTick(double tick)
{
    this->tick = tick;
}

double Axis::getTick()
{
    return this->tick;
}

void Axis::setAutoscale(bool autoscale)
{
    this->autoscale = autoscale;
}

bool Axis::getAutoscale()
{
    return this->autoscale;
}

void Axis::setMin(double min)
{
    this->min = min;
}

double Axis::getMin()
{
    return this->min;
}

void Axis::setMax(double max)
{
    this->max = max;
}

double Axis::getMax()
{
    return this->max;
}

void Axis::setTickSize(int size)
{
    this->tickSize = size;
}

int Axis::getTickSize()
{
    return this->tickSize;
}

void Axis::setTickDirection(Direction direction)
{
    this->tickDirection = direction;
}

Direction Axis::getTickDirection()
{
    return this->tickDirection;
}

void Axis::setUnitVisibility(bool visible)
{
    this->showUnit = visible;
}

bool Axis::getUnitVisibility()
{
    return this->showUnit;
}

void Axis::setFont(QFont font)
{
    this->font = font;
}

QFont Axis::getFont()
{
    return this->font;
}

void Axis::setPosition(Position position)
{
    this->position = position;
}

Position Axis::getPosition()
{
    return this->position;
}

void Axis::setUnit(QString unit)
{
    this->unit = unit;
}

QString Axis::getUnit()
{
    return this->unit;
}

void Axis::setGeometry(Geometry geometry)
{
    this->geometry = geometry;
}

Geometry &Axis::getGeometry()
{
    return this->geometry;
}

QPixmap Axis::draw()
{
    QFontMetrics fm(this->getFont());
    const int tickCount = (this->max-this->min)/this->tick;
    const QString unit = this->showUnit?" "+this->unit:"";
    int textWidth = fm.width(QString::number(this->max)+unit);
    int textHeight = fm.height();
    QPixmap temp;
    float space;

    //najdluzszy tekst
    for(int i=1; i<=tickCount; i++)
    {
        if(fm.width(QString::number(this->max-tick*i)+unit) > textWidth)
            textWidth = fm.width(QString::number(this->max-tick*i)+unit);
    }

    if(position==left || position==right)
    {
        //this->setGeometry(Geometry(0,0,textWidth+6+this->tickSize, this->geometry.getHeight()));
        temp = QPixmap(textWidth+6+this->tickSize, this->geometry.getHeight());
        space = (temp.height()-20)/(max-min)*tick;
    }
    else
    {
        //this->setGeometry(Geometry(0, 0, this->geometry.getWidth(), textHeight+6+tickSize));
        temp = QPixmap(this->geometry.getWidth(), textHeight+6+this->tickSize);
        space = (temp.width()-20)/(max-min)*tick;
    }

    QPainter p;
    p.begin(&temp);
    p.fillRect(0, 0, temp.width(), temp.height(), Qt::white);
    p.setFont(this->getFont());

    if(position==left)
    {
        if(tickDirection==inside)
            p.drawLine(textWidth+5, 10, textWidth+5, temp.height()-10);
        else if(tickDirection == middle)
            p.drawLine(textWidth+5+tickSize/2, 10, textWidth+5+tickSize/2, temp.height()-10);
        else
            p.drawLine(textWidth+5+tickSize, 10, textWidth+5+tickSize, temp.height()-10);

        for(int i=tickCount; i>=0; i--)
        {
            p.drawLine(textWidth+5, temp.height()-10-i*space, textWidth+5+tickSize, temp.height()-10-i*space);
            p.drawText(0, temp.height()-10-i*space-textHeight/2, textWidth, textHeight, Qt::AlignRight, QString::number(min+tick*i)+unit);
        }
        p.drawLine(textWidth+5, 10, textWidth+5+tickSize, 10);
    }
    else if(position == right)
    {
        if(tickDirection==inside)
            p.drawLine(1+tickSize, 10, 1+tickSize, temp.height()-10);
        else if(tickDirection == middle)
            p.drawLine(1+tickSize/2, 10, 1+tickSize/2, temp.height()-10);
        else
            p.drawLine(1, 10, 1, temp.height()-10);

        for(int i=tickCount; i>=0; i--)
        {
            p.drawLine(1, temp.height()-10-i*space, 1+tickSize, temp.height()-10-i*space);
            p.drawText(6+tickSize, temp.height()-10-i*space-textHeight/2, textWidth, textHeight, Qt::AlignLeft, QString::number(min+tick*i)+unit);
        }
        p.drawLine(1, 10, 1+tickSize, 10);
    }
    else if(position == bottom)
    {
        if(tickDirection==outside)
            p.drawLine(10, 1, temp.width()-10, 1);
        else if(tickDirection == middle)
            p.drawLine(10, 1+tickSize/2, temp.width()-10, 1+tickSize/2);
        else
            p.drawLine(10, 1+tickSize, temp.width()-10, 1+tickSize);

        for(int i=tickCount; i>=0; i--)
        {
            p.drawLine(10+i*space, 1, 10+i*space, 1+tickSize);
            //p.drawText(6+tickSize, temp.height()-10-i*space+textHeight/2, QString::number(min+tick*i)+unit);
        }
        p.drawLine(temp.width()-10, 1, temp.width()-10, 1+tickSize);
    }
    else    //top
    {
        if(tickDirection==outside)
            p.drawLine(10, 5+tickSize+textHeight, temp.width()-10, 5+tickSize+textHeight);
        else if(tickDirection == middle)
            p.drawLine(10, 5+tickSize/2+textHeight, temp.width()-10, 5+tickSize/2+textHeight);
        else
            p.drawLine(10, 5+textHeight, temp.width()-10, 5+textHeight);

        for(int i=tickCount; i>=0; i--)
        {
            p.drawLine(10+i*space, 6+textHeight, 10+i*space, 6+tickSize+textHeight);
            //p.drawText(6+tickSize, temp.height()-10-i*space+textHeight/2, QString::number(min+tick*i)+unit);
        }
        p.drawLine(temp.width()-10, 6+textHeight, temp.width()-10, 6+tickSize+textHeight);
    }

    p.end();
    this->geometry.setWidth(temp.width());
    this->geometry.setHeight(temp.height());

    return temp;
}
