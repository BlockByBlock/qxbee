QT       -= gui widget
QT       += core

TARGET = qxbee
TEMPLATE = lib
unix:CONFIG += static
win32:CONFIG += static

SOURCES += \
        src/qxbee.cpp \
        src/xbeeGenericPacket.cpp \
        src/xbeeReceivePacket.cpp \
        src/xbeeTransmitPacket.cpp

HEADERS += \
        include/qxbee.h \
        include/qxbee_global.h \
        include/xbeeTransmitPacket.h \
        include/xbeeGenericPacket.h \
        include/xbeeReceivePacket.h

#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}
