#include "select.h"
#include"game.h"
#include<QPainter>
#include<QPaintEvent>
#include"mypushbutton.h"
#include<QTimer>
select::select(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//setWindowFlags(Qt::WindowStaysOnTopHint | Qt::MaximizeUsingFullscreenGeometryHint);
	//this->setFixedSize(700, 1198);
	setWindowFlags(Qt::WindowStaysOnTopHint);
	this->resize(600, 1027);
	this->move(500, 0);
	
	//connect(this->ppage3,&game::backtopage2,this,&select::gotopage2);
	connect(ui.btn2, &QPushButton::clicked, this, [=]() {
		emit this->backtopage1();
		});
	connect(ui.btn4, &QPushButton::clicked, this, [=]() {
		emit this->gotopage3();
		});

	mypushbutton* text = new mypushbutton(QString(":/setting/qtres/setting/pause.png"));
	text->setParent(this);
	text->move((this->width() - text->width()) / 2, this->height() / 2);
	connect(text, &mypushbutton::released, this, [=]()
		{
			QTimer* tptime = new QTimer(this);
			connect(tptime, &QTimer::timeout, this, &select::gotopage3);
			connect(tptime, &QTimer::timeout, tptime, &QTimer::stop);//�������ͣ
			tptime->start(200);
		});

}

select::~select()
{}
void select::paintEvent(QPaintEvent* e)
{
	QPainter* painter = new QPainter(this);
	QPixmap* bkg = new QPixmap(":/qtres/bg.png");
	painter->drawPixmap(0, 0, *bkg);
	painter->end();
}

void select::gotopage2()
{
	this->show();
	this->ppage3->hide();
	delete(ppage3);
	ppage3 = NULL;
}
void select::gotopage3()
{
	this->ppage3 = new game;
	connect(this->ppage3, &game::backtopage2, this, &select::gotopage2);
	this->ppage3->show();
	this->hide();
}