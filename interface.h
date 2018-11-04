#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <QDebug>

#include "controller.h"

class Controller;

class Interface
{
public:
    Interface(Controller *controller);
    ~Interface();

    void Draw();

    //getters
    sf::Vector2i getMousePosition();
    sf::Vector2f getWindowSize();

    void startTreatEvent();

    //setters
    void setActive(bool active);
    void setWindowSize(sf::Vector2u size);
    void setGameWindowSize();
    void setEditorWindowSize();
    void setVisibleMainWindow(bool visible);
    void setMenuWindowSize();

    const unsigned int WINDOW_WIDTH_MENU = 450;
    const unsigned int WINDOW_HEIGHT_MENU = 500;

    const unsigned int WINDOW_WIDTH_GAME = 864;
    const unsigned int WINDOW_HEIGHT_GAME = 552;

    const unsigned int WINDOW_WIDTH_EDITOR = 1314;
    const unsigned int WINDOW_HEIGHT_EDITOR = 512;

private:
    Controller *controller;

    sf::RenderWindow *window;

    sf::Context context;
};

