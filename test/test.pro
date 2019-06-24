QT          += core \
               testlib
QT          -= gui
CONFIG      += console

TARGET       = test
TEMPLATE     = app

SOURCES     += main.cpp \
               testqxbee.cpp \
               ../library/src/qxbee.cpp

HEADERS     += testqxbee.h \
               ../library/include/qxbee.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../library/release/ -lqxbee
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../library/debug/ -lqxbee
else:unix:!macx: LIBS += -L$$OUT_PWD/../library/ -lqxbee

INCLUDEPATH += $$PWD/../library
DEPENDPATH += $$PWD/../library

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../library/release/libqxbee.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../library/debug/libqxbee.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../library/release/qxbee.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../library/debug/qxbee.lib
else:unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../library/libqxbee.a
