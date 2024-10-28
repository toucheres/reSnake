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

double snakemapClass::getpx(double x)
{
	return this->xlengthp* (36.0/PX_OF_WIDTH_OF_MAP+(x-1)*(PX_OF_LATTICE/PX_OF_WIDTH_OF_MAP));
}

double snakemapClass::getpy(double y)
{
	return this->ylengthp * ((y-1)*(PX_OF_LATTICE/PX_OF_LENGTH_OF_MAP));
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
