#include "dialog_sauv_level.h"
#include "ui_dialog_sauv_level.h"

Dialog_Sauv_Level::Dialog_Sauv_Level(QWidget *parent, Level_Editor *level_editor, Controller *controller) :
    QDialog(parent),
    ui(new Ui::Dialog_Sauv_Level)
{
    ui->setupUi(this);

    this->level_editor = level_editor;
    this->controller = controller;

    this->setWindowTitle("Sauvegarder ?");
}

Dialog_Sauv_Level::~Dialog_Sauv_Level()
{
    delete ui;
}

void Dialog_Sauv_Level::on_button_save_clicked()
{
    this->close();

    level_editor->SaveLevel();

    controller->setState(In_Menu);
    controller->getInterface()->setMenuWindowSize();

    controller->getInterface()->Draw();

}

void Dialog_Sauv_Level::on_button_no_save_clicked()
{
    this->close();

    controller->setState(In_Menu);
    controller->getInterface()->setMenuWindowSize();

    controller->getInterface()->Draw();
}

void Dialog_Sauv_Level::on_button_cancel_clicked()
{
    this->close();
}
