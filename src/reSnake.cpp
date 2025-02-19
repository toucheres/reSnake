#include "reSnake.h"
#include "game.h"
#include<QPushbutton>
#include"select.h"
#include"mypushbutton.h"
#include<iostream>
#include<QTimer>
#include<QTime>
#include<QPainter>
#include<QPaintEvent>
#include<QApplication>
#include<QtGUI>
reSnake::reSnake(QWidget *parent)
    : QMainWindow (parent)
{
    ui.setupUi(this);
    //setWindowFlags(Qt::WindowStaysOnTopHint|Qt::MaximizeUsingFullscreenGeometryHint);
    //setWindowFlags(Qt::WindowStaysOnTopHint);
    this->resize(600, 1027);
    this->move(900,0);
    this->ppage2 = new selectpage(this);
    //按钮
    //std::cout<< "anxia";
    mypushbutton* text = new mypushbutton(QString(":/setting/qtres/setting/pause.png"),this);
    text->setParent(this);
    text->move((this->width()-text->width())/2,this->height()/2);
    connect(text, &mypushbutton::released, this, [=]() 
        {
        connect(tptime, &QTimer::timeout, this, &reSnake::gotopage2);
        connect(tptime, &QTimer::timeout, tptime ,&QTimer::stop);//点击后暂停
        tptime->start(200);
        });

    //接受page2的gotopage1信号
    connect(this->ppage2, &selectpage::backtopage1, this, &reSnake::gotopage1);

}

reSnake::~reSnake()
{
    delete ppage2;
}

void reSnake::paintEvent(QPaintEvent* e)
{
    QPainter* painter = new QPainter(this);
    QPixmap* bkg_pixmap = new QPixmap(":/qtres/bg.png");
    *bkg_pixmap = bkg_pixmap->scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    painter->drawPixmap(0, 0, *bkg_pixmap);
    painter->end();
    delete painter;
    delete bkg_pixmap;
}

void reSnake::resizeEvent(QResizeEvent*)
{
    std::cout << "resize" << std::endl;
    QList<mypushbutton*>mypushbuttons = this->findChildren<mypushbutton*>();
    for (mypushbutton* button : mypushbuttons)
    {
        button->move((this->width()-button->width())/2,this->height()/2);
    }

}

void reSnake::gotopage2()
{
    this->ppage2->show();//子界面出现
    QTime dieTime = QTime::currentTime().addMSecs(200);//5为延迟时间，可更改
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->hide();//主界面关闭
}
void reSnake::gotopage1()
{
    this->show();
    QTime dieTime = QTime::currentTime().addMSecs(5);//5为延迟时间，可更改
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->ppage2->hide();
}