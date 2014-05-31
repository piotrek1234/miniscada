#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "label.h"
#include "geometry.h"
#include "icon.h"
#include "axis.h"
#include "legend.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Label l;
    l.setGeometry(Geometry(10, 10));
    l.setOrientation(horizontal);
    l.setText("test comic sansa gghjghjg jhfjj ngb 76p ' '''][].gfd");
    l.setFont(QFont("comic sans ms", 10));
    l.setIcon(Icon(Geometry(0,0,20,20), Qt::green));

    Label l2;
    l2.setGeometry(Geometry(10, 10));
    l2.setOrientation(horizontal);
    l2.setText("test Tajmsa");
    l2.setFont(QFont("times new roman", 20));
    l2.setIcon(Icon(Geometry(0,0,5,5), Qt::red));

    /*leg.addLabel(Label("Etykieta 1", Geometry(0, 0, 0, 20), Icon(Qt::red)));
    leg.addLabel(Label("Etykieta 2", Geometry(0, 0, 0, 20), Icon(Qt::yellow)));
    leg.addLabel(Label("Etykieta 3", Geometry(0, 0, 0, 20), Icon(Qt::darkYellow)));
    leg.addLabel(Label("Etykieta 4", Geometry(0, 0, 0, 20), Icon(Qt::darkRed)));
    leg.addLabel(Label("Etykieta 5", Geometry(0, 0, 0, 20), Icon(Qt::cyan)));
    leg.addLabel(Label("Etykieta 6", Geometry(0, 0, 0, 20), Icon(Qt::magenta)));*/
    Axis x;
    x.setFont(QFont("arial", 10));
    x.setTick(20);
    x.setTickDirection(inside);
    x.setTickSize(5);
    x.setMax(100);
    x.setMin(0);
    x.setPosition(bottom);
    x.setUnitVisibility(false);
    x.setGeometry(Geometry(0, 0, 400, 30));

    ch.setAxisX(x);
    x.setPosition(left);
    x.setGeometry(Geometry(0, 0, 40, 400));
    ch.addAxisY(x);
    ch.setGeometry(Geometry(0, 0, 500, 500));

    s = new Serie;
    s->setLength(5);
    s->setTick(20);
    s->addPoint(0);
    s->addPoint(50);
    s->addPoint(20);
    s->addPoint(90);
    s->addPoint(50);
    ch.addSerie(s);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete s;
}

void MainWindow::on_pushButton_clicked()
{
    ch.drawBackground();
    ui->label->setPixmap(ch.draw());
}
