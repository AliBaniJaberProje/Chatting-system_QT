#-------------------------------------------------
#
# Project created by QtCreator 2019-11-10T22:29:51
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HW_E
TEMPLATE = app


SOURCES += main.c++\
        mainwindow.c++ \
    user2.c++

HEADERS  += mainwindow.h \
    user2.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc \
    pp.qrc
