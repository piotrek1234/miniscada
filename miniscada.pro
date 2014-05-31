#-------------------------------------------------
#
# Project created by QtCreator 2014-05-18T11:14:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = miniscada
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    geometry.cpp \
    font.cpp \
    color.cpp \
    dotstyle.cpp \
    linestyle.cpp \
    serie.cpp \
    icon.cpp \
    label.cpp \
    legend.cpp \
    axis.cpp \
    chart.cpp

HEADERS  += mainwindow.h \
    geometry.h \
    font.h \
    color.h \
    dotstyle.h \
    linestyle.h \
    serie.h \
    icon.h \
    orientation.h \
    label.h \
    legend.h \
    axis.h \
    chart.h

FORMS    += mainwindow.ui
