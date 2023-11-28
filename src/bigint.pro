QT += core
QT -= gui

CONFIG += c++11

TARGET = bigint
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    bigint.cpp\
    main.cpp

HEADERS += \
    bigint.hpp
