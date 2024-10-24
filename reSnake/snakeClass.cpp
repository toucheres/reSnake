#include "snakeClass.h"

snakeClass::snakeClass()
{
	this->color = green;
	this->lenght = 3;
	this->direction = up;
	this->state = alive;
	this->speed = 1000;
	//³õÊ¼»¯ÉßÉí
	//this->body.push_back(*new snakeNodeClass());
}

snakeClass::~snakeClass()
{
}

void snakeClass::move()
{
}

void snakeClass::changeDirection(int direction)
{
}

void snakeClass::setlenght(int lenght)
{
}

void snakeClass::skill()
{
}
