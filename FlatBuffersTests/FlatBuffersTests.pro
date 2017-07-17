TEMPLATE = app
CONFIG += console c++1z
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "gtest/src"
INCLUDEPATH += "/gtest/include/gtest/"
INCLUDEPATH += "../../"

SOURCES += main.cpp \
    ../cserialization.cpp

HEADERS += \
    ../cserialization.h \
    ../schema_generated.h
