#include "select.h"
#include"game.h"
#include<QPainter>
#include<QPaintEvent>
#include"mypushbutton.h"
#include<QTimer>
#include<iostream>
#include<QKeyEvent>
#include"SmallWidget.h"
select::select(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//setWindowFlags(Qt::WindowStaysOnTopHint | Qt::MaximizeUsingFullscreenGeometryHint);
	//this->setFixedSize(700, 1198);
	//setWindowFlags(Qt::WindowStaysOnTopHint);
	this->resize(600, 1027);
	this->move(900, 0);
	SmallWidget* smallwidget = new SmallWidget(this);
	smallwidget->move(40,250);
	//connect(this->ppage3,&game::backtopage2,this,&select::gotopage2);
	//connect(ui.btn2, &QPushButton::clicked, this, [=]() {
	//	emit this->backtopage1();
	//	});
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
			connect(tptime, &QTimer::timeout, tptime, &QTimer::stop);//点击后暂停
			tptime->start(200);
		});

}

select::~select()
{}
void select::paintEvent(QPaintEvent* e)
{
	QPainter* painter = new QPainter(this);
	QPixmap* bkg_pixmap = new QPixmap(":/qtres/bg.png");
	*bkg_pixmap = bkg_pixmap->scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	painter->drawPixmap(0, 0, *bkg_pixmap);
	painter->end();
}

void select::resizeEvent(QResizeEvent*)
{
	std::cout << "resize" << std::endl;
	QList<mypushbutton*>mypushbuttons = this->findChildren<mypushbutton*>();
	for (mypushbutton* button : mypushbuttons)
	{
		button->move((this->width() - button->width()) / 2, this->height() / 2);
	}

}

void select::keyPressEvent(QKeyEvent* event)
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

void select::keyReleaseEvent(QKeyEvent* e)
{
}

double select::getsppeedbyinput(double x)
{
	// 通过选定的参数 a, b, c 来设置二次函数
	double a = 0.00065;  // 二次项系数
	double b = -9.81;     // 一次项系数
	double c = 1000;     // 常数项
	return a * x * x + b * x + c;
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
	SmallWidget* tpsmallwidget = this->findChild<SmallWidget*>();

	int val = tpsmallwidget->getnum();
	//int val = 1000;
	//std::cout << "val:" << val << std::endl;
	
	ppage3->init(getsppeedbyinput(val),4);

	connect(this->ppage3, &game::backtopage2, this, &select::gotopage2);
	this->ppage3->show();
	this->hide();
}