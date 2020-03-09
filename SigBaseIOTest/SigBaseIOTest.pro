QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_baseiotest.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SigBaseIO/release/ -lSigBaseIO
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SigBaseIO/debug/ -lSigBaseIO

INCLUDEPATH += $$PWD/../SigBaseIO
DEPENDPATH += $$PWD/../SigBaseIO
