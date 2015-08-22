#-------------------------------------------------
#
# Project created by QtCreator 2015-08-21T23:26:22
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = stress
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    requestthread.cpp \
    client.cpp \
    payload.cpp

HEADERS += \
    requestthread.h \
    client.h \
    payload.h
