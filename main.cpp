#include <QApplication>

#include "interface.h"
#include "controller.h"

#include "file_tools.h"

int main(int argc, char *argv[]){

    QApplication app(argc, argv);

    //File_Tools fr("release/Level/level_1.txt");
    //fr.setValueFromAttribute("Level_Name", "Level2");

    Controller controller;

    return app.exec();
}
