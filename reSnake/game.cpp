#include "game.h"
#include "QPushbutton"
#include<QPainter>
#include<QPaintEvent>
game::game(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::WindowStaysOnTopHint | Qt::MaximizeUsingFullscreenGeometryHint);
	this->setFixedSize(700, 1198);
	this->move(500, 0);
	//buttons
	connect(ui.btn3, &QPushButton::clicked, this, [=]() {
		emit this->backtopage2();
		});
	//logic
	snakeClass* snake = new snakeClass;
	foodClass* food = new foodClass;
	snakemapClass* snakemap = new snakemapClass;
}
void game::paintEvent(QPaintEvent* e)
{
	QPainter* painter = new QPainter(this);
	QPixmap* bkg = new QPixmap(":/qtres/bg.png");
	painter->drawPixmap(0, 0, *bkg);
	painter->end();

}

game::~game()
{}


