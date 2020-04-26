QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_iotest.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SigIO/release/ -lSigIO
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SigIO/debug/ -lSigIO

INCLUDEPATH += $$PWD/../SigIO
DEPENDPATH += $$PWD/../SigIO

HEADERS += \
    tst_iotest.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SigIO/release/ -lSigIO
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SigIO/debug/ -lSigIO
else:unix: LIBS += -L$$OUT_PWD/../SigIO/ -lSigIO

INCLUDEPATH += $$PWD/../SigIO
DEPENDPATH += $$PWD/../SigIO
