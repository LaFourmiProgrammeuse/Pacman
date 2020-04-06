#pragma once

#include <QDebug>
#include <QDir>
#include <QFileDialog>

#include <GameDev/button_widget.h>
#include "GameDev/text_switch_widget.h"
#include "GameDev/file_tools.h"
#include "GameDev/event_handler.h"

#include "controller.h"
#include "interface.h"
#include "level.h"

#include <SFML/Graphics.hpp>

class Controller;
class Interface;

struct Level_Description{
    Button_Widget *button_level;
    bool locked;
    bool finished;
    QString level_path;
};

class Menu
{
public:
    Menu(Controller *controller);

    void Event(sf::Event event);
    void Draw(sf::RenderWindow *window);

    void setPage(int page);

private:
    QList<QList<Button_Widget *>> list_page_button_widget;
    QList<QList<Text_Switch_Widget *>> list_page_txt_switch_widget;

    QList<QList<sf::RectangleShape>> list_page_rectangle_shape;
    QList<QList<sf::Text *>> list_page_text;

    QList<Level_Description> list_level_official;

    int page;
    int page_level_official;

    Controller *controller;
    Interface *interface;

    sf::Font *font_dimis;
    sf::Font *font_bebas;

    Event_Handler<Menu> *eh;

    sf::Texture texture_pacman_title;
    sf::Sprite sprite_pacman_title;

    sf::Texture texture_background_1;
    sf::Sprite sprite_background_1;

    void Test();


};

