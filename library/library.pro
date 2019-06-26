QT       -= gui widget
QT       += core

TARGET = qxbee
TEMPLATE = lib
unix:CONFIG += static
win32:CONFIG += static

SOURCES += \
    src/QXbee.cpp \
    src/FrameHandler.cpp \
    src/FrameBuffer.cpp \
    src/QXbeeFrame.cpp \
    src/QXbeeFrameData.cpp

HEADERS += \
    include/FrameHandler.h \
    include/FrameBuffer.h \
    include/QXbee.h \
    include/QXbee_global.h \
    include/QXbeeFrame.h \
    include/QXbeeFrameData.h

#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}
