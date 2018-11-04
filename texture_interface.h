#ifndef TEXTURE_INTERFACE_H
#define TEXTURE_INTERFACE_H

#include <QDebug>
#include <QThread>

#include "level_editor.h"

#include <SFML/Graphics.hpp>

class Level_Editor;

class Texture_Interface : public QThread
{
public:
    Texture_Interface(Level_Editor *level_editor);
    ~Texture_Interface();

    void showTextureInterface();
    void hideTextureInterface();

    void createWindow();

    bool isOpen();

    void Draw();

    //getters


    //setters

private:
    sf::RenderWindow *window;

    const unsigned int WINDOW_WIDTH_TEXTURE = 200;
    const unsigned int WINDOW_HEIGHT_TEXTURE = 400;

    Level_Editor *level_editor;

    void run();

};

#endif // TEXTURE_INTERFACE_H
