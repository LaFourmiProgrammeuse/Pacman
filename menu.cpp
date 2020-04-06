#include "menu.h"

Menu::Menu(Controller *controller)
{
    qDebug() << "Constructeur Menu";

    page = 0;
    page_level_official = 0;

    this->controller = controller;

    interface = controller->getInterface();

    font_bebas = new sf::Font;
    font_dimis = new sf::Font;

    if(font_dimis->loadFromFile("D:/Programmation/Fichier ressource(image,ect)/Police/DIMIS___.ttf")){
        qDebug() << "Font dimis chargée avec succes";
    }
    else{
        qDebug() << "Echec lors du chargement de la font dimis";
    }

    if(font_bebas->loadFromFile("D:/Programmation/Fichier ressource(image,ect)/Police/Bebas.otf")){
        qDebug() << "Font bebas chargée avec succes";
    }
    else{
        qDebug() << "Echec lors du chargement de la font bebas";
    }

    /* BUTTON */

    Button_Widget *button_exit = new Button_Widget;
    button_exit->setCharacterSize(28);
    button_exit->setString("Quitter");
    button_exit->setTextColor(sf::Color::White);
    button_exit->LoadFont("D:/Programmation/Fichier ressource(image,ect)/Police/DIMIS___.ttf");
    button_exit->setPosition(sf::Vector2f(interface->WINDOW_WIDTH_MENU/2, 425));

    Button_Widget *button_play = new Button_Widget;
    button_play->setCharacterSize(28);
    button_play->setString("Jouer");
    button_play->setTextColor(sf::Color::White);
    button_play->LoadFont("D:/Programmation/Fichier ressource(image,ect)/Police/DIMIS___.ttf");
    button_play->setPosition(sf::Vector2f(interface->WINDOW_WIDTH_MENU/2, 130));

    Button_Widget *button_stats = new Button_Widget;
    button_stats->setCharacterSize(28);
    button_stats->setString("Editeur de carte");
    button_stats->setTextColor(sf::Color::White);
    button_stats->LoadFont("D:/Programmation/Fichier ressource(image,ect)/Police/DIMIS___.ttf");
    button_stats->setPosition(sf::Vector2f(interface->WINDOW_WIDTH_MENU/2, 190));

    Button_Widget *button_level_editor = new Button_Widget;
    button_level_editor->setCharacterSize(28);
    button_level_editor->setString("Statistique");
    button_level_editor->setTextColor(sf::Color::White);
    button_level_editor->LoadFont("D:/Programmation/Fichier ressource(image,ect)/Police/DIMIS___.ttf");
    button_level_editor->setPosition(sf::Vector2f(interface->WINDOW_WIDTH_MENU/2, 250));


    QList<Button_Widget *> page_button_1;
    page_button_1.append(button_exit);
    page_button_1.append(button_play);
    page_button_1.append(button_stats);
    page_button_1.append(button_level_editor);

    list_page_button_widget.append(page_button_1);

    Button_Widget *button_back_p_2 = new Button_Widget;
    button_back_p_2->setCharacterSize(28);
    button_back_p_2->setString("Retour");
    button_back_p_2->setTextColor(sf::Color::White);
    button_back_p_2->LoadFont("D:/Programmation/Fichier ressource(image,ect)/Police/Bebas.otf");
    button_back_p_2->setPosition(sf::Vector2f(48, interface->WINDOW_HEIGHT_MENU-23));

    QList<Button_Widget *> page_button_2;
    page_button_2.append(button_back_p_2);

    list_page_button_widget.append(page_button_2);


    /* TEXT */


    QList<sf::Text *> page_text_1;

    list_page_text.append(page_text_1);

    sf::Text *txt_title_pge_lvl_official = new sf::Text;
    txt_title_pge_lvl_official->setString("Level Officiel");
    txt_title_pge_lvl_official->setCharacterSize(25);
    txt_title_pge_lvl_official->setFont(*font_bebas);
    txt_title_pge_lvl_official->setPosition(controller->getInterface()->WINDOW_WIDTH_MENU/2-txt_title_pge_lvl_official->getGlobalBounds().width/2, 20);
    txt_title_pge_lvl_official->setFillColor(sf::Color::White);

    QList<sf::Text *> page_text_2;
    page_text_2.append(txt_title_pge_lvl_official);

    list_page_text.append(page_text_2);


    /* RECTANGLE */


    QList<sf::RectangleShape> page_rectagle_shape_1;

    list_page_rectangle_shape.append(page_rectagle_shape_1);

    sf::RectangleShape rectangle_cadran_level;
    rectangle_cadran_level.setSize(sf::Vector2f(225, 380));
    rectangle_cadran_level.setOutlineColor(sf::Color::White);
    rectangle_cadran_level.setOutlineThickness(1);
    rectangle_cadran_level.setFillColor(sf::Color::Black);
    rectangle_cadran_level.setPosition(interface->WINDOW_WIDTH_MENU/2-rectangle_cadran_level.getSize().x/2, 67);

    QList<sf::RectangleShape> page_rectagle_shape_2;
    page_rectagle_shape_2.append(rectangle_cadran_level);

    list_page_rectangle_shape.append(page_rectagle_shape_2);


    /* TEXT SWITCH */


    QList<Text_Switch_Widget *> page_tsw_1;

    list_page_txt_switch_widget.append(page_tsw_1);

    sf::Text *txt_page_lvl = new sf::Text;
    txt_page_lvl->setString("Page 1");
    txt_page_lvl->setCharacterSize(25);
    txt_page_lvl->setFont(*font_bebas);
    txt_page_lvl->setFillColor(sf::Color::White);


    Text_Switch_Widget *tsw_page_level = new Text_Switch_Widget;
    tsw_page_level->setCharacterSize(28);
    //tsw_page_level->AddString(txt_page_lvl);
    tsw_page_level->LoadFont("D:/Programmation/Fichier ressource(image,ect)/Police/Bebas.otf");

    QList<Text_Switch_Widget *> page_tsw_2;
    page_tsw_2.append(tsw_page_level);

    list_page_txt_switch_widget.append(page_tsw_2);



    /* LEVEL */


    int number_in_this_page = 0;
    int number_page_level = 1;

    //On ajoute la page 1
    sf::Text *txt_level_page = new sf::Text;
    txt_level_page->setString(sf::String("Page "+QString::number(1).toStdString()));
    txt_level_page->setCharacterSize(25);
    txt_level_page->setFont(*font_bebas);
    txt_level_page->setFillColor(sf::Color::White);

    tsw_page_level->AddString(txt_level_page); qDebug() << "test1";

    QDir dir_level_official("release/Level");
    for(int i = 0; i < dir_level_official.entryInfoList().size(); i++){

        if(dir_level_official.entryList().at(i) != "." && dir_level_official.entryList().at(i) != ".."){

            File_Tools file_tools(dir_level_official.entryInfoList().at(i).absoluteFilePath());

            Level_Description lv;
            lv.button_level = new Button_Widget;
            lv.button_level->setCharacterSize(28);
            lv.button_level->LoadFont("D:/Programmation/Fichier ressource(image,ect)/Police/JAi_____.ttf");
            lv.button_level->setString(sf::String(file_tools.getValueFromAttribute("Level_Name").toStdString()));
            lv.button_level->setTextColor(sf::Color::White);

            lv.level_path = dir_level_official.entryInfoList().at(i).absoluteFilePath();

            list_level_official.append(lv);

            number_in_this_page++;
            lv.button_level->setPosition(sf::Vector2f(controller->getInterface()->WINDOW_WIDTH_MENU/2, 64+number_in_this_page*46));

            //A chaque fois qu'on a 6 nouveaux level on rajoute un page
            if(number_in_this_page == 6){

                number_in_this_page = 0;
                number_page_level++;

                //Texte qui donne le nombre de la page dans le tsw
                sf::Text *txt_level_page = new sf::Text;
                txt_level_page->setString(sf::String("Page "+QString::number(number_page_level).toStdString()));
                txt_level_page->setCharacterSize(25);
                txt_level_page->setFont(*font_bebas);
                txt_level_page->setFillColor(sf::Color::White);

                tsw_page_level->AddString(txt_level_page);
            }

        }
    }
    tsw_page_level->setPosition(interface->WINDOW_WIDTH_MENU/2, 415);

//    eh = new Event_Handler<Menu>(200);
//    eh->newEvent(&Test, 1200, true, this);
//    eh->start(Qt::NormalEventPriority);

    /* TEXTURE - SPRITE */

    texture_pacman_title.loadFromFile("pacman_title.png");
    sprite_pacman_title.setTexture(texture_pacman_title);

    sprite_pacman_title.setPosition(225-sprite_pacman_title.getGlobalBounds().width/2, 30);

    /* BACKGROUND */

    texture_background_1.loadFromFile("background_menu_1.jpg");
    sprite_background_1.setTexture(texture_background_1);

    sprite_background_1.rotate(90);
    sprite_background_1.setPosition(450, 0);
    sprite_background_1.setScale(1.64, 2.94);

    qDebug() << "test";

}

