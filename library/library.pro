QT       -= gui widget
QT       += core

TARGET = qxbee
TEMPLATE = lib
unix:CONFIG += static
win32:CONFIG += static

SOURCES += \
    src/QXbee.cpp \
    src/QXbeePrivate.cpp \
    src/Frame.cpp

SOURCES += \
    src/Frames/TransmitFrame.cpp \
    src/Frames/ReceiveFrame.cpp \
    src/Frames/UnidentifiedFrame.cpp

HEADERS += \
    include/QXbee.h \
    include/QXbee_global.h \
    include/QXbeePrivate.h \
    include/Frame.h \
    include/FrameData.h

HEADERS += \
    include/Frames/TransmitFrame.h \
    include/Frames/ReceiveFrame.h \
    include/Frames/UnidentifiedFrame.h

#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}
