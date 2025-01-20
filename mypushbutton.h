#pragma once

#include <QWidget>
#include "ui_mypushbutton.h"
#include<QPushButton>
#include <QString>

class mypushbutton : public QPushButton
{
	Q_OBJECT

public:

	~mypushbutton();
    //explicit mypushbutton(QWidget *parent = 0);
    mypushbutton(QString normalImgPath, QString pressedImgPath = "");
    // mypushbutton(QWidget*p);
    //mypushbutton(QString normalImgPath, QString pressedImgPath);

       // 下坠
    void downBounce();
    // 上弹
    void upBounce();
    //设置正常图片路径
    void setnormalImgPath(QString path);
    //设置按压图片路径
    void setpressedImgPath(QString path);
    // 正常显示的图片路径
    QString normalImgPath;
    // 按压时的图片路径
    QString pressedImgPath;

    // 鼠标按下事件
    void mousePressEvent(QMouseEvent* e);
    // 鼠标释放事件
    void mouseReleaseEvent(QMouseEvent* e);

private:
	Ui::mypushbuttonClass ui;
};
