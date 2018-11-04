#include "level_editor.h"

Level_Editor::Level_Editor(Level *level, Controller *controller)
{
    qDebug() << "Constructeur Level_Editor";

    this->level = level;
    this->controller = controller;

    dialog_sauv_level = new Dialog_Sauv_Level(nullptr, this, controller);

    list_solid_texture = level->getListSolidTexture();
    tile_map_to_set = level->getTileMap();
    sprite_set = false;

    page_texture = 0;
    page_menu = 0;

    if(right_arrow_texture.loadFromFile("D:/Programmation/Fichier ressource(image,ect)/Icone/Fleche droite.png")){
        qDebug() << "Texture right arrow chargée avec succes !";
    }
    else{
        qDebug() << "Erreur lors du chargement de la texture right arrow";
    }

    right_arrow_sprite_menu.setTexture(right_arrow_texture);
    right_arrow_sprite_menu.setScale(1.5, 1.5);

    tsw_page_texture.LoadFont("D:/Programmation/Fichier ressource(image,ect)/Police/JAi_____.ttf");
    tsw_page_texture.setCharacterSize(22);

    /* FONT */

    if(!font_jai.loadFromFile("D:/Programmation/Fichier ressource(image,ect)/Police/JAi_____.ttf")){
        qDebug() << "Erreur lors du chargement d'une font";
    }

    if(!font_dimis.loadFromFile("D:/Programmation/Fichier ressource(image,ect)/Police/Dimis___.ttf")){
        qDebug() << "Erreur lors du chargement d'une font";
    }



    /* PAGE PLACE ENTITY INIT */

    sf::RectangleShape frame_pacman_entity;
    frame_pacman_entity.setSize(sf::Vector2f(64, 64));
    frame_pacman_entity.setPosition(1182, 42);
    frame_pacman_entity.setFillColor(sf::Color::Transparent);
    frame_pacman_entity.setOutlineColor(sf::Color::White);
    frame_pacman_entity.setOutlineThickness(1);

    list_menu_frame_entity.append(frame_pacman_entity);

    sf::RectangleShape frame_pink_ghost_entity;
    frame_pink_ghost_entity.setSize(sf::Vector2f(64, 64));
    frame_pink_ghost_entity.setPosition(1229, 122);
    frame_pink_ghost_entity.setFillColor(sf::Color::Transparent);
    frame_pink_ghost_entity.setOutlineColor(sf::Color::White);
    frame_pink_ghost_entity.setOutlineThickness(1);

    list_menu_frame_entity.append(frame_pink_ghost_entity);

    sf::RectangleShape frame_red_ghost_entity;
    frame_red_ghost_entity.setSize(sf::Vector2f(64, 64));
    frame_red_ghost_entity.setPosition(1135, 122);
    frame_red_ghost_entity.setFillColor(sf::Color::Transparent);
    frame_red_ghost_entity.setOutlineColor(sf::Color::White);
    frame_red_ghost_entity.setOutlineThickness(1);

    list_menu_frame_entity.append(frame_red_ghost_entity);

    sf::RectangleShape frame_orange_ghost_entity;
    frame_orange_ghost_entity.setSize(sf::Vector2f(64, 64));
    frame_orange_ghost_entity.setPosition(1229, 202);
    frame_orange_ghost_entity.setFillColor(sf::Color::Transparent);
    frame_orange_ghost_entity.setOutlineColor(sf::Color::White);
    frame_orange_ghost_entity.setOutlineThickness(1);

    list_menu_frame_entity.append(frame_orange_ghost_entity);

    sf::RectangleShape frame_blue_ghost_entity;
    frame_blue_ghost_entity.setSize(sf::Vector2f(64, 64));
    frame_blue_ghost_entity.setPosition(1135, 202);
    frame_blue_ghost_entity.setFillColor(sf::Color::Transparent);
    frame_blue_ghost_entity.setOutlineColor(sf::Color::White);
    frame_blue_ghost_entity.setOutlineThickness(1);

    list_menu_frame_entity.append(frame_blue_ghost_entity);

    sf::RectangleShape frame_coin_object;
    frame_coin_object.setSize(sf::Vector2f(64, 64));
    frame_coin_object.setPosition(1229, 334);
    frame_coin_object.setFillColor(sf::Color::Transparent);
    frame_coin_object.setOutlineColor(sf::Color::White);
    frame_coin_object.setOutlineThickness(1);

    list_menu_frame_object.append(frame_coin_object);

    sf::RectangleShape frame_fruit_object;
    frame_fruit_object.setSize(sf::Vector2f(64, 64));
    frame_fruit_object.setPosition(1135, 334);
    frame_fruit_object.setFillColor(sf::Color::Transparent);
    frame_fruit_object.setOutlineColor(sf::Color::White);
    frame_fruit_object.setOutlineThickness(1);

    list_menu_frame_object.append(frame_fruit_object);


    label_entity_to_place.setString("Entites");
    label_entity_to_place.setCharacterSize(22);
    label_entity_to_place.setFont(font_jai);
    label_entity_to_place.setPosition(sf::Vector2f(1214, 23));
    label_entity_to_place.setTextColor(sf::Color::White);

    label_coin_to_place.setString("Piece");
    label_coin_to_place.setCharacterSize(22);
    label_coin_to_place.setFont(font_jai);
    label_coin_to_place.setPosition(sf::Vector2f(1261, 315));
    label_coin_to_place.setTextColor(sf::Color::White);

    label_fruit_to_place.setString("Fruit");
    label_fruit_to_place.setCharacterSize(22);
    label_fruit_to_place.setFont(font_jai);
    label_fruit_to_place.setPosition(sf::Vector2f(1167, 315));
    label_fruit_to_place.setTextColor(sf::Color::White);


    /* INIT PACMAN */

    sf::Texture *texture_pacman_entity = new sf::Texture;
    texture_pacman_entity->loadFromFile("pacman_entity.png");

    list_texture_entity.append(texture_pacman_entity);

    sf::Sprite sprite_pacman_entity_to_place;
    sprite_pacman_entity_to_place.setTexture(*texture_pacman_entity);
    sprite_pacman_entity_to_place.setPosition(sf::Vector2f(1188.4f, 48.4f));
    sprite_pacman_entity_to_place.setScale(0.8f, 0.8f);

    list_sprite_entity_to_place.append(sprite_pacman_entity_to_place);

    sf::Sprite sprite_pacman_entity_icone;
    sprite_pacman_entity_icone.setTexture(*texture_pacman_entity);
    sprite_pacman_entity_icone.setScale(0.28f, 0.28f);

    list_sprite_entity_mouse_icone.append(sprite_pacman_entity_icone);

    sf::Sprite sprite_pacman_entity_placed;
    sprite_pacman_entity_placed.setTexture(*texture_pacman_entity);
    sprite_pacman_entity_placed.setScale(0.5f, 0.5f);

    sf::Vector2i *pacman_pos = level->getPacmanPosition();
    sprite_pacman_entity_placed.setPosition(250+pacman_pos->x*CASE_WIDTH, pacman_pos->y*CASE_HEIGHT);

    list_sprite_entity_placed.append(sprite_pacman_entity_placed);


    /* INIT BLUE GHOST */

    sf::Texture *texture_blue_ghost_entity = new sf::Texture;
    texture_blue_ghost_entity->loadFromFile("blue_ghost_entity.png");

    list_texture_entity.append(texture_blue_ghost_entity);

    sf::Sprite sprite_blue_ghost_entity_to_place;
    sprite_blue_ghost_entity_to_place.setTexture(*texture_blue_ghost_entity);
    sprite_blue_ghost_entity_to_place.setPosition(sf::Vector2f(1141.4f, 208.4f));
    sprite_blue_ghost_entity_to_place.setScale(0.8f, 0.8f);

    list_sprite_entity_to_place.append(sprite_blue_ghost_entity_to_place);

    sf::Sprite sprite_blue_ghost_entity_mouse_icone;
    sprite_blue_ghost_entity_mouse_icone.setTexture(*texture_blue_ghost_entity);
    sprite_blue_ghost_entity_mouse_icone.setScale(0.28f, 0.28f);

    list_sprite_entity_mouse_icone.append(sprite_blue_ghost_entity_mouse_icone);

    sf::Sprite sprite_blue_ghost_entity_placed;
    sprite_blue_ghost_entity_placed.setTexture(*texture_blue_ghost_entity);
    sprite_blue_ghost_entity_placed.setScale(0.5f, 0.5f);

    sf::Vector2i *blue_ghost_pos = level->getBlueGhostPosition();
    sprite_blue_ghost_entity_placed.setPosition(250+blue_ghost_pos->x*CASE_WIDTH, blue_ghost_pos->y*CASE_HEIGHT);

    list_sprite_entity_placed.append(sprite_blue_ghost_entity_placed);


    /* INIT RED GHOST */

    sf::Texture *texture_red_ghost_entity = new sf::Texture;
    texture_red_ghost_entity->loadFromFile("red_ghost_entity.png");

    list_texture_entity.append(texture_red_ghost_entity);

    sf::Sprite sprite_red_ghost_entity;
    sprite_red_ghost_entity.setTexture(*texture_red_ghost_entity);
    sprite_red_ghost_entity.setPosition(sf::Vector2f(1141.4f, 128.4f));
    sprite_red_ghost_entity.setScale(0.8f, 0.8f);

    list_sprite_entity_to_place.append(sprite_red_ghost_entity);

    sf::Sprite sprite_red_ghost_entity_mouse_icone;
    sprite_red_ghost_entity_mouse_icone.setTexture(*texture_red_ghost_entity);
    sprite_red_ghost_entity_mouse_icone.setScale(0.28f, 0.28f);

    list_sprite_entity_mouse_icone.append(sprite_red_ghost_entity_mouse_icone);

    sf::Sprite sprite_red_ghost_entity_placed;
    sprite_red_ghost_entity_placed.setTexture(*texture_red_ghost_entity);
    sprite_red_ghost_entity_placed.setScale(0.5f, 0.5f);

    sf::Vector2i *red_ghost_pos = level->getRedGhostPosition();
    sprite_red_ghost_entity_placed.setPosition(250+red_ghost_pos->x*CASE_WIDTH, red_ghost_pos->y*CASE_HEIGHT);

    list_sprite_entity_placed.append(sprite_red_ghost_entity_placed);


    /* INIT ORANGE GHOST */

    sf::Texture *texture_orange_ghost_entity = new sf::Texture;
    texture_orange_ghost_entity->loadFromFile("orange_ghost_entity.png");

    list_texture_entity.append(texture_orange_ghost_entity);

    sf::Sprite sprite_orange_ghost_entity;
    sprite_orange_ghost_entity.setTexture(*texture_orange_ghost_entity);
    sprite_orange_ghost_entity.setPosition(sf::Vector2f(1235.4f, 208.4f));
    sprite_orange_ghost_entity.setScale(0.8f, 0.8f);

    list_sprite_entity_to_place.append(sprite_orange_ghost_entity);

    sf::Sprite sprite_orange_ghost_entity_mouse_icone;
    sprite_orange_ghost_entity_mouse_icone.setTexture(*texture_orange_ghost_entity);
    sprite_orange_ghost_entity_mouse_icone.setScale(0.28f, 0.28f);

    list_sprite_entity_mouse_icone.append(sprite_orange_ghost_entity_mouse_icone);

    sf::Sprite sprite_orange_ghost_entity_placed;
    sprite_orange_ghost_entity_placed.setTexture(*texture_orange_ghost_entity);
    sprite_orange_ghost_entity_placed.setScale(0.5f, 0.5f);

    sf::Vector2i *orange_ghost_pos = level->getOrangeGhostPosition();
    sprite_orange_ghost_entity_placed.setPosition(250+orange_ghost_pos->x*CASE_WIDTH, orange_ghost_pos->y*CASE_HEIGHT);

    list_sprite_entity_placed.append(sprite_orange_ghost_entity_placed);


    /* INIT PINK GHOST */

    sf::Texture *texture_pink_ghost_entity = new sf::Texture;
    texture_pink_ghost_entity->loadFromFile("pink_ghost_entity.png");

    list_texture_entity.append(texture_pink_ghost_entity);

    sf::Sprite sprite_pink_ghost_entity;
    sprite_pink_ghost_entity.setTexture(*texture_pink_ghost_entity);
    sprite_pink_ghost_entity.setPosition(sf::Vector2f(1235.4f, 128.4f));
    sprite_pink_ghost_entity.setScale(0.8f, 0.8f);

    list_sprite_entity_to_place.append(sprite_pink_ghost_entity);

    sf::Sprite sprite_pink_ghost_entity_mouse_icone;
    sprite_pink_ghost_entity_mouse_icone.setTexture(*texture_pink_ghost_entity);
    sprite_pink_ghost_entity_mouse_icone.setScale(0.28f, 0.28f);

    list_sprite_entity_mouse_icone.append(sprite_pink_ghost_entity_mouse_icone);

    sf::Sprite sprite_pink_ghost_entity_placed;
    sprite_pink_ghost_entity_placed.setTexture(*texture_pink_ghost_entity);
    sprite_pink_ghost_entity_placed.setScale(0.5f, 0.5f);

    sf::Vector2i *pink_ghost_pos = level->getPinkGhostPosition();
    sprite_pink_ghost_entity_placed.setPosition(250+pink_ghost_pos->x*CASE_WIDTH, pink_ghost_pos->y*CASE_HEIGHT);

    list_sprite_entity_placed.append(sprite_pink_ghost_entity_placed);




    /* PAGE PHASE INIT */

    tsw_phase_level.LoadFont("D:/Programmation/Fichier ressource(image,ect)/Police/JAi_____.ttf");
    tsw_phase_level.setCharacterSize(22);

    /* PHASE NUMBER */

    for(int i = 1; i <= max_level; i++){

        sf::Text *label_level_number = new sf::Text;
        label_level_number->setString(sf::String((QString("Phase "+QString::number(i))).toStdString()));
        label_level_number->setFillColor(sf::Color::White);

        tsw_phase_level.AddString(label_level_number);
    }
    tsw_phase_level.setPosition(1214, 60);

    /* CHASE */

    tsw_time_chase_mode.LoadFont("D:/Programmation/Fichier ressource(image,ect)/Police/JAi_____.ttf");
    tsw_time_chase_mode.setCharacterSize(21);

    for(int i = 0; i < max_level; i++){

        sf::Text *label_chase_number_second = new sf::Text;
        label_chase_number_second->setString(sf::String((QString(QString::number(i)+" sec(s)")).toStdString()));
        label_chase_number_second->setFillColor(sf::Color::White);

        tsw_time_chase_mode.AddString(label_chase_number_second);
    }

    tsw_time_chase_mode.setPosition(1214, 150);

    /* SCATTER */

    tsw_time_scatter_mode.LoadFont("D:/Programmation/Fichier ressource(image,ect)/Police/JAi_____.ttf");
    tsw_time_scatter_mode.setCharacterSize(21);

    for(int i = 0; i < max_level; i++){

        sf::Text *label_catter_number_second = new sf::Text;
        label_catter_number_second->setString(sf::String((QString(QString::number(i)+" sec(s)")).toStdString()));
        label_catter_number_second->setFillColor(sf::Color::White);

        tsw_time_scatter_mode.AddString(label_catter_number_second);
    }

    tsw_time_scatter_mode.setPosition(1214, 220);

    /* FRIGHTENED */

    tsw_time_frightened_mode.LoadFont("D:/Programmation/Fichier ressource(image,ect)/Police/JAi_____.ttf");
    tsw_time_frightened_mode.setCharacterSize(21);

    for(int i = 0; i < max_level; i++){

        sf::Text *label_frightened_number_second = new sf::Text;
        label_frightened_number_second->setString(sf::String((QString(QString::number(i)+" sec(s)")).toStdString()));
        label_frightened_number_second->setFillColor(sf::Color::White);

        tsw_time_frightened_mode.AddString(label_frightened_number_second);
    }

    tsw_time_frightened_mode.setPosition(1214, 290);




    label_phase_level.setCharacterSize(18);
    label_phase_level.setFont(font_jai);
    label_phase_level.setString("Phase");
    label_phase_level.setFilledColor(sf::Color::White);
    label_phase_level.setPosition(sf::Vector2f(1214, 30));

    label_time_chase_mode.setCharacterSize(18);
    label_time_chase_mode.setFont(font_jai);
    label_time_chase_mode.setString("Chase mode");
    label_time_chase_mode.setFilledColor(sf::Color::White);
    label_time_chase_mode.setPosition(sf::Vector2f(1214, 120));

    label_time_scatter_mode.setCharacterSize(18);
    label_time_scatter_mode.setFont(font_jai);
    label_time_scatter_mode.setString("Scatter mode");
    label_time_scatter_mode.setFilledColor(sf::Color::White);
    label_time_scatter_mode.setPosition(sf::Vector2f(1214, 190));

    label_time_frightened_mode.setCharacterSize(18);
    label_time_frightened_mode.setFont(font_jai);
    label_time_frightened_mode.setString("Frightened mode");
    label_time_frightened_mode.setFilledColor(sf::Color::White);
    label_time_frightened_mode.setPosition(sf::Vector2f(1214, 260));


    bw_clear_time_mode.setCharacterSize(24);
    bw_clear_time_mode.setString("Reinitialiser");
    bw_clear_time_mode.setFont(font_dimis);
    bw_clear_time_mode.setTextColor(sf::Color::White);
    bw_clear_time_mode.setPosition(sf::Vector2f(1214, 478));

    time_chase_mode = level->getTimeChaseMode();
    time_frightened_mode = level->getTimeFrightened();
    time_scatter_mode = level->getTimeScatterMode();

    //On actualise la premiere page manuellement car logiquement cela ce fait lorsq'on change de page
    tsw_time_chase_mode.setPositionList(time_chase_mode->at(tsw_phase_level.getPositionList()));
    tsw_time_frightened_mode.setPositionList(time_frightened_mode->at(tsw_phase_level.getPositionList()));
    tsw_time_scatter_mode.setPositionList(time_scatter_mode->at(tsw_phase_level.getPositionList()));

    tsw_time_chase_mode.Update();
    tsw_time_frightened_mode.Update();
    tsw_time_scatter_mode.Update();



    /* ZOOM TEXTURE USED INIT */

    frame_sprite_to_set.setFillColor(sf::Color::Transparent);
    frame_sprite_to_set.setOutlineColor(sf::Color::White);
    frame_sprite_to_set.setOutlineThickness(1);
    frame_sprite_to_set.setSize(sf::Vector2f(96, 96));

    /* PAGE TEXTURE INIT */

    //Premiere page
    sf::Text *page_1 = new sf::Text;
    page_1->setFont(font_jai);
    page_1->setFillColor(sf::Color::White);
    page_1->setString("Page 1");

    tsw_page_texture.AddString(page_1);

    int x = 1;
    int y = 1;
    int page_number = 1;
    for(int i = 0; i < level->getListTexture()->size(); i++){

        sf::Sprite *sprite = new sf::Sprite;
        sprite->setTexture(*level->getListTexture()->at(i));
        sprite->setScale(1.3, 1.3);
        sprite->setPosition(1164+(x-1)*79, 185+(y-1)*50);

        list_texture_sprite.append(sprite);

        Button_Widget *label_number_texture = new Button_Widget;
        label_number_texture->setCharacterSize(18);
        label_number_texture->LoadFont("D:/Programmation/Fichier ressource(image,ect)/Police/JAi_____.ttf");
        label_number_texture->setTextColor(sf::Color::White);
        label_number_texture->setString(sf::String(QString::number(i+1).toStdString()));
        label_number_texture->setPosition(sf::Vector2f(1142+(x-1)*79, 205+(y-1)*50));

        list_number_label_texture.append(label_number_texture);

        sf::RectangleShape *border_texture_sprite = new sf::RectangleShape;
        border_texture_sprite->setSize(sf::Vector2f(sprite->getGlobalBounds().width, sprite->getGlobalBounds().height));
        border_texture_sprite->setFillColor(sf::Color::Transparent);
        border_texture_sprite->setOutlineThickness(1);
        border_texture_sprite->setPosition(sprite->getPosition());

        //         border_texture_sprite->setOutlineColor(sf::Color::Blue);

        qDebug() << i;
        if(list_solid_texture->contains(i)){

            border_texture_sprite->setOutlineColor(sf::Color::Red);
        }
        else{
            border_texture_sprite->setOutlineColor(sf::Color::Green);
        }

        list_border_texture_sprite.append(border_texture_sprite);



        if(x == 2 && y == 4){
            x = 0;
            y = 1;

            page_number++;

            sf::Text *new_page = new sf::Text;
            new_page->setCharacterSize(25);
            new_page->setFont(font_jai);
            new_page->setFillColor(sf::Color::White);
            new_page->setString(sf::String("Page "+QString::number(page_number).toStdString()));

            tsw_page_texture.AddString(new_page);

            //continue;
        }

        if(x < 2){
            x++;
        }
        else if(y < 4){
            x = 1;
            y++;
        }
    }
    tsw_page_texture.setPosition(1214, 406);

    /* BORDER PAGE TEXTURE INIT */

    border_page_texture.setSize(sf::Vector2f(173, 262));
    border_page_texture.setFillColor(sf::Color::Transparent);
    border_page_texture.setOutlineColor(sf::Color::Cyan);
    border_page_texture.setOutlineThickness(1);
    border_page_texture.setPosition(1127, 170);

    /* BUTTON WIDGET INIT */

    bw_back.setString("Retour au menu");
    bw_back.setTextColor(sf::Color::White);
    bw_back.LoadFont("D:/Programmation/Fichier ressource(image,ect)/Police/Dimis___.ttf");
    bw_back.setCharacterSize(28);
    bw_back.setPosition(sf::Vector2f(125, 480));

    Button_Widget *bw_menu_place_tile = new Button_Widget;
    bw_menu_place_tile->setTextColor(sf::Color::White);
    bw_menu_place_tile->LoadFont("D:/Programmation/Fichier ressource(image,ect)/Police/Square.ttf");
    bw_menu_place_tile->setCharacterSize(21);
    bw_menu_place_tile->setString("Tuiles");
    bw_menu_place_tile->setPosition(sf::Vector2f(125, 50));

    Button_Widget *bw_menu_place_entity = new Button_Widget;
    bw_menu_place_entity->setTextColor(sf::Color::White);
    bw_menu_place_entity->LoadFont("D:/Programmation/Fichier ressource(image,ect)/Police/Square.ttf");
    bw_menu_place_entity->setCharacterSize(21);
    bw_menu_place_entity->setString("Entites / Objet");
    bw_menu_place_entity->setPosition(sf::Vector2f(125, 100));

    Button_Widget *bw_menu_place_way = new Button_Widget;
    bw_menu_place_way->setTextColor(sf::Color::White);
    bw_menu_place_way->LoadFont("D:/Programmation/Fichier ressource(image,ect)/Police/Square.ttf");
    bw_menu_place_way->setCharacterSize(21);
    bw_menu_place_way->setString("Ronde / Node");
    bw_menu_place_way->setPosition(sf::Vector2f(125, 150));

    Button_Widget *bw_menu_phase = new Button_Widget;
    bw_menu_phase->setTextColor(sf::Color::White);
    bw_menu_phase->LoadFont("D:/Programmation/Fichier ressource(image,ect)/Police/Square.ttf");
    bw_menu_phase->setCharacterSize(21);
    bw_menu_phase->setString("Phase");
    bw_menu_phase->setPosition(sf::Vector2f(125, 200));

    list_bw_menu_editor.append(bw_menu_place_tile);
    list_bw_menu_editor.append(bw_menu_place_entity);
    list_bw_menu_editor.append(bw_menu_phase);
    list_bw_menu_editor.append(bw_menu_place_way);

    bw_clear_tile.setTextColor(sf::Color::White);
    bw_clear_tile.LoadFont("D:/Programmation/Fichier ressource(image,ect)/Police/Dimis___.ttf");
    bw_clear_tile.setCharacterSize(24);
    bw_clear_tile.setString("Effacer");
    bw_clear_tile.setPosition(sf::Vector2f(1214, 475));

    bw_label_texture_used.setTextColor(sf::Color::White);
    bw_label_texture_used.LoadFont("D:/Programmation/Fichier ressource(image,ect)/Police/JAi_____.ttf");
    bw_label_texture_used.setCharacterSize(21);
    bw_label_texture_used.setString("Tuile actuelle");
    bw_label_texture_used.setPosition(sf::Vector2f(1214, 25));

    right_arrow_sprite_menu.setPosition(bw_menu_place_tile->getPosition().x-(bw_menu_place_tile->getGlobalBounds().width/2+5), bw_menu_place_tile->getPosition().y-(bw_menu_place_tile->getGlobalBounds().height/2-9));


    /* RECTANGLE INIT */

    border_right_grid.setSize(sf::Vector2f(1, 1314));
    border_right_grid.setFillColor(sf::Color::White);
    border_right_grid.setPosition(1115, 0);

    sprite_to_set = *list_texture_sprite[DEFAULT_TEXTURE];
    sprite_set = true;

}


