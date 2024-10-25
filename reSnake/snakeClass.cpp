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

void snakeClass::changeDirection(int tdirection)
{
	if (tdirection == up && this->direction != down && this->direction != up)
	{
		this->direction = up;
	}
	if (tdirection == down && this->direction != up && this->direction != down)
	{
		this->direction = down;
	}
	if (tdirection == left && this->direction != right && this->direction != left)
	{
		this->direction = left;
	}
	if (tdirection == right && this->direction != left && this->direction != right)
	{
		this->direction = right;
	}
}

void snakeClass::setlength(int lenght)
{

}

void snakeClass::skill()
{
}

snakeNodeClass snakeClass::getNextHead()
{
	snakeNodeClass tp = this->body.front();
	switch (this->direction)
	{

	case up:
	{
		tp.y--;
		break;
	}
	case down:
	{
		tp.y++;
		break;
	}
	case left:
	{
		tp.x--;
		break;
	}
	case right:
	{
		tp.x++;
		break;
	}

	}
	return tp;
}

void snakeClass::updataState()
{
	this->body.front().direction = this->direction;

	std::list<snakeNodeClass>::iterator it = this->body.begin();
	it++;
	(*it).type = shesheng;

	it = this->body.end();
	it--;
	it--;
	this->body.back().direction = (*it).direction;
	this->body.back().type = shewei;
}
