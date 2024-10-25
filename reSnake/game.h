#pragma once

#include <QMainWindow>
#include "ui_game.h"
#include "snakeClass.h"
#include "foodClass.h"
#include "snakemapClass.h"


class game : public QMainWindow
{
	Q_OBJECT

public:
	snakeClass* snake;
	foodClass* food;
	snakemapClass* snakemap;
	game(QWidget *parent = nullptr);
	~game();
	void init();
	void logic();
	void paintEvent(QPaintEvent*);
	void resizeEvent(QResizeEvent*);



signals:
	void backtopage2();
private:
	Ui::gameClass ui;
};
