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
	void initpixmap();
	void logic();
	void paintEvent(QPaintEvent *e) override;
	void resizeEvent(QResizeEvent*e)override;
	void keyPressEvent(QKeyEvent*e)override;
	void keyReleaseEvent(QKeyEvent *e) override;
	void isover();
	void closeEvent(QCloseEvent* event) override;

signals:
	void backtopage2();
private:
	std::vector<std::unique_ptr<QPixmap>> pixmaps;
	Ui::gameClass ui;
	enum pixmapIndex
	{
		shesheng_pixmap,		  // 0
		shetouleft_pixmap,	  // 1
		shetouright_pixmap,	  // 2
		shetouup_pixmap,		  // 3
		shetoudown_pixmap,	  // 4
		sheweileft_pixmap,	  // 5
		sheweiright_pixmap,	  // 6
		sheweidown_pixmap,	  // 7
		sheweiup_pixmap,		  // 8
		shewanleftdown_pixmap,  // 9
		shewanrightup_pixmap,	  // 10
		shewanleftup_pixmap,	  // 11
		shewanrightdown_pixmap, // 12
		food_pixmap,			  // 13
		bkg_pixmap,			  // 14
	};
};
