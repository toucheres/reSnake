#pragma once

#include <QMainWindow>
#include "ui_game.h"
#include "snakeClass.h"
#include "foodClass.h"
#include "snakemapClass.h"
#include<QKeyEvent>
#include <qtmetamacros.h>
//#include "selectpage.h"


class game : public QMainWindow
{
	Q_OBJECT

public:
	snakeClass* snake;
	foodClass* food;
	snakemapClass* snakemap;

	double snakewidth = 1;
	
	game(QWidget *parent = nullptr);
	~game();
	void init(int speed = 100,int length = 4,double wight = 1 );
	void logic();
	void paintEvent(QPaintEvent*e);
	void resizeEvent(QResizeEvent*e);
	void keyPressEvent(QKeyEvent*e);
	void keyReleaseEvent(QKeyEvent*e);
	void isover();

signals:
	void backtopage2();
private:
	Ui::gameClass ui;
};
