#pragma once

#include <SFML/Graphics.hpp>

#include <QDebug>

#include "controller.h"

class Select_Level_Editor
{
public:
    Select_Level_Editor(Controller *controller);

    void Event(sf::Event event);
    void Draw(sf::RenderWindow *window);

private:
    Controller *controller;

    QVector<Button_Widget> list_recent_file;

    Button_Widget bw_back;
    Button_Widget bw_create_level;


};

