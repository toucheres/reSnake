#include "snakeNodeClass.h"

snakeNodeClass::snakeNodeClass(int x, int y, int direction,int type)
{
	this->x = x;
	this->y = y;
	this->direction = direction;
	this->type = type;
	this->shewanDirection = undefined;
	//shewandirection������ת��ʱ�ᱻ�޸ģ��˴��޸Ľ����ڳ�ʼ��
}

snakeNodeClass::~snakeNodeClass()
{
}
