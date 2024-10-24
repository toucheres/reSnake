#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_reSnake.h"
#include "game.h"
#include "select.h"

class reSnake : public QMainWindow
{
    Q_OBJECT

public:
    reSnake(QWidget *parent = nullptr);
    ~reSnake();
    select* ppage2=NULL;
    void paintEvent(QPaintEvent*);
    void resizeEvent(QResizeEvent*);
public slots:
    void gotopage2();
    void gotopage1();
private:
    Ui::reSnakeClass ui;
};
