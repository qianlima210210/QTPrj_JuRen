#-------------------------------------------------
#
# Project created by QtCreator 2016-07-24T13:45:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled12
TEMPLATE = app


SOURCES += main.cpp\
    grouplistview.cpp \
    grouplistviewdelegate.cpp \
    grouplistviewmodel.cpp \
    groupwidget.cpp \
    grouptitlewidget.cpp \
    people.cpp \
    group.cpp \
    groupbase.cpp

HEADERS  += \
    grouplistview.h \
    grouplistviewdelegate.h \
    grouplistviewmodel.h \
    groupwidget.h \
    grouptitlewidget.h \
    people.h \
    group.h \
    groupbase.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
