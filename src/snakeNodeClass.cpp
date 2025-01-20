#include "snakeNodeClass.h"

snakeNodeClass::snakeNodeClass(int x, int y, int direction,int type)
{
	this->x = x;
	this->y = y;
	this->direction = direction;
	this->type = type;
	this->shewanDirection = undefined;
	//shewandirection属性在转向时会被修改，此处修改仅用于初始化
}

snakeNodeClass::~snakeNodeClass()
{
}