void Level_Editor::DrawMainWindow(sf::RenderWindow *window){

    /* TEXTURE GRILLE DRAW */

    controller->getInterface()->setActive(true);
    window->clear(sf::Color::Black);

    for(unsigned int r = 0; r < NUMBER_CASE_Y; r++){

        for(unsigned int c = 0; c < NUMBER_CASE_X; c++){

            window->draw((*tile_map_to_set)(c, r)->case_sprite);
            (*tile_map_to_set)(c, r)->case_sprite.setPosition(250+c*CASE_WIDTH, r*CASE_HEIGHT);
        }
    }

    /* GRILLE DRAW */

    sf::RectangleShape rect_grille;
    rect_grille.setFillColor(sf::Color::Transparent);
    rect_grille.setOutlineColor(sf::Color::White);
    rect_grille.setOutlineThickness(0.5);
    rect_grille.setSize(sf::Vector2f(CASE_WIDTH, CASE_HEIGHT));

    window->draw(border_right_grid);

    for(unsigned int r = 0; r < NUMBER_CASE_Y; r++){

        for(unsigned int c = 0; c < NUMBER_CASE_X; c++){

            rect_grille.setPosition(sf::Vector2f(250+c*CASE_HEIGHT, r*CASE_WIDTH));
            window->draw(rect_grille);
        }
    }

    /* PAGE PLACE ENTITY DRAW : page 1 */

    if(page_menu == 1){

        for(int i = 0; i < list_menu_frame_entity.size(); i++){
            window->draw(list_menu_frame_entity[i]);
        }

        for(int i = 0; i < list_sprite_entity_to_place.size(); i++){
            window->draw(list_sprite_entity_to_place[i]);
        }

        for(int i = 0; i < list_menu_frame_object.size(); i++){
            window->draw(list_menu_frame_object[i]);
        }

        for(int i = 0; i < list_sprite_object_to_place.size(); i++){
            window->draw(list_sprite_object_to_place[i]);
        }

        for(int i = 0; i < list_sprite_entity_placed.size(); i++){
            window->draw(list_sprite_entity_placed[i]);
        }

        for(int i = 0; i < list_sprite_object_placed.size(); i++){
            window->draw(list_sprite_object_placed[i]);
        }

        window->draw(label_entity_to_place);
        window->draw(label_coin_to_place);
        window->draw(label_fruit_to_place);

        if(is_entity_placing == true){
            window->draw(list_sprite_entity_mouse_icone[entity_who_is_placing]);
        }

    }

    /* PAGE PHASE DRAW : page 3 */

    if(page_menu == 3){

        window->draw(tsw_time_frightened_mode);
        window->draw(tsw_phase_level);
        window->draw(tsw_time_chase_mode);
        window->draw(tsw_time_scatter_mode);

        window->draw(label_phase_level);
        window->draw(label_time_chase_mode);
        window->draw(label_time_frightened_mode);
        window->draw(label_time_scatter_mode);

        window->draw(bw_clear_time_mode);
    }

    /* BUTTON_WIDGET DRAW : page x, page 0 */

    window->draw(bw_back);

    for(int i = 0; i < list_bw_menu_editor.size(); i++){
        window->draw(*list_bw_menu_editor[i]);
    }

    if(page_menu == 0){
        window->draw(bw_label_texture_used);
    }

    /* PART PAGE TEXTURE DRAW  : page 0 */

    if(page_menu == 0){

        sprite_to_set.setScale(3, 3);

        frame_sprite_to_set.setPosition(1166, 50);

        sprite_to_set.setPosition(1166, 50);

        window->draw(frame_sprite_to_set);
        window->draw(sprite_to_set);
        window->draw(tsw_page_texture);

        window->draw(border_page_texture);

        for(int i = (page_texture*8); i < list_texture_sprite.size() && i < (page_texture*8)+8; i++){
            window->draw(*list_texture_sprite[i]);
            window->draw(*list_number_label_texture[i]);
        }

        for(int i = (page_texture*8); i < list_border_texture_sprite.size() && i < (page_texture*8)+8; i++){
            window->draw(*list_border_texture_sprite[i]);
        }

        window->draw(bw_clear_tile);
    }

    /* MENU */

    window->draw(right_arrow_sprite_menu);

    window->display();
    controller->getInterface()->setActive(false);

}

