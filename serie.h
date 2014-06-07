#ifndef SERIE_H
#define SERIE_H

#include "dotstyle.h"
#include "linestyle.h"
#include <vector>

enum ConnectingStyle{
    line,
    spline,
    none
};

class Serie
{
public:
    Serie();
    void addPoint(double value);
    void clear();
    double getPoint(int id);
    void setLength(int length);
    int getLength();
    void setTick(double tick);
    double getTick();
    void setLineStyle(LineStyle style);
    LineStyle getLineStyle();
    void setPointsConnectingStyle(ConnectingStyle style);
    ConnectingStyle getPointsConnectingStyle();
    bool getPointsConnected();
    void setPointsConnected(bool connected);
    void setDotsVisibility(bool visible);
    bool getDotsVisibility();
    void setDotStyle(DotStyle style);
    DotStyle getDotStyle();
    void setAxisId(int id);
    int getAxisId();
private:
    std::vector<double> points;
    int length;
    double tick;
    LineStyle lineStyle;
    ConnectingStyle pointsConnectingStyle;
    bool pointsConnected;
    bool showDots;
    DotStyle dotsStyle;
    int axisId;
};

#endif // SERIE_H
