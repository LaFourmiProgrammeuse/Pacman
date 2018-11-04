QT += widgets
QT += network

win32: LIBS += -L$$PWD/../../Librairie/Sfml/Compiler/ -lsfml-main

INCLUDEPATH += $$PWD/../../Librairie/Sfml/Compiler/include
DEPENDPATH += $$PWD/../../Librairie/Sfml/Compiler/include

win32: LIBS += -L$$PWD/../../Librairie/Sfml/Compiler/ -lsfml-window

INCLUDEPATH += $$PWD/../../Librairie/Sfml/Compiler/include
DEPENDPATH += $$PWD/../../Librairie/Sfml/Compiler/include

win32: LIBS += -L$$PWD/../../Librairie/Sfml/Compiler/ -lsfml-graphics

INCLUDEPATH += $$PWD/../../Librairie/Sfml/Compiler/include
DEPENDPATH += $$PWD/../../Librairie/Sfml/Compiler/include

win32: LIBS += -L$$PWD/../../Librairie/Sfml/Compiler/ -lsfml-system

INCLUDEPATH += $$PWD/../../Librairie/Sfml/Compiler/include
DEPENDPATH += $$PWD/../../Librairie/Sfml/Compiler/include

win32: LIBS += -L$$PWD/../build-Lib_GameDev-Desktop_Qt_5_10_0_MinGW_32bit-Release/release/ -lLib_GameDev

INCLUDEPATH += $$PWD/../Lib_GameDev
DEPENDPATH += $$PWD/../Lib_GameDev

SOURCES += \
    main.cpp \
    controller.cpp \
    interface.cpp \
    game.cpp \
    menu.cpp \
    level.cpp \
    pacman.cpp \
    ghost.cpp \
    level_editor.cpp \
    dialog_sauv_level.cpp \
    select_level_editor.cpp \
    game_loading.cpp

HEADERS += \
    controller.h \
    game.h \
    menu.h \
    level.h \
    pacman.h \
    ghost.h \
    level_editor.h \
    interface.h \
    dialog_sauv_level.h \
    select_level_editor.h \
    game_loading.h

FORMS += \
    dialog_sauv_level.ui