void Level_Editor::EventMainWindow(sf::Event event){

    switch (event.type) {
    case sf::Event::KeyReleased:
    {
        sf::Vector2i mouse_position = controller->getInterface()->getMousePosition();

        if(event.key.shift == true && event.key.code == sf::Keyboard::S){

            for(int i = (page_texture*8); i < list_texture_sprite.size() && i < (page_texture*8)+8; i++){

                if(list_texture_sprite[i]->getGlobalBounds().contains(mouse_position.x, mouse_position.y)){

                    if(list_solid_texture->contains(i)){
                        list_border_texture_sprite.at(i)->setOutlineColor(sf::Color::Green);
                        list_solid_texture->removeOne(i);
                    }
                    else{
                        list_solid_texture->append(i);
                        list_border_texture_sprite.at(i)->setOutlineColor(sf::Color::Red);
                    }
                }
            }
        }

        break;
    }
    case sf::Event::MouseButtonPressed:
    {
        sf::Vector2i mouse_position = controller->getInterface()->getMousePosition();

        /* EVENT CLICK TEXTURE GRILLE : page 0, page 1 */

        if(page_menu == 0){

            for(unsigned int r = 0; r < NUMBER_CASE_Y; r++){

                for(unsigned int c = 0; c < NUMBER_CASE_X; c++){

                    Case *_case = (*tile_map_to_set)(c, r);
                    if(_case->case_sprite.getGlobalBounds().contains(mouse_position.x, mouse_position.y)){

                        if(event.mouseButton.button == sf::Mouse::Left){
                            sprite_to_set = _case->case_sprite;
                            sprite_set = true;

                        }
                        else if(event.mouseButton.button == sf::Mouse::Right){

                            //On met la taille de l'image a set a la taille de la case et puis on la remet ensuite a la taille de la frame de presentation de l'image utilisr
                            sprite_to_set.setScale(1, 1);
                            (*tile_map_to_set)(c, r)->case_sprite = sprite_to_set;
                            sprite_to_set.setScale(3, 3);
                        }
                    }
                }
            }
        }
        else if(page_menu == 1){

                for(unsigned int r = 0; r < NUMBER_CASE_Y; r++){

                    for(unsigned int c = 0; c < NUMBER_CASE_X; c++){

                        Case *_case = (*tile_map_to_set)(c, r);
                        if(_case->case_sprite.getGlobalBounds().contains(mouse_position.x, mouse_position.y)){

                            if(event.mouseButton.button == sf::Mouse::Left){

                                for(int i = 0; i < list_sprite_entity_placed.size(); i++){

                                    if(list_sprite_entity_placed[i].getPosition() == _case->case_sprite.getPosition()){
                                        entity_who_is_placing = i;
                                    }
                                }
                            }
                            else if(event.mouseButton.button == sf::Mouse::Right){

                                for(int i = 0; i < list_sprite_entity_placed.size(); i++){

                                    if(list_sprite_entity_placed[i].getPosition() == _case->case_sprite.getPosition()){
                                        list_sprite_entity_placed[i].setPosition(-500, -500);
                                    }
                                }

                                list_sprite_entity_placed[entity_who_is_placing].setPosition(_case->case_sprite.getPosition());
                            }
                        }
                    }
                }
            }

        /* EVENT TEXT SWITCH WIDGET */

        if(tsw_page_texture.CollisionLeftArrow(mouse_position.x, mouse_position.y) && page_menu == 0){
            tsw_page_texture.Previous();
            page_texture = tsw_page_texture.getPositionList();
        }
        else if(tsw_page_texture.CollisionRightArrow(mouse_position.x, mouse_position.y) && page_menu == 0){
            tsw_page_texture.Next();
            page_texture = tsw_page_texture.getPositionList();
        }

        if(tsw_phase_level.CollisionLeftArrow(mouse_position.x, mouse_position.y) && page_menu == 3){

            time_scatter_mode->replace(tsw_phase_level.getPositionList(), tsw_time_scatter_mode.getPositionList());
            time_frightened_mode->replace(tsw_phase_level.getPositionList(), tsw_time_frightened_mode.getPositionList());
            time_chase_mode->replace(tsw_phase_level.getPositionList(), tsw_time_chase_mode.getPositionList());

            tsw_phase_level.Previous();

            tsw_time_chase_mode.setPositionList(time_chase_mode->at(tsw_phase_level.getPositionList()));
            tsw_time_frightened_mode.setPositionList(time_frightened_mode->at(tsw_phase_level.getPositionList()));
            tsw_time_scatter_mode.setPositionList(time_scatter_mode->at(tsw_phase_level.getPositionList()));

            tsw_time_chase_mode.Update();
            tsw_time_frightened_mode.Update();
            tsw_time_scatter_mode.Update();

        }
        else if(tsw_phase_level.CollisionRightArrow(mouse_position.x, mouse_position.y) && page_menu == 3){

            time_scatter_mode->replace(tsw_phase_level.getPositionList(), tsw_time_scatter_mode.getPositionList());
            time_frightened_mode->replace(tsw_phase_level.getPositionList(), tsw_time_frightened_mode.getPositionList());
            time_chase_mode->replace(tsw_phase_level.getPositionList(), tsw_time_chase_mode.getPositionList());

            tsw_phase_level.Next();

            tsw_time_chase_mode.setPositionList(time_chase_mode->at(tsw_phase_level.getPositionList()));
            tsw_time_frightened_mode.setPositionList(time_frightened_mode->at(tsw_phase_level.getPositionList()));
            tsw_time_scatter_mode.setPositionList(time_scatter_mode->at(tsw_phase_level.getPositionList()));

            tsw_time_chase_mode.Update();
            tsw_time_frightened_mode.Update();
            tsw_time_scatter_mode.Update();
        }

        if(tsw_time_chase_mode.CollisionLeftArrow(mouse_position.x, mouse_position.y)){
            tsw_time_chase_mode.Previous();
        }
        else if(tsw_time_chase_mode.CollisionRightArrow(mouse_position.x, mouse_position.y)){
            tsw_time_chase_mode.Next();
        }

        if(tsw_time_frightened_mode.CollisionLeftArrow(mouse_position.x, mouse_position.y)){
            tsw_time_frightened_mode.Previous();
        }
        else if(tsw_time_frightened_mode.CollisionRightArrow(mouse_position.x, mouse_position.y)){
            tsw_time_frightened_mode.Next();
        }

        if(tsw_time_scatter_mode.CollisionLeftArrow(mouse_position.x, mouse_position.y)){
            tsw_time_scatter_mode.Previous();
        }
        else if(tsw_time_scatter_mode.CollisionRightArrow(mouse_position.x, mouse_position.y)){
            tsw_time_scatter_mode.Next();
        }


        /* EVENT CLICK TEXTURE SPRITE */

        for(int i = (page_texture*8); i < list_texture_sprite.size() && i < (page_texture*8)+8; i++){

            if(list_texture_sprite[i]->getGlobalBounds().contains(mouse_position.x, mouse_position.y)){

                if(event.mouseButton.button == sf::Mouse::Left){
                    sprite_to_set = *list_texture_sprite[i];
                    sprite_set = true;

                }
            }
        }

        /* EVENT CLICK BUTTON WIDGET */

        if(bw_back.Contains(mouse_position)){

            dialog_sauv_level->show();
        }

        for(int i = 0; i < list_bw_menu_editor.size(); i++){

            if(list_bw_menu_editor[i]->Contains(mouse_position)){

                if(list_bw_menu_editor[i]->getString() == "Tuiles"){

                    page_menu = 0;

                    right_arrow_sprite_menu.setPosition(list_bw_menu_editor[i]->getPosition().x-(list_bw_menu_editor[i]->getGlobalBounds().width/2-2), list_bw_menu_editor[i]->getPosition().y-(list_bw_menu_editor[i]->getGlobalBounds().height/2-9));
                }
                else if(list_bw_menu_editor[i]->getString() == "Entites / Objet"){

                    page_menu = 1;

                    right_arrow_sprite_menu.setPosition(list_bw_menu_editor[i]->getPosition().x-(list_bw_menu_editor[i]->getGlobalBounds().width/2-45), list_bw_menu_editor[i]->getPosition().y-(list_bw_menu_editor[i]->getGlobalBounds().height/2-9));

                    is_entity_placing = false;
                    entity_who_is_placing = 0;
                }
                else if(list_bw_menu_editor[i]->getString() == "Ronde / Node"){

                    page_menu = 2;

                    right_arrow_sprite_menu.setPosition(list_bw_menu_editor[i]->getPosition().x-(list_bw_menu_editor[i]->getGlobalBounds().width/2-33), list_bw_menu_editor[i]->getPosition().y-(list_bw_menu_editor[i]->getGlobalBounds().height/2-9));

                }
                else if(list_bw_menu_editor[i]->getString() == "Phase"){

                    page_menu = 3;

                    right_arrow_sprite_menu.setPosition(list_bw_menu_editor[i]->getPosition().x-(list_bw_menu_editor[i]->getGlobalBounds().width/2+5), list_bw_menu_editor[i]->getPosition().y-(list_bw_menu_editor[i]->getGlobalBounds().height/2-9));
                }
            }
        }

        if(bw_clear_tile.Contains(mouse_position) && page_menu == 0){
            ResetTileMap();
        }

        /* EVENT CLICK SPRITE ENTITY TO PLACE */

        if(page_menu == 1){

            for(int i = 0; i < list_sprite_entity_to_place.size(); i++){

                if(list_sprite_entity_to_place[i].getGlobalBounds().contains(mouse_position.x, mouse_position.y)){

                    is_entity_placing = true;
                    entity_who_is_placing = i;

                    list_sprite_entity_mouse_icone[i].setPosition(mouse_position.x+25, mouse_position.y+25);
                }
            }
        }

    }
    case sf::Event::MouseMoved:
    {
        sf::Vector2i mouse_position = controller->getInterface()->getMousePosition();

        /* EVENT MOUSE MOVED */

        if(bw_clear_tile.Contains(mouse_position) && page_menu == 0){
            bw_clear_tile.setHighlight(27, sf::Color::White);
        }
        else{
            bw_clear_tile.unHighlight();
        }

        if(bw_clear_time_mode.Contains(mouse_position) && page_menu == 3){
            bw_clear_time_mode.setHighlight(27, sf::Color::White);
        }
        else{
            bw_clear_time_mode.unHighlight();
        }

        if(bw_back.Contains(mouse_position)){
            bw_back.setHighlight(31, sf::Color::White);
        }
        else{
            bw_back.unHighlight();
        }

        if(is_entity_placing == true){
            list_sprite_entity_mouse_icone[entity_who_is_placing].setPosition(mouse_position.x+25, mouse_position.y+25);
        }


    }
    default:
        break;
    }

    controller->getInterface()->Draw();
}

