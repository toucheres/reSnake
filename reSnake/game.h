#pragma once

#include <QMainWindow>
#include "ui_game.h"
#include "snakeClass.h"
#include "foodClass.h"
#include "snakemapClass.h"
#include<QKeyEvent>
#include <qtmetamacros.h>
//#include "select.h"


class game : public QMainWindow
{
	Q_OBJECT

public:
	snakeClass* snake;
	foodClass* food;
	snakemapClass* snakemap;
	
	game(QWidget *parent = nullptr);
	~game();
	void init(int speed = 100,int size = 4);
	void logic();
	void paintEvent(QPaintEvent*e);
	void resizeEvent(QResizeEvent*e);
	void keyPressEvent(QKeyEvent*e);
	void keyReleaseEvent(QKeyEvent*e);

signals:
	void backtopage2();
private:
	Ui::gameClass ui;
};
