#-------------------------------------------------
#
# Project created by QtCreator 2018-08-14T20:50:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = beatMouse1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myscence.cpp \
    myitem.cpp \
    handler.cpp

HEADERS  += mainwindow.h \
    myscence.h \
    myitem.h \
    handler.h

FORMS    += mainwindow.ui

RESOURCES += \
    img.qrc
