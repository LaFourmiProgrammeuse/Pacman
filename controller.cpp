#include "controller.h"

Controller::Controller()
{
    interface = new Interface(this);

    qDebug() << "Constructeur Controller";

    state = In_Menu;
    menu = new Menu(this);

    //Ne rien mettre apres ces 2 lignes !
    this->start(QThread::NormalPriority);
    interface->startTreatEvent();
}

Controller::~Controller()
{
    qDebug() << "Destructeur Controller";

    delete level_editor;
    delete game;
    delete menu;
    delete interface;

    this->exit(0);
}

void Controller::run(){


    while(1){

        //qDebug() << "Controller loop";

        sf::Clock clock;

        if(state == In_Menu){

            if(((1/framerate) - clock.getElapsedTime().asSeconds()) >= 0){

                this->usleep((1/framerate) - clock.getElapsedTime().asSeconds());
            }
//            qDebug() << (1/framerate) - clock.getElapsedTime().asSeconds() << a;
//            a++;

            continue;
        }
        else if(state == In_Editor){

            if((1/framerate) - clock.getElapsedTime().asSeconds() >= 0){

                this->usleep((1/framerate) - clock.getElapsedTime().asSeconds());
            }
            continue;
        }

        interface->Draw();

        if((1/framerate) - clock.getElapsedTime().asSeconds() >= 0){

            this->usleep((1/framerate) - clock.getElapsedTime().asSeconds());
        }
    }
}

State Controller::getState(){
    return state;
}

void Controller::setState(State state){
    this->state = state;
}

Game *Controller::getGame(){
    return game;
}

Menu *Controller::getMenu(){
    return menu;
}

Interface *Controller::getInterface(){
    return interface;
}

Level_Editor *Controller::getLevelEditor(){
    return level_editor;
}

void Controller::CreateGame(Level *level){

    game = new Game(level, this);

    state = In_Game;
}

void Controller::CreateLevelEditor(Level *level){

    level_editor = new Level_Editor(level, this);

    state = In_Editor;
}

void Controller::CreateSelectLevelEditor(){

    select_level_editor = new Select_Level_Editor(this);

    state = In_Select_Level;
}

