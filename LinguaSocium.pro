#-------------------------------------------------
#
# Project created by QtCreator 2016-02-15T19:24:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LinguaSocium
TEMPLATE = app
DESTDIR = ./bin
OBJECTS_DIR = ./obj
MOC_DIR = ./moc
RCC_DIR = ./rcc
UI_DIR = ./ui


SOURCES += main.cpp \
    mainwindow.cpp \
    loginform.cpp \
    logindialog.cpp \
    registrationdialog.cpp \
    registrationform.cpp \
    warningdialog.cpp

HEADERS  += \
    mainwindow.h \
    loginform.h \
    logindialog.h \
    registrationdialog.h \
    registrationform.h \
    warningdialog.h

FORMS    += \
    mainwindow.ui \
    loginform.ui \
    logindialog.ui \
    registrationdialog.ui \
    registrationform.ui \
    warningdialog.ui

CONFIG += mobility
MOBILITY = 