void Menu::Event(sf::Event event){

    switch (event.type) {
    case sf::Event::MouseMoved:
    {
        sf::Vector2i mouse_position = interface->getMousePosition();
        for(int i = 0; i < list_page_button_widget[page].size(); i++){

            if(list_page_button_widget[page][i]->Contains(sf::Vector2i(mouse_position.x, mouse_position.y))){

                list_page_button_widget[page][i]->setHighlight(34, sf::Color::Yellow);
            }
            else{
                list_page_button_widget[page][i]->unHighlight();
            }
        }

        interface->Draw();
        break;
    }
    case sf::Event::MouseButtonPressed:
    {
        sf::Vector2i mouse_position = interface->getMousePosition();

        /* EVENT BUTTON */

        for(int i = 0; i < list_page_button_widget[page].size(); i++){

            if(list_page_button_widget[page][i]->Contains(sf::Vector2i(mouse_position.x, mouse_position.y))){

                list_page_button_widget[page][i]->unHighlight();

                if(page == 0 && list_page_button_widget[page][i]->getString() == "Jouer"){
                    list_page_button_widget[page][i]->unHighlight();

                    page = 1;
                    interface->Draw();
                }
                else if(page == 0 && list_page_button_widget[page][i]->getString() == "Editeur de carte"){

                    controller->getInterface()->setVisibleMainWindow(false);

                    QString file_path = QFileDialog::getOpenFileName(nullptr, "Open Level", "release/Level", "Fichier txt (*.txt)");
                    if(file_path == ""){

                        list_page_button_widget[page][i]->unHighlight();
                        controller->getInterface()->Draw();
                    }
                    else{

                        Level *level = new Level(file_path);
                        controller->CreateLevelEditor(level);

                        controller->getInterface()->setEditorWindowSize();
                        //controller->getInterface()->Draw();
                    }

                    controller->getInterface()->setVisibleMainWindow(true);
                }
                else if(page == 0 && list_page_button_widget[page][i]->getString() == "Statistique"){

                }
                else if(page == 1 && list_page_button_widget[page][i]->getString() == "Retour"){
                    list_page_button_widget[page][i]->unHighlight();

                    page = 0;
                    interface->Draw();
                }
                else{

                }
            }
        }

        /* EVENT TEXT SWITCH */

        for(int i = 0; i < list_page_txt_switch_widget[page].size(); i++){

            if(list_page_txt_switch_widget[page][i]->CollisionLeftArrow(mouse_position.x, mouse_position.y)){
                list_page_txt_switch_widget[page][i]->Previous();

                page_level_official = list_page_txt_switch_widget[page][i]->getPositionList();

                interface->Draw();
            }
            else if(list_page_txt_switch_widget[page][i]->CollisionRightArrow(mouse_position.x, mouse_position.y)){
                list_page_txt_switch_widget[page][i]->Next();

                page_level_official = list_page_txt_switch_widget[page][i]->getPositionList();

                interface->Draw();
            }
        }

        /* EVENT LEVEL */

        if(page == 1){

            for(int i = 0; i < list_level_official.size(); i++){

                if(list_level_official[i].button_level->Contains(sf::Vector2i(mouse_position.x, mouse_position.y))){

                    if(controller->getGame() == 0){

                        Level *level = new Level(list_level_official[i].level_path);
                        controller->CreateGame(level);

                    }
                }
            }
        }
    }
    default:
        break;
    }


}

void Menu::Draw(sf::RenderWindow *window){

    interface->setActive(true);
    window->clear(sf::Color::Black);

    for(int i = 0; i < list_page_rectangle_shape[page].size(); i++){
        window->draw(list_page_rectangle_shape[page][i]);
    }

    for(int i = 0; i < list_page_button_widget[page].size(); i++){
        window->draw(*list_page_button_widget[page][i]);
    }

    for(int i =0; i < list_page_text[page].size(); i++){
        window->draw(*list_page_text[page][i]);
    }

    for(int i = 0; i < list_page_txt_switch_widget[page].size(); i++){
        window->draw(*list_page_txt_switch_widget[page][i]);
    }

    /* DRAW PAGE 2 */

    if(page == 0){

        window->draw(sprite_pacman_title);
        //window->draw(sprite_background_1);
    }

    /* DRAW PAGE 1 */

    if(page == 1){

        for(int i = (page_level_official)*6; i < list_level_official.size() && i != ((page_level_official)*6)+6; i++){
            window->draw(*list_level_official[i].button_level);
        }

    }


    window->display();
    interface->setActive(false);
}

void Menu::setPage(int page){
    this->page = page;
}

void Menu::Test(){
    qDebug() << "test";
}
