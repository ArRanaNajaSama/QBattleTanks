QT -= gui
QT += widgets

CONFIG += c++11

TARGET = QBattleCity
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Game.cpp \
    $$PWD/Tanks/*.cpp \
    $$PWD/Field/*.cpp \

HEADERS += \
    Game.h \
    $$PWD/Tanks/*.h \
    $$PWD/Field/*.h \
