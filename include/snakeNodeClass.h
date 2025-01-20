#pragma once
#include "snakeEnum.h"
class snakeNodeClass
{
public:
	snakeNodeClass(int x, int y, int direction,int tpye);
	~snakeNodeClass();
	int x;
	int y;
	int direction;
	int type;
	int shewanDirection;
};

