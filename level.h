#pragma once

#include <QFile>
#include <QDebug>
#include <QVector>

#include "file_tools.h"
#include "matrix.h"

#include <SFML/Graphics.hpp>

#include "game.h"

class Game;

struct Case{
    bool solid = false;
    sf::Sprite case_sprite;
};

class Level
{
public:
    Level(QString path);
    ~Level();

    //getters
    Matrix<Case *> *getTileMap();
    QVector<sf::Texture *> *getListTexture();
    QVector<int> *getListSolidTexture();
    QString getLevelPath();
    sf::Texture *getDefaultTexture();

    QList<int> *getTimeScatterMode();
    QList<int> *getTimeChaseMode();
    QList<int> *getTimeFrightened();

    sf::Vector2i *getPacmanPosition();
    sf::Vector2i *getBlueGhostPosition();
    sf::Vector2i *getRedGhostPosition();
    sf::Vector2i *getOrangeGhostPosition();
    sf::Vector2i *getPinkGhostPosition();

private:

    const int default_tile = 22;

    bool finished;
    bool locked;

    Matrix<Case *> *tile_map;

    QVector<sf::Texture *> list_texture;
    QVector<int> list_solid_texture;

    QString path_file;

    QList<int> *time_scatter_mode;
    QList<int> *time_chase_mode;
    QList<int> *time_frightened_mode;

    sf::Vector2i pacman_pos;
    sf::Vector2i blue_ghost_pos;
    sf::Vector2i red_ghost_pos;
    sf::Vector2i orange_ghost_pos;
    sf::Vector2i pink_ghost_pos;


};


