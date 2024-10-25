#include "snakeClass.h"


snakeClass::snakeClass()
{
	this->color = green;
	this->lenght = 3;
	this->direction = up;
	this->state = alive;
	this->speed = 1000;
}

snakeClass::~snakeClass()
{
}

void snakeClass::move()
{
	this->body.pop_back();
	this->body.push_front(this->getNextHead());
	this->updataState();
}

void snakeClass::changeDirection(int direction)
{
	std::cout << "更改方向为：" << direction << std::endl;
}

void snakeClass::setlenght(int lenght)
{
}

void snakeClass::skill()
{
}

snakeNodeClass snakeClass::getNextHead()
{
	snakeNodeClass tp = this->body.front();
	switch(this->direction)
		case up:
	{
		tp.y--;
		break;
	}
	return tp;
}

void snakeClass::updataState()
{
	std::list<snakeNodeClass>::iterator it = this->body.begin();
	it++;
	(*it).type = shesheng;

	it = this->body.end();
	it--;
	it--;
	this->body.back().direction = (*it).direction;
	this->body.back().type = shewei;
}
