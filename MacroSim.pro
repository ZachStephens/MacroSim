TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wshadow -std=c++11 -lboost_system


SOURCES += main.cpp \
    nationstate.cpp \
    population.cpp \
    rawmaterial.cpp \
    simstate.cpp \
    individual.cpp

HEADERS += \
    nationstate.h \
    population.h \
    rawmaterial.h \
    simstate.h \
    individual.h

INCLUDEPATH += /usr/include/boost

LIBS += -L/usr/include/boost -lboost_system
LIBS += -L/usr/include/boost  -lboost_chrono
LIBS += -L/usr/include/boost  -lboost_thread
