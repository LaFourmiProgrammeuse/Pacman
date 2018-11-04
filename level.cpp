#include "level.h"

Level::Level(QString path)
{
    qDebug() << "Constructeur Level";

    path_file = path;

    tile_map = new Matrix<Case *>(NUMBER_CASE_X, NUMBER_CASE_Y, new Case);

    File_Tools ft(path);

        /* LIST SOLID TEXTURE INIT */

    QStringList solid_texture_data = ft.getValueFromAttribute("Solid_Tile").split(",");
    for(int i = 0; i < solid_texture_data.size(); i++){

        list_solid_texture.append(solid_texture_data[i].toInt());
    }

        /* TEXTURE LOAD */

    for(int r = 0; r < 10; r++){

        for(int c = 0; c < 10; c++){

            sf::Texture *texture = new sf::Texture;
            texture->loadFromFile("D:/Programmation/Fichier ressource(image,ect)/Tile_Set/Tile_set_pacman.png", sf::IntRect(c*TILE_SIZE_WIDTH, r*TILE_SIZE_HEIGHT, TILE_SIZE_WIDTH, TILE_SIZE_WIDTH));
            list_texture.append(texture);
        }
    }

        /* INIT CASE */

    QStringList tile_map_data = ft.getValueFromAttribute("Tile_Map").split(",");
    qDebug() << tile_map_data;
    int tile_map_data_pos = 0;

    for(unsigned int r = 0; r < NUMBER_CASE_Y; r++){

        for(unsigned int c = 0; c < NUMBER_CASE_X; c++){

            sf::Sprite sprite;

            if(tile_map_data_pos >= tile_map_data.size()){

                //On met une case grise si pas de case de definis dans la tilemap
                sprite.setTexture(*list_texture[default_tile]);

            }else{

                sprite.setTexture(*list_texture[tile_map_data[tile_map_data_pos].toInt()]);
            }

            Case *_case = new Case;
            _case->case_sprite = sprite;

            _case->solid = false;

            (*tile_map)(c, r) = _case;

            tile_map_data_pos++;

        }
    }

    /* TIME PHASE LOAD */

    time_chase_mode = new QList<int>;
    time_frightened_mode = new QList<int>;
    time_scatter_mode = new QList<int>;

    QStringList list_chunk_time_mode = ft.getValueFromAttribute("Time_Phase").split(",");
    for(int i = 0; i < list_chunk_time_mode.length(); i++){

        QStringList list_time_mode = list_chunk_time_mode.at(i).split("-");

        qDebug() << list_time_mode;

        time_chase_mode->append(list_time_mode.at(0).toInt());
        time_frightened_mode->append(list_time_mode.at(1).toInt());
        time_scatter_mode->append(list_time_mode.at(2).toInt());
    }

    /* ENTITY POSITION LOAD */

    QString pacman_x_string, pacman_y_string;
    QString blue_ghost_x_string, blue_ghost_y_string;
    QString red_ghost_x_string, red_ghost_y_string;
    QString orange_ghost_x_string, orange_ghost_y_string;
    QString pink_ghost_x_string, pink_ghost_y_string;

    pacman_x_string = ft.getValueFromAttribute("Pacman_X");
    pacman_y_string = ft.getValueFromAttribute("Pacman_Y");
    blue_ghost_x_string = ft.getValueFromAttribute("Blue_Ghost_X");
    blue_ghost_y_string = ft.getValueFromAttribute("Blue_Ghost_Y");
    red_ghost_x_string = ft.getValueFromAttribute("Red_Ghost_X");
    red_ghost_y_string = ft.getValueFromAttribute("Red_Ghost_Y");
    orange_ghost_x_string = ft.getValueFromAttribute("Orange_Ghost_X");
    orange_ghost_y_string = ft.getValueFromAttribute("Orange_Ghost_Y");
    pink_ghost_x_string = ft.getValueFromAttribute("Pink_Ghost_X");
    pink_ghost_y_string = ft.getValueFromAttribute("Pink_Ghost_Y");

    pacman_pos.x = pacman_x_string.toInt();
    pacman_pos.y = pacman_y_string.toInt();
    blue_ghost_pos.x = blue_ghost_x_string.toInt();
    blue_ghost_pos.y = blue_ghost_y_string.toInt();
    red_ghost_pos.x = red_ghost_x_string.toInt();
    red_ghost_pos.y = red_ghost_y_string.toInt();
    orange_ghost_pos.x = orange_ghost_x_string.toInt();
    orange_ghost_pos.y = orange_ghost_y_string.toInt();
    pink_ghost_pos.x = pink_ghost_x_string.toInt();
    pink_ghost_pos.y = pink_ghost_y_string.toInt();

}

Level::~Level(){
    qDebug() << "Destructeur Level";
    delete tile_map;
}

Matrix<Case *> *Level::getTileMap(){
    return tile_map;
}

QVector<sf::Texture *> *Level::getListTexture(){
    return &list_texture;
}

QVector<int> *Level::getListSolidTexture(){
    return &list_solid_texture;
}

QString Level::getLevelPath(){
    return path_file;
}

sf::Texture *Level::getDefaultTexture(){
    return list_texture.at(default_tile);
}

QList<int> *Level::getTimeFrightened(){
    return time_frightened_mode;
}

QList<int> *Level::getTimeChaseMode(){
    return time_chase_mode;
}

QList<int> *Level::getTimeScatterMode(){
    return time_scatter_mode;
}


sf::Vector2i *Level::getPacmanPosition(){
    return &pacman_pos;
}

sf::Vector2i *Level::getBlueGhostPosition(){
    return &blue_ghost_pos;
}

sf::Vector2i *Level::getRedGhostPosition(){
    return &red_ghost_pos;
}

sf::Vector2i *Level::getOrangeGhostPosition(){
    return &orange_ghost_pos;
}

sf::Vector2i *Level::getPinkGhostPosition(){
    return &pink_ghost_pos;
}

