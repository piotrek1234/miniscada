#include "chart.h"

Chart::Chart()
{
}

QPixmap Chart::draw()
{
    QPixmap temp(this->background.width(), this->background.height());
    QPainter p;
    p.begin(&temp);
    p.fillRect(0, 0, temp.width(), temp.height(), Qt::white);
    p.drawPixmap(0, 0, this->background);
    int x=0;
    int y=this->getAxisY(0).getGeometry().getHeight()-10;
    for(int i=0; i<this->getAxisCount(); i++)
    {
        if(this->getAxisY(i).getPosition() == left)
            x+= this->getAxisY(i).draw().width();
    }

    //dla każdej serii czy tam osi
    const double scale = double(this->getAxisY(0).getGeometry().getHeight()-20)/(this->getAxisY(0).getMax()-this->getAxisY(0).getMin());
    for(int i=0; i<this->getSerie(0)->getLength()-1; i++)
    {
        p.drawLine(x+i*20, y-scale*(this->getSerie(0)->getPoint(i)-this->getAxisY(0).getMin()), (i+1)*20+x, y-scale*(this->getSerie(0)->getPoint(i+1)-this->getAxisY(0).getMin()));
    }

    p.end();
    return temp;
}

void Chart::drawBackground()
{
    int width = 0, yWidth = 0;
    for(int i=0; i<this->getAxisCount(); i++)
    {
        this->getAxisY(i).draw();
        if(this->getAxisY(i).getPosition() == left)
            yWidth+= this->getAxisY(i).getGeometry().getWidth();
        width += this->getAxisY(i).getGeometry().getWidth();
    }

    //do poprawy:
    width -= this->getAxisY(this->getAxisCount()-1).getTickSize();

    width += this->getAxisX().getGeometry().getWidth();
    width += this->legend.getGeometry().getWidth();

    int height = 0;
    height += this->getAxisY(0).getGeometry().getHeight();
    height += this->getAxisX().getGeometry().getHeight();

    //QPixmap temp(this->getGeometry().getWidth(), this->getGeometry().getHeight());
    QPixmap temp(width, height);
    QPainter p;
    p.begin(&temp);
    p.fillRect(0, 0, temp.width(), temp.height(), Qt::white);

    int prevWidth = 0;
    //oś x
    p.drawPixmap(yWidth-11-this->getAxisY(0).getTickSize(), this->getAxisY(0).getGeometry().getHeight()-10, this->getAxisX().draw());
    //lewe osie y
    for(int i=0; i<this->getAxisCount(); i++)
    {
        if(this->getAxisY(i).getPosition() == left)
        {
            p.drawPixmap(prevWidth, 0, this->getAxisY(i).draw());
            prevWidth+= this->getAxisY(i).getGeometry().getWidth();
        }
    }
    //prawe osie y
    prevWidth += this->getAxisX().getGeometry().getWidth()-20;
    for(int i=0; i<this->getAxisCount(); i++)
    {
        if(this->getAxisY(i).getPosition() == right)
        {
            p.drawPixmap(prevWidth, 0, this->getAxisY(i).draw());
            prevWidth+= this->getAxisY(i).getGeometry().getWidth();
        }
    }

    p.drawPixmap(width-this->legend.getGeometry().getWidth(), 0, this->getLegend().draw());

    //p.drawPixmap();

    p.end();
    this->background = temp;
}

void Chart::setGeometry(Geometry geometry)
{
    this->geometry = geometry;
}

Geometry &Chart::getGeometry()
{
    return this->geometry;
}

void Chart::addSerie(Serie *serie)
{
    series.push_back(serie);
}

void Chart::removeSerie(int id)
{
    series.erase(series.begin()+id);
}

Serie *Chart::getSerie(int id)
{
    return series.at(id);
}

void Chart::setLabel(Label label)
{
    this->label = label;
}

Label &Chart::getLabel()
{
    return this->label;
}

void Chart::setTick(double tick)
{
    this->tick = tick;
}

double Chart::getTick()
{
    return this->tick;
}

void Chart::setGridStyle(LineStyle style)
{
    this->gridStyle = style;
}

LineStyle Chart::getGridStyle()
{
    return this->gridStyle;
}

void Chart::setLegend(Legend legend)
{
    this->legend = legend;
}

Legend &Chart::getLegend()
{
    return this->legend;
}

void Chart::setAxisX(Axis axis)
{
    this->axisX = axis;
}

Axis &Chart::getAxisX()
{
    return this->axisX;
}

void Chart::addAxisY(Axis axis)
{
    this->axisY.push_back(axis);
}

void Chart::removeAxisY(int id)
{
    axisY.erase(axisY.begin()+id);
}

Axis &Chart::getAxisY(int id)
{
    return axisY.at(id);
}

void Chart::setGridVisibility(bool visible)
{
    this->showGrid = visible;
}

bool Chart::getGridVisibility()
{
    return this->showGrid;
}

void Chart::setLegendVisibility(bool visible)
{
    this->showLegend = visible;
}

bool Chart::getLegendVisibility()
{
    return this->showLegend;
}

void Chart::setLabelVisibility(bool visible)
{
    this->showLabel = visible;
}

bool Chart::getLabelVisibility()
{
    return this->showLabel;
}

int Chart::getAxisCount()
{
    return this->axisY.size();
}

int Chart::getSeriesCount()
{
    return this->series.size();
}
