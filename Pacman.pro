QT += widgets
#QT += network

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
    interface.h \
    game.h \
    menu.h \
    level.h \
    pacman.h \
    ghost.h \
    level_editor.h \
    dialog_sauv_level.h \
    select_level_editor.h \
    game_loading.h

FORMS += \
    dialog_sauv_level.ui


#LIB SFML
INCLUDEPATH += $$_PRO_FILE_PWD_/SFML-2.5.1/include
DEPENDPATH += $$_PRO_FILE_PWD_/SFML-2.5.1/include

unix: LIBS += -L$$_PRO_FILE_PWD_/SFML-2.5.1/linux/lib -lsfml-window
else:win32: LIBS += -L$$_PRO_FILE_PWD_/SFML-2.5.1/window/lib -lsfml-window

unix: LIBS += -L$$_PRO_FILE_PWD_/SFML-2.5.1/linux/lib -lsfml-graphics
else:win32: LIBS += -L$$_PRO_FILE_PWD_/SFML-2.5.1/window/lib -lsfml-graphics

unix: LIBS += -L$$_PRO_FILE_PWD_/SFML-2.5.1/linux/lib -lsfml-network
else:win32: LIBS += -L$$_PRO_FILE_PWD_/SFML-2.5.1/window/lib -lsfml-network

unix: LIBS += -L$$_PRO_FILE_PWD_/SFML-2.5.1/linux/lib -lsfml-system
else:win32: LIBS += -L$$_PRO_FILE_PWD_/SFML-2.5.1/window/lib -lsfml-system

unix: LIBS += -L$$_PRO_FILE_PWD_/SFML-2.5.1/linux/lib -lsfml-audio
else:win32: LIBS += -L$$_PRO_FILE_PWD_/SFML-2.5.1/window/lib -lsfml-audio

#LIB GAMEDEV
INCLUDEPATH += $$_PRO_FILE_PWD_/Lib_GameDev/include
DEPENDPATH += $$_PRO_FILE_PWD_/Lib_GameDev/include

win32: LIBS += -L$$_PRO_FILE_PWD_/Lib_GameDev/window/lib/ -lLib_GameDev
else:unix: LIBS += -L$$_PRO_FILE_PWD_/Lib_GameDev/linux/lib/ -lLib_GameDev
