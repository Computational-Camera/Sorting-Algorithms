QT       += core
QT       -= gui

QT_CONFIG -= no-pkg-config
CONFIG += link_pkgconfig

TARGET   = sort
TEMPLATE = app

CONFIG   += console
CONFIG   += optimize_full
CONFIG   -= app_bundle

TEMPLATE = app
#HEADERS    =    ./src/*.h
SOURCES		=    ./src/*.cpp

QMAKE_CXXFLAGS += -O3 -march=native -std=c++11 -m64 -pipe -ffast-math -Waggressive-loop-optimizations -Wall -fpermissive

OBJECTS_DIR = ./obj
DESTDIR     = ./bin

