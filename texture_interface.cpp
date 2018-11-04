#include "texture_interface.h"

Texture_Interface::Texture_Interface(Level_Editor *level_editor)
{
    qDebug() << "Constructeur Texture_Interface";

    this->level_editor = level_editor;

    this->start(QThread::NormalPriority);

    window = new sf::RenderWindow;
}

Texture_Interface::~Texture_Interface()
{
    qDebug() << "Destructeur Texture_Interface";
}

void Texture_Interface::showTextureInterface(){

    if(window->isOpen()){
        window->setVisible(true);
    }
}

void Texture_Interface::hideTextureInterface(){

    if(window->isOpen()){
        window->setVisible(false);
    }
}

void Texture_Interface::Draw(){
    level_editor->DrawTextureWindow(window);
}


bool Texture_Interface::isOpen(){
    return window->isOpen();
}

void Texture_Interface::run(){

    while(1){

        sf::Event event;
        while(window->waitEvent(event)){
            level_editor->EventTextureWindow(event);
        }
    }
}

void Texture_Interface::createWindow(){

    window->create(sf::VideoMode(WINDOW_WIDTH_TEXTURE, WINDOW_HEIGHT_TEXTURE), "Fenetre Texture");
    this->start(QThread::NormalPriority);
}
