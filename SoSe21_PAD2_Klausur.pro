TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        city.cpp \
        citywithinfo.cpp \
        main.cpp

HEADERS += \
    CityGraph.h \
    city.h \
    citywithinfo.h
