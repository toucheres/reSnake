#include "snakemapClass.h"

snakemapClass::snakemapClass(snakeClass*tpsnake)
{
	this->ylengthnum = NUM_OF_LENGTH_Y;
	this->xlengthnum = NUM_OF_LENGTH_X;
	this->snakeonMap = tpsnake;
	//ylengthp xlengthp 在reSnake.cpp中初始化
}

snakemapClass::~snakemapClass()
{
}

int snakemapClass::getpx(int x)
{
	return this->xlengthp* (36.0/700+(x-1)*(57.0/700));
}

int snakemapClass::getpy(int y)
{
	return this->ylengthp * ((y-1)*(57.0/1198));
}

void snakemapClass::addWall(int x, int y)
{
}

void snakemapClass::addWall(int index)
{
}

void snakemapClass::addWall(int* indexArr, int size)
{
}
