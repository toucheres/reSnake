#pragma once
#include <list>
#include <vector>
#include <deque>
#include "snakeNodeClass.h"
#include "snakeEnum.h"
#include <QDebug>
#include <iostream>
#include <qobject.h>

class snakeClass :public QObject
{
	Q_OBJECT
public:

	snakeClass();
	~snakeClass();
	int color;
	int live;
	int speed;
	int state;
	int lenght;
	int direction;
	bool flag_direction_changed;
	bool is_moving;
	int direactionBefore;
	std::deque<snakeNodeClass> body;
	void move();
	void changeDirection(int direction);
	void setlength(int length);
	void skill();
	snakeNodeClass getNextHead();
	snakeNodeClass getNextTail();
	void updataState();
	void checkState();//����(��Ȼǰ����ת��ǰ��ͬʱ����ʱ�и��ʳ�����������������)
	void printSnake();
	void getLonger();
	void getShorter();
	signals:
		void stateChange();
};

