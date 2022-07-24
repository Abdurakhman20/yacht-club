TEMPLATE = app
CONFIG += console c99
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        aboutTheDeveloper.c \
        main.c \
        mainFileEdit.c \
        projectMenu.c \
        readAndWrite.c \
        spravFunctions.c

HEADERS += \
    aboutTheDeveloper.h \
    fileStructs.h \
    mainFileEdit.h \
    projectMenu.h \
    readAndWrite.h \
    spravFunctions.h
