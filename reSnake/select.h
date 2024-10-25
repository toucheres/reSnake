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
	void paintEvent(QPaintEvent*);
	void resizeEvent(QResizeEvent*);
	void keyPressEvent(QKeyEvent* e);
	void keyReleaseEvent(QKeyEvent* e);
public slots:
	void gotopage2();
	void gotopage3();
signals:
	void backtopage1();

private:
	Ui::selectClass ui;
};
