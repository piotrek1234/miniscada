#include "legend.h"

//Legend::Legend()
//{
//    this->geometry = Geometry(0, 0, 0, 0);
//    this->orientation = vertical;
//}

Legend::Legend(Orientation orientation)
{
    this->geometry = Geometry(0, 0, 0, 0);
    this->orientation = orientation;
}

void Legend::addLabel(Label label)
{
    this->labels.push_back(label);

    int width=0, height=0;
    for(int i=0; i<this->getLabelsCount(); i++)
    {
        labels.at(i).refresh();
        if(labels.at(i).getGeometry().getWidth() > width)
            width = labels.at(i).getGeometry().getWidth();
        height += labels.at(i).getGeometry().getHeight();
    }
    this->setGeometry(Geometry(0, 0, width, height));
}

void Legend::removeLabel(int id)
{
    this->labels.erase(labels.begin()+id);

    int width=0, height=0;
    for(int i=0; i<this->getLabelsCount(); i++)
    {
        labels.at(i).refresh();
        if(labels.at(i).getGeometry().getWidth() > width)
            width = labels.at(i).getGeometry().getWidth();
        height += labels.at(i).getGeometry().getHeight();
    }
    this->setGeometry(Geometry(0, 0, width, height));
}

Label &Legend::getLabel(int id)
{
    return this->labels[id];
}

void Legend::setOrientation(Orientation orientation)
{
    this->orientation = orientation;
}

Orientation Legend::getOrientation()
{
    return this->orientation;
}

void Legend::setGeometry(Geometry geometry)
{
    this->geometry = geometry;
}

Geometry &Legend::getGeometry()
{
    return this->geometry;
}

int Legend::getLabelsCount()
{
    return this->labels.size();
}

QPixmap Legend::draw()
{
    int width=0, height=0, y=0;
    for(int i=0; i<this->getLabelsCount(); i++)
    {
        //this->labels[labels.begin()+i].refresh();
        labels.at(i).refresh();
        if(labels.at(i).getGeometry().getWidth() > width)
            width = labels.at(i).getGeometry().getWidth();
        height += labels.at(i).getGeometry().getHeight();
    }

    QPixmap temp(width, height);
    QPainter p;
    p.begin(&temp);
    p.fillRect(0, 0, width, height, Qt::white);

    for(int i=0; i<this->getLabelsCount(); i++)
    {
        p.drawPixmap(0, y, labels.at(i).getPixmap());
        y+= labels.at(i).getGeometry().getHeight();
    }

    p.end();
    this->setGeometry(Geometry(0, 0, width, height));

    return temp;
}

void Legend::refresh()
{
    this->pixmap = this->draw();
}
