TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    getvalues.cpp \
    encounter.cpp \
    battle.cpp \
    ai.cpp

HEADERS += \
    getvalues.h \
    encounter.h \
    battle.h \
    ai.h
