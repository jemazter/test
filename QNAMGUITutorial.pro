#-------------------------------------------------
#
# Project created by QtCreator 2017-01-04T11:05:04
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QNAMGUITutorial
TEMPLATE = app

OPENSSL_LIBS='-L/opt/ssl/lib -lssl -lcrypto' ./configure -openssl-linked

SOURCES += main.cpp\
        mainwindow.cpp \
    mynetworkclass.cpp

HEADERS  += mainwindow.h \
    mynetworkclass.h

FORMS    += mainwindow.ui