void Level_Editor::SaveLevel(){

    time_scatter_mode->replace(tsw_phase_level.getPositionList(), tsw_time_scatter_mode.getPositionList());
    time_frightened_mode->replace(tsw_phase_level.getPositionList(), tsw_time_frightened_mode.getPositionList());
    time_chase_mode->replace(tsw_phase_level.getPositionList(), tsw_time_chase_mode.getPositionList());

    File_Tools ft(level->getLevelPath());

    QString level_string;
    for(unsigned int r = 0; r < NUMBER_CASE_Y; r++){

        for(unsigned int c = 0; c < NUMBER_CASE_X; c++){

            for(int i = 0; i < list_texture_sprite.size(); i++){

                qDebug()<< r << c;

                if((*tile_map_to_set)(c, r)->case_sprite.getTexture() == list_texture_sprite[i]->getTexture()){
                    if(level_string.length() != 0){
                        level_string+=",";
                    }
                    level_string+=QString::number(i);
                    break;
                }
            }
        }
    }

    QString solid_texture_string;
    for(int i = 0; i < list_solid_texture->size(); i++){

        if(solid_texture_string.length() != 0){
            solid_texture_string+=",";
        }

        solid_texture_string+=QString::number(list_solid_texture->at(i));

    }

    QString time_phase_string = "";
    for(int i = 0; i < max_level; i++){

        QString time_phase_level_string = "";

        if(time_phase_string.length() != 0){
            time_phase_level_string += ",";
        }

        time_phase_level_string += QString::number(time_chase_mode->at(i));
        time_phase_level_string += "-";
        time_phase_level_string += QString::number(time_frightened_mode->at(i));
        time_phase_level_string += "-";
        time_phase_level_string += QString::number(time_scatter_mode->at(i));

        time_phase_string += time_phase_level_string;
    }

    QString pacman_x_string, pacman_y_string;
    QString blue_ghost_x_string, blue_ghost_y_string;
    QString red_ghost_x_string, red_ghost_y_string;
    QString orange_ghost_x_string, orange_ghost_y_string;
    QString pink_ghost_x_string, pink_ghost_y_string;

    for(unsigned int r = 0; r < NUMBER_CASE_Y; r++){

        for(unsigned int c = 0; c < NUMBER_CASE_X; c++){

            for(int i = 0; i < list_sprite_entity_placed.size(); i++){

                if(list_sprite_entity_placed[i].getGlobalBounds().contains(250+CASE_WIDTH*c, CASE_HEIGHT*r)){

                    if(i == 0){
                        pacman_x_string = QString::number(c);
                        pacman_y_string = QString::number(r);
                    }
                    else if(i == 1){
                        blue_ghost_x_string = QString::number(c);
                        blue_ghost_y_string = QString::number(r);
                    }
                    else if(i == 2){
                        red_ghost_x_string = QString::number(c);
                        red_ghost_y_string = QString::number(r);
                    }
                    else if(i == 3){
                        orange_ghost_x_string = QString::number(c);
                        orange_ghost_y_string = QString::number(r);
                    }
                    else if(i == 4){
                        pink_ghost_x_string = QString::number(c);
                        pink_ghost_y_string = QString::number(r);
                    }
                }
            }
        }
    }

    ft.setValueFromAttribute("Tile_Map", level_string);
    ft.setValueFromAttribute("Solid_Tile", solid_texture_string);
    ft.setValueFromAttribute("Time_Phase", time_phase_string);

    ft.setValueFromAttribute("Pacman_X", pacman_x_string);
    ft.setValueFromAttribute("Pacman_Y", pacman_y_string);
    ft.setValueFromAttribute("Blue_Ghost_X", blue_ghost_x_string);
    ft.setValueFromAttribute("Blue_Ghost_Y", blue_ghost_y_string);
    ft.setValueFromAttribute("Red_Ghost_X", red_ghost_x_string);
    ft.setValueFromAttribute("Red_Ghost_Y", red_ghost_y_string);
    ft.setValueFromAttribute("Orange_Ghost_X", orange_ghost_x_string);
    ft.setValueFromAttribute("Orange_Ghost_Y", orange_ghost_y_string);
    ft.setValueFromAttribute("Pink_Ghost_X", pink_ghost_x_string);
    ft.setValueFromAttribute("Pink_Ghost_Y", pink_ghost_y_string);
}

void Level_Editor::ResetTileMap(){

    sf::Texture *default_texture = level->getDefaultTexture();

    for(unsigned int r = 0; r < tile_map_to_set->getHeight(); r++){

        for(unsigned int c = 0; c < tile_map_to_set->getWidth(); c++){
            (*tile_map_to_set)(c, r)->case_sprite.setTexture(*default_texture);
        }
    }
}
