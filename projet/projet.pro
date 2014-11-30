#-------------------------------------------------
#
# Project created by QtCreator 2014-11-30T11:42:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projet
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    personnage.cpp \
    heros.cpp \
    ennemi.cpp \
    majordhomme.cpp \
    terrain.cpp \
    objet.cpp \
    decor.cpp \
    echelle.cpp \
    armoire.cpp

HEADERS  += mainwindow.h \
    personnage.h \
    heros.h \
    ennemi.h \
    majordhomme.h \
    terrain.h \
    objet.h \
    decor.h \
    echelle.h \
    armoire.h

FORMS    += mainwindow.ui
