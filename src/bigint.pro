QT += core
QT += gui widgets

CONFIG += c++11

TARGET = bigint
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    ../../lect4/hellowidget.cpp \
    ../../lect4/recordsfacade.cpp \
    bigint.cpp\
    form.cpp \
    main.cpp \
    mycode.cpp

HEADERS += \
    ../../lect4/hellowidget.h \
    ../../lect4/recordsfacade.h \
    bigint.hpp \
    form.h \
    mycode.h

FORMS += \
    form.ui
