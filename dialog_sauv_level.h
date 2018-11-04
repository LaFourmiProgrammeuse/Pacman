#pragma once

#include <QDialog>

#include "level_editor.h"

namespace Ui {
class Dialog_Sauv_Level;
}

class Level_Editor;

class Dialog_Sauv_Level : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Sauv_Level(QWidget *parent = 0, Level_Editor *level_editor = 0, Controller *controller = 0);
    ~Dialog_Sauv_Level();

private slots:
    void on_button_save_clicked();

    void on_button_no_save_clicked();

    void on_button_cancel_clicked();

private:
    Ui::Dialog_Sauv_Level *ui;

    Level_Editor *level_editor;
    Controller *controller;
};

#pragma once
