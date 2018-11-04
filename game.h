#pragma once

#include <QDebug>

#include <SFML/Graphics.hpp>

#include "controller.h"
#include "level.h"

#include "matrix.h"
#include "button_widget.h"

class Controller;
class Level;

struct Case;

const static unsigned int CASE_WIDTH = 32;
const static unsigned int CASE_HEIGHT = 32;

const static unsigned int NUMBER_CASE_X = 27;
const static unsigned int NUMBER_CASE_Y = 16;

const static unsigned int TILE_SIZE_WIDTH = 32;
const static unsigned int TILE_SIZE_HEIGHT = 32;

enum Game_State{Wait_Start, Running , Paused, Finished};
enum Ghost_State{Scatter_Mode, Chase_Mode, Frightened_Mode};

class Game
{
public:
    Game(Level *level, Controller *controller);
    ~Game();

    void Event(sf::Event event);
    void Draw(sf::RenderWindow *window);

    //getters
    Game_State getGameState();

    //setters

private:
    Controller *controller;
    Level *level;

    Game_State game_state;
    Ghost_State ghost_state;

    Matrix<Case *> *tile_map;
    QVector<sf::Texture *> *list_texture;
    QVector<int> *list_solid_texture;

    Button_Widget bw_score;
    sf::Text bw_score_value;

    Button_Widget bw_best_score;
    sf::Text bw_best_score_value;

    Button_Widget bw_life;
    sf::Text bw_life_value;

    QList<sf::RectangleShape> list_shape;

    sf::Font *font_bebas;

};

