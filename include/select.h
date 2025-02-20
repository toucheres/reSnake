#pragma once

#include <QMainWindow>
#include "ui_select.h"
#include"game.h"

class selectpage : public QMainWindow
{
	Q_OBJECT

public:
	selectpage(QWidget *parent = nullptr);
	~selectpage();
	game* ppage3 = NULL;
	double snakewidth;
	void paintEvent(QPaintEvent*)override;
	void resizeEvent(QResizeEvent*)override;
	void keyPressEvent(QKeyEvent *e) override;
	void keyReleaseEvent(QKeyEvent* e)override;
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
	void closeEvent(QCloseEvent* event) override;
};
