#pragma once

#include <QMainWindow>
#include "ui_select.h"
#include"game.h"

class select : public QMainWindow
{
	Q_OBJECT

public:
	select(QWidget *parent = nullptr);
	~select();
	game* ppage3 = NULL;
	double snakewidth;
	void paintEvent(QPaintEvent*);
	void resizeEvent(QResizeEvent*);
	void keyPressEvent(QKeyEvent* e);
	void keyReleaseEvent(QKeyEvent* e);
	double getsppeedbyinput(double speed);
	int getlengthbyinput();
	double getsizebyinput(double size);
public slots:
	void gotopage2();
	void gotopage3();
signals:
	void backtopage1();

private:
	Ui::selectClass ui;
};
