#pragma once

#include <QDebug>
#include <QVector3D>

#include "level.h"
#include "game.h"
#include "controller.h"
#include "dialog_sauv_level.h"

#include "GameDev/text_switch_widget.h"
#include "GameDev/button_widget.h"
#include "GameDev/file_tools.h"

#include "SFML/Graphics.hpp"

class Level;
struct Case;
class Dialog_Sauv_Level;

class Level_Editor
{
public:
    Level_Editor(Level *level, Controller *controller);

    void DrawMainWindow(sf::RenderWindow *window);
    void DrawTextureWindow(sf::RenderWindow *window);

    void EventMainWindow(sf::Event event);

    void SaveLevel();

    void ResetTileMap();

    //getters


    //setters


private:
    //Instance classe
    Level *level;
    Controller *controller;
    Dialog_Sauv_Level *dialog_sauv_level;

    //Texture used : page 0
    sf::Sprite sprite_to_set;
    sf::RectangleShape frame_sprite_to_set;
    Button_Widget bw_label_texture_used;
    bool sprite_set;

    //System page texture : page 0
    Text_Switch_Widget *tsw_page_texture;
    sf::RectangleShape *border_page_texture;
    QList<sf::RectangleShape *> list_border_texture_sprite;
    QList<sf::Sprite *> list_texture_sprite;
    int page_texture;
    QList<Button_Widget *> list_number_label_texture;
    Button_Widget bw_clear_tile;
    sf::RectangleShape border_right_grid;
    const int DEFAULT_TEXTURE = 39;

    //Page place entity : page 1
    QList<sf::RectangleShape> list_menu_frame_entity;
    QList<sf::RectangleShape> list_menu_frame_object;
    QList<sf::Texture *> list_texture_entity;
    QList<sf::Texture *> list_texture_object;

    QList<sf::Sprite> list_sprite_entity_to_place;
    QList<sf::Sprite> list_sprite_object_to_place;
    QList<sf::Sprite> list_sprite_entity_placed;
    QList<sf::Sprite> list_sprite_object_placed;
    QList<sf::Sprite> list_sprite_entity_mouse_icone;
    QList<sf::Sprite> list_sprite_object_mouse_icone;


    Button_Widget label_entity_to_place;
    Button_Widget label_fruit_to_place;
    Button_Widget label_coin_to_place;

    int entity_who_is_placing = 0;
    bool is_entity_placing = false;

    //Page phase : page 3
    Text_Switch_Widget tsw_phase_level;
    Text_Switch_Widget tsw_time_scatter_mode;
    Text_Switch_Widget tsw_time_chase_mode;
    Text_Switch_Widget tsw_time_frightened_mode;

    Button_Widget label_phase_level;
    Button_Widget label_time_scatter_mode;
    Button_Widget label_time_chase_mode;
    Button_Widget label_time_frightened_mode;

    QList<int> *time_scatter_mode;
    QList<int> *time_chase_mode;
    QList<int> *time_frightened_mode;

    const int max_level = 30;

    Button_Widget bw_clear_time_mode;


    //Menu Editor
    QList<Button_Widget *> list_bw_menu_editor;
    Button_Widget *bw_back;
    sf::Sprite right_arrow_sprite_menu;
    int page_menu;

    //Tile_map et list solid texture
    Matrix<Case *> *tile_map_to_set;
    QVector<int> *list_solid_texture;

    //Texture et Font
    sf::Font font_jai;
    sf::Font font_dimis;

    sf::Texture right_arrow_texture;

};


