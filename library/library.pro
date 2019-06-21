QT       -= gui widget
QT       += core

TARGET = qxbee
TEMPLATE = lib
unix:CONFIG += static
win32:CONFIG += static

SOURCES += \
        src/qxbee.cpp \
        src/xbeegenericpacket.cpp

HEADERS += \
        include/qxbee.h \
        include/qxbee_global.h \
        include/xbeegenericpacket.h

#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}
