QT          += core
QT          += console
QT          -= gui

TARGET       = test
TEMPLATE     = app

SOURCES     += main.cpp \
               testqxbee.cpp

HEADERS     += testqxbee.h

LIBS        += -lqxbeed

