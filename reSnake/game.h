#pragma once

#include <QMainWindow>
#include "ui_game.h"

class game : public QMainWindow
{
	Q_OBJECT

public:
	game(QWidget *parent = nullptr);
	~game();
	void paintEvent(QPaintEvent*);

signals:
	void backtopage2();
private:
	Ui::gameClass ui;
};
