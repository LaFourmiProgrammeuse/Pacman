#include "interface.h"

Interface::Interface(Controller *controller)
{
    qDebug() << "Constructeur Interface";

    this->controller = controller;

    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH_MENU, WINDOW_HEIGHT_MENU), "Agario plagiat");

}

Interface::~Interface()
{
    qDebug() << "Destructeur Interface";

    delete window;
}

void Interface::startTreatEvent(){

    //Le draw qui permet de dessiner la fenetre au demarrage sans attendre un mouvement de souris
    Draw();

    while(window->isOpen()){

        sf::Event event;
        while(window->waitEvent(event)){

            switch (event.type) {
            case sf::Event::Closed:
                controller->quit();
                window->close();

                break;
            default:
                break;
            }

                /* REDIRECTION EVENT */

            if(controller->getState() == In_Menu){
                controller->getMenu()->Event(event);
            }
            else if(controller->getState() == In_Game){
                controller->getGame()->Event(event);
            }
            else if(controller->getState() == In_Editor){
                controller->getLevelEditor()->EventMainWindow(event);              
            }
            else if(controller->getState() == In_Select_Level){

            }
        }
    }
}

void Interface::Draw(){

    if(controller->getState() == In_Menu){
        controller->getMenu()->Draw(window);
    }
    else if(controller->getState() == In_Game){
        controller->getGame()->Draw(window);
    }
    else if(controller->getState() == In_Editor){
        controller->getLevelEditor()->DrawMainWindow(window);
    }
}

void Interface::setActive(bool active){
    window->setActive(active);
}

sf::Vector2i Interface::getMousePosition(){
    return sf::Mouse::getPosition(*window);
}

void Interface::setWindowSize(sf::Vector2u size){
    window->setSize(size);
}

void Interface::setGameWindowSize(){

    window->setSize(sf::Vector2u(WINDOW_WIDTH_GAME, WINDOW_HEIGHT_GAME));
    window->setView(sf::View(sf::Vector2f(0+WINDOW_WIDTH_GAME/2, 0+WINDOW_HEIGHT_GAME/2), sf::Vector2f(WINDOW_WIDTH_GAME, WINDOW_HEIGHT_GAME)));
}

void Interface::setVisibleMainWindow(bool visible){
    window->setVisible(visible);
}

void Interface::setEditorWindowSize(){

    window->setSize(sf::Vector2u(WINDOW_WIDTH_EDITOR, WINDOW_HEIGHT_EDITOR));
    window->setView(sf::View(sf::Vector2f(0+WINDOW_WIDTH_EDITOR/2, 0+WINDOW_HEIGHT_EDITOR/2), sf::Vector2f(WINDOW_WIDTH_EDITOR, WINDOW_HEIGHT_EDITOR)));
}

void Interface::setMenuWindowSize(){

    window->setSize(sf::Vector2u(WINDOW_WIDTH_MENU, WINDOW_HEIGHT_MENU));
    window->setView(sf::View(sf::Vector2f(0+WINDOW_WIDTH_MENU/2, 0+WINDOW_HEIGHT_MENU/2), sf::Vector2f(WINDOW_WIDTH_MENU, WINDOW_HEIGHT_MENU)));
}
