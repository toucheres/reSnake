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
    setWindowFlags(Qt::WindowStaysOnTopHint|Qt::MaximizeUsingFullscreenGeometryHint);
    this->setFixedSize(700, 1198);
    this->move(500,0);
    this->ppage2 = new(select);
    //��ť
    //std::cout<< "anxia";
    mypushbutton* text = new mypushbutton(QString(":/setting/qtres/setting/pause.png"));
    text->setParent(this);
    text->move((this->width()-text->width())/2,this->height()/2);
    connect(text, &mypushbutton::released, this, [=]() 
        {
        QTimer* tptime = new QTimer(this);
        connect(tptime, &QTimer::timeout, this, &reSnake::gotopage2);
        connect(tptime, &QTimer::timeout, tptime ,&QTimer::stop);//�������ͣ
        tptime->start(200);
        });

    //����page2��gotopage1�ź�
    connect(this->ppage2, &select::backtopage1, this, &reSnake::gotopage1);

}

reSnake::~reSnake()
{}

void reSnake::paintEvent(QPaintEvent* e)
{
    QPainter* painter = new QPainter(this);
    QPixmap* bkg = new QPixmap(":/qtres/bg.png");
    painter->drawPixmap(0, 0, *bkg);
    painter->end();
}

void reSnake::gotopage2()
{
    this->ppage2->show();//�ӽ������
    QTime dieTime = QTime::currentTime().addMSecs(200);//5Ϊ�ӳ�ʱ�䣬�ɸ���
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->hide();//������ر�
}
void reSnake::gotopage1()
{
    this->show();
    QTime dieTime = QTime::currentTime().addMSecs(5);//5Ϊ�ӳ�ʱ�䣬�ɸ���
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->ppage2->hide();
}