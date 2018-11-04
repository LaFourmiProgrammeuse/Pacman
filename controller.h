#pragma once

#include "interface.h"
#include "game.h"
#include "menu.h"
#include "level.h"
#include "level_editor.h"
#include "select_level_editor.h"

#include <QDebug>
#include <QThread>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Interface;
class Menu;
class Game;
class Level;
class Level_Editor;
class Select_Level_Editor;

enum State{In_Menu, In_Game, In_Editor, In_Tuto, In_Select_Level};

class Controller : public QThread
{
public:
    Controller();
    ~Controller();

    void run();

    //getters
    State getState();
    Game *getGame();
    Menu *getMenu();
    Interface *getInterface();
    Level_Editor *getLevelEditor();

    //setters
    void setState(State state);


    void CreateGame(Level *level);
    void CreateLevelEditor(Level *level);
    void CreateSelectLevelEditor();

private:
    Interface *interface;
    Level_Editor *level_editor;
    Select_Level_Editor *select_level_editor;
    Game *game;
    Menu *menu;

    State state;

    const float framerate = 10;

};


