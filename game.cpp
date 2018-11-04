#include "game.h"

Game::Game(Level *level, Controller *controller)
{
    qDebug() << "Constructeur Game";

    font_bebas = new sf::Font;

    if(font_bebas->loadFromFile("D:/Programmation/Fichier ressource(image,ect)/Police/Bebas.otf")){
        qDebug() << "Font bebas chargée avec succes";
    }
    else{
        qDebug() << "Echec lors du chargement de la font bebas";
    }

    this->level = level;
    this->controller = controller;

    game_state = Wait_Start;
    ghost_state = Scatter_Mode;

    controller->getInterface()->setGameWindowSize();

    list_solid_texture = level->getListSolidTexture();
    list_texture = level->getListTexture();

    tile_map = level->getTileMap();

    sf::RectangleShape separation_line;
    separation_line.setSize(sf::Vector2f(864, 4));
    separation_line.setPosition(0, 512);

    list_shape.append(separation_line);

    bw_score.setFont(*font_bebas);
    bw_score.setCharacterSize(23);
    bw_score.setString("Score :");
    bw_score.setPosition(sf::Vector2f(50, 535));
    bw_score.setTextColor(sf::Color::White);

    bw_score_value.setFont(*font_bebas);
    bw_score_value.setCharacterSize(23);
    bw_score_value.setString("0");
    bw_score_value.setPosition(sf::Vector2f(93, 520));
    bw_score_value.setFillColor(sf::Color::White);

    bw_best_score.setFont(*font_bebas);
    bw_best_score.setCharacterSize(23);
    bw_best_score.setString("Meilleure score :");
    bw_best_score.setPosition(sf::Vector2f(230, 535));
    bw_best_score.setTextColor(sf::Color::White);

    bw_best_score_value.setFont(*font_bebas);
    bw_best_score_value.setCharacterSize(23);
    bw_best_score_value.setString("0");
    bw_best_score_value.setPosition(sf::Vector2f(310, 520));
    bw_best_score_value.setFillColor(sf::Color::White);

    bw_life.setFont(*font_bebas);
    bw_life.setCharacterSize(23);
    bw_life.setString("Vie Restante :");
    bw_life.setPosition(sf::Vector2f(429, 535));
    bw_life.setTextColor(sf::Color::White);

    bw_life_value.setFont(*font_bebas);
    bw_life_value.setCharacterSize(23);
    bw_life_value.setString("20");
    bw_life_value.setPosition(sf::Vector2f(495, 520));
    bw_life_value.setFillColor(sf::Color::White);


}

Game::~Game()
{
    qDebug() << "Destructeur Game";

    delete level;
}

void Game::Event(sf::Event event){

    switch (event.type) {
    case sf::Event::KeyReleased:
    {
        break;
    }
    default:
        break;
    }
}

void Game::Draw(sf::RenderWindow *window){

    controller->getInterface()->setActive(true);
    window->clear(sf::Color::Black);

    Matrix<Case*> tile_map = *level->getTileMap();

    for(unsigned int r = 0; r < NUMBER_CASE_Y; r++){

        for(unsigned int c = 0; c < NUMBER_CASE_X; c++){

          window->draw(tile_map(c, r)->case_sprite);
          tile_map(c, r)->case_sprite.setPosition(c*CASE_WIDTH, r*CASE_HEIGHT);
        }
    }

    for(int i = 0; i < list_shape.size(); i++){
        window->draw(list_shape[i]);
    }

    window->draw(bw_score);
    window->draw(bw_score_value);
    window->draw(bw_best_score);
    window->draw(bw_best_score_value);
    window->draw(bw_life);
    window->draw(bw_life_value);

    window->display();
    controller->getInterface()->setActive(false);
}

Game_State Game::getGameState(){
    return game_state;
}
