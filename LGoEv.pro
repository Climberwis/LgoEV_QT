#-------------------------------------------------
#
# Project created by QtCreator 2016-01-20T18:28:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LGoEv
TEMPLATE = app

CONFIG += c++14

SOURCES += main.cpp\
        mainwindow.cpp \
    mapfield.cpp \
    maplife.cpp \
    functions.cpp

HEADERS  += mainwindow.h \
    mapfield.h \
    maplife.h \
    header.h

FORMS    += mainwindow.ui
