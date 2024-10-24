#pragma once
#include "snakeEnum.h"
class snakeNodeClass
{
public:
	snakeNodeClass(int x, int y,int tpye, int direction = up);
	~snakeNodeClass();
	int x;
	int y;
	int direction;
	int type;
};

