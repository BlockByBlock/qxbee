QT       -= gui widget
QT       += core

TARGET = qxbee
TEMPLATE = lib
unix:CONFIG += static
win32:CONFIG += static

SOURCES += \
    src/QXbee.cpp
#    src/Frame.cpp

#SOURCES += \
#    src/Frames/TransmitFrame.cpp \
#    src/Frames/ReceiveFrame.cpp

HEADERS += \
    include/QXbee.h \
    include/QXbee_global.h \
    include/QXbeePrivate.h
#    include/Frame.h

#HEADERS += \
#    include/Frames/TransmitFrame.h \
#    include/Frames/ReceiveFrame.h

#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}
