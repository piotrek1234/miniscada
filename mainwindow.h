#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <label.h>
#include "legend.h"
#include "chart.h"
#include "serie.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    //int i;
    //Legend leg;
    Chart ch;
    Serie* s;
    QColor kolor;
};

#endif // MAINWINDOW_H
