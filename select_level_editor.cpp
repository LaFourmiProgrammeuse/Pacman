#include "select_level_editor.h"

Select_Level_Editor::Select_Level_Editor(Controller *controller)
{
    qDebug() << "Constructeur SelectLevelEditor";

    this->controller = controller;

}

void Select_Level_Editor::Draw(sf::RenderWindow *window){

}

void Select_Level_Editor::Event(sf::Event event){

    switch (event.type) {
    case sf::Event::MouseMoved:

        break;
    default:
        break;
    }
}
