#ifndef CHART_H
#define CHART_H

#include <QPixmap>
#include <vector>
#include "label.h"
#include "linestyle.h"
#include "legend.h"
#include "axis.h"
#include "serie.h"
#include "geometry.h"

class Chart
{
public:
    Chart();
    QPixmap draw();
    void drawBackground();
    void setGeometry(Geometry geometry);
    Geometry &getGeometry();
    void addSerie(Serie* serie);
    void removeSerie(int id);
    Serie* getSerie(int id);
    void setLabel(Label label);
    Label &getLabel();
    void setTick(double tick);
    double getTick();
    void setGridStyle(LineStyle style);
    LineStyle getGridStyle();
    void setLegend(Legend legend);
    Legend &getLegend();
    void setAxisX(Axis axis);
    Axis &getAxisX();
    void addAxisY(Axis axis);
    void removeAxisY(int id);
    Axis &getAxisY(int id);
    void setGridVisibility(bool visible);
    bool getGridVisibility();
    void setLegendVisibility(bool visible);
    bool getLegendVisibility();
    void setLabelVisibility(bool visible);
    bool getLabelVisibility();
    int getAxisCount();
    int getSeriesCount();
private:
    std::vector<Serie*> series;
    Label label;
    Geometry geometry;
    double tick;
    LineStyle gridStyle;
    Legend legend;
    Axis axisX;
    std::vector<Axis> axisY;
    bool showGrid;
    bool showLegend;
    bool showLabel;
    QPixmap background;
};

#endif // CHART_H
