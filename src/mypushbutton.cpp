#include "mypushbutton.h"
#include <QDebug>
#include <QPropertyAnimation>
#include<iostream>
//mypushbutton::mypushbutton(QWidget *parent) :
//    QPushButton(parent)
//{
//}

mypushbutton::mypushbutton(QString normalImgPath,QWidget* p, QString pressedImgPath) {
    //mypushbutton::mypushbutton(QString normalImgPath, QString pressedImgPath=""){
    this->normalImgPath = normalImgPath;
    this->pressedImgPath = pressedImgPath;
    this->setParent(p);
    QPixmap pix;
    bool res = pix.load(normalImgPath);
    if (!res) {
        qDebug() << normalImgPath << "ͼƬ����ʧ�ܣ�";
        return;
    }

    //this->setFixedSize(pix.size());

    this->resize(pix.width(), pix.height());

    this->setStyleSheet("QPushButton{border:0px;}");

    this->setIcon(pix);

    this->setIconSize(pix.size());
}

//mypushbutton::mypushbutton(QWidget* p) {
//    //mypushbutton::mypushbutton(QString normalImgPath, QString pressedImgPath=""){
//    this->normalImgPath = "";
//    this->pressedImgPath = "";
//
//    QPixmap pix;
//    bool res = pix.load(normalImgPath);
//    if (!res) {
//        qDebug() << normalImgPath << "ͼƬ����ʧ�ܣ�";
//        return;
//    }
//
//    //this->setFixedSize(pix.size());
//
//    this->resize(pix.width(), pix.height());
//
//    this->setStyleSheet("QPushButton{border:0px;}");
//
//    this->setIcon(pix);
//
//    this->setIconSize(pix.size());
//}

void mypushbutton::mousePressEvent(QMouseEvent* e) {
    if (this->pressedImgPath != "") 
    {
        //        this->setStyleSheet("background: rgb(255,150,128)");
        std::cout<< "anxia";
        QPixmap pix;
        bool res = pix.load(this->pressedImgPath);
        if (!res) {
            qDebug() << normalImgPath << "ͼƬ����ʧ�ܣ�";
            return;
        }

        //this->setFixedSize(pix.size());

        this->resize(pix.width(), pix.height());

        this->setStyleSheet("QPushButton{border:0px;}");

        this->setIcon(pix);

        this->setIconSize(pix.size());
    }
    else
    {
        this->downBounce();
    }

    return QPushButton::mousePressEvent(e);
}
void mypushbutton::mouseReleaseEvent(QMouseEvent* e) {
    if (this->pressedImgPath != "") {
        //        this->setStyleSheet("background-color: rgb(0,0,255)");
        QPixmap pix;
        bool res = pix.load(this->normalImgPath);
        if (!res) {
            qDebug() << normalImgPath << "ͼƬ����ʧ�ܣ�";
            return;
        }

        //this->setFixedSize(pix.size());

        this->resize(pix.width(), pix.height());

        this->setStyleSheet("QPushButton{border:0px;}");

        this->setIcon(pix);

        this->setIconSize(pix.size());
    }
    else
    {
        this->upBounce();
    }

    return QPushButton::mouseReleaseEvent(e);
}

void mypushbutton::downBounce() {
    // 1. ������̬����
    QPropertyAnimation* ani = new QPropertyAnimation(this, "geometry");

    // 2. ���ö���ʱ����
    ani->setDuration(200);

    // 3. ��ʼλ��
    ani->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));

    // 4. ����λ��
//    ani->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    ani->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));

    // 5. ���õ�������
    ani->setEasingCurve(QEasingCurve::OutBounce);

    // 6. ִ�ж���
    ani->start();
}
void mypushbutton::upBounce() {
    // 1. ������̬����
    QPropertyAnimation* ani = new QPropertyAnimation(this, "geometry");

    // 2. ���ö���ʱ����
    ani->setDuration(200);

    // 3. ��ʼλ��
    ani->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));

    // 4. ����λ��
//    ani->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    ani->setEndValue(QRect(this->x(), this->y()-10, this->width(), this->height()));

    // 5. ���õ�������
    ani->setEasingCurve(QEasingCurve::OutBounce);

    // 6. ִ�ж���
    ani->start();
}
void mypushbutton::setnormalImgPath(QString path)
{
    this->normalImgPath = path;

}

void mypushbutton::setpressedImgPath(QString path)
{
    this->pressedImgPath = path;
}

mypushbutton::~mypushbutton()
{}