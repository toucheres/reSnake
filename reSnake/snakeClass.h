#pragma once
#include <list>
#include "snakeNodeClass.h"
#include "snakeEnum.h"
#include <QDebug>
#include <iostream>

class snakeClass
{
public:

	snakeClass();
	~snakeClass();
	int color;
	int speed;
	int state;
	int lenght;
	int direction;
	std::list<snakeNodeClass> body;
	void move();
	void changeDirection(int direction);
	void setlenght(int lenght);
	void skill();
	snakeNodeClass getNextHead();
	void updataState();
};

