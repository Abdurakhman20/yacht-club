TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
        mainFileEdit.c \
        projectMenu.c \
        readAndWrite.c

HEADERS += \
    fileStructs.h \
    mainFileEdit.h \
    projectMenu.h \
    readAndWrite.h
