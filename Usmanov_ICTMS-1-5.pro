TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
        projectMenu.c \
        readAndWrite.c

HEADERS += \
    fileStructs.h \
    projectMenu.h \
    readAndWrite.h
