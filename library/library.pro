QT       -= gui widget
QT       += core

TARGET = qxbee
TEMPLATE = lib
unix:CONFIG += static
win32:CONFIG += static

SOURCES += \
    src/QXbee.cpp \
    src/ReceiveFrame.cpp \
    src/TransmitFrame.cpp \
    src/FrameHandler.cpp \
    src/QXbeeFrame.cpp

HEADERS += \
    include/FrameHandler.h \
    include/QXbee.h \
    include/ReceiveFrame.h \
    include/QXbee_global.h \
    include/TransmitFrame.h \
    include/QXbeeFrame.h

#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}
