#include "select.h"
#include"game.h"
#include<QPainter>
#include<QPaintEvent>
#include"mypushbutton.h"
#include<QTimer>
#include<iostream>
#include<QKeyEvent>
#include"SmallWidget.h"
#include<qsoundeffect.h>
#include<thread>
#include<qmediaplayer.h>
selectpage::selectpage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//setWindowFlags(Qt::WindowStaysOnTopHint | Qt::MaximizeUsingFullscreenGeometryHint);
	//this->setFixedSize(PX_OF_WIDTH_OF_MAP,\PX_OF_LENGTH_OF_MAP);
	//setWindowFlags(Qt::WindowStaysOnTopHint);
	this->resize(600, 1027);
	this->move(900, 0);
	SmallWidget* selectspeed = new SmallWidget(this);
	selectspeed->move(100,140);
	selectspeed->setnum(50);
	selectspeed->setParent(this);
	selectspeed->setObjectName("pselectspeed");

	SmallWidget* selectsize = new SmallWidget(this);
	selectsize->move(100, 236);
	selectsize->setnum(50);
	selectsize->setParent(this);
	selectsize->setObjectName("pselectsize");
	
	ui.greencheck->setChecked(true);
	ui.redcheck->setCheckable(false);
	ui.normal->setChecked(true);

	mypushbutton* text = new mypushbutton(QString(":/setting/qtres/setting/pause.png"),this);
	text->setParent(this);
	text->move((this->width() - text->width()) / 2, this->height() / 2);
	connect(text, &mypushbutton::released, this, [=]()
		{
			QTimer* tptime = new QTimer(this);
			connect(tptime, &QTimer::timeout, this, &selectpage::gotopage3);
			connect(tptime, &QTimer::timeout, tptime, &QTimer::stop);//点击后暂停
			tptime->start(200);
		});

}

selectpage::~selectpage()
{}
void selectpage::paintEvent(QPaintEvent* e)
{
	QPainter* painter = new QPainter(this);
	QPixmap* bkg_pixmap = new QPixmap(":/qtres/bg.png");
	*bkg_pixmap = bkg_pixmap->scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	painter->drawPixmap(0, 0, *bkg_pixmap);
	painter->end();
	delete painter;
	delete bkg_pixmap;
}

void selectpage::resizeEvent(QResizeEvent*)
{
	std::cout << "resize" << std::endl;
	QList<mypushbutton*>mypushbuttons = this->findChildren<mypushbutton*>();
	for (mypushbutton* button : mypushbuttons)
	{
		button->move((this->width() - button->width()) / 2, this->height() / 2);
	}

}

void selectpage::keyPressEvent(QKeyEvent* event)
{
	switch (event->key())
	{
		case Qt::Key_Escape:
			emit this->backtopage1();
			break;
		default:
			break;
	}
}

void selectpage::keyReleaseEvent(QKeyEvent* e)
{
}

double selectpage::getsppeedbyinput(double x)
{
	// 通过选定的参数 a, b, c 来设置二次函数
	double a = 0.00065;  // 二次项系数
	double b = -9.81;     // 一次项系数
	double c = 1000;     // 常数项
	return a * x * x + b * x + c;
}

int selectpage::getlengthbyinput()
{
	if (ui.normal->isChecked())
		return NORMAL_LENGTH;
	else if (ui.short_2->isChecked())
		return SHORT_LENGTH;
	else if (ui.long_2->isChecked())
		return LONG_LENGTH;
	return 0;
}

double selectpage::getsizebyinput(double x)
{
	return 0.0001 * x * x + 0.005 * x + 0.5;
}
void selectpage::gotopage2()
{
	this->show();
	this->ppage3->hide();
	delete(ppage3);
	ppage3 = NULL;
}
void selectpage::gotopage3()
{
	this->ppage3 = new game(this);

	SmallWidget* tpsmallwidget = this->findChild<SmallWidget*>("pselectspeed");
	int valofspeed = tpsmallwidget->getnum();

	SmallWidget* tpsmallwidget2 = this->findChild<SmallWidget*>("pselectsize");
	int valofsize = tpsmallwidget2->getnum();

	
	//getsizebyinput(valofsize)
	this->snakewidth=getsizebyinput(valofsize);
	
	this->ppage3->snakemap->snakewidth= getsizebyinput(valofsize);
	this->ppage3->snakemap->xlengthnum*= getsizebyinput(valofsize);
	this->ppage3->snakemap->ylengthnum*= getsizebyinput(valofsize);
	this->ppage3->food->xlengthnum=this->ppage3->snakemap->xlengthnum;
	this->ppage3->food->ylengthnum=this->ppage3->snakemap->ylengthnum;

	//this->ppage3->snakemap->snakewidth = 1;
	//this->ppage3->snakemap->xlengthnum *= 1;
	//this->ppage3->snakemap->ylengthnum *= 1;
	ppage3->init(getsppeedbyinput(valofspeed), getlengthbyinput(), getsizebyinput(valofsize));
	//ppage3->init(getsppeedbyinput(valofspeed), 3, 1);

	connect(this->ppage3, &game::backtopage2, this, &selectpage::gotopage2);
	this->ppage3->show();
	this->hide();
}

void selectpage::closeEvent(QCloseEvent* event)
{
	emit this->backtopage1();
}
