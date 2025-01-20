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

       // ��׹
    void downBounce();
    // �ϵ�
    void upBounce();
    //��������ͼƬ·��
    void setnormalImgPath(QString path);
    //���ð�ѹͼƬ·��
    void setpressedImgPath(QString path);
    // ������ʾ��ͼƬ·��
    QString normalImgPath;
    // ��ѹʱ��ͼƬ·��
    QString pressedImgPath;

    // ��갴���¼�
    void mousePressEvent(QMouseEvent* e);
    // ����ͷ��¼�
    void mouseReleaseEvent(QMouseEvent* e);

private:
	Ui::mypushbuttonClass ui;
};
