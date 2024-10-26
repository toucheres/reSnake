#pragma once
#include <vector>
#include "snakeEnum.h"
#include "snakeClass.h"
class snakemapClass
{
public:
	snakemapClass(snakeClass* tpsnake);
	~snakemapClass();
	int xlengthp;
	int ylengthp;
	int xlengthnum;
	int ylengthnum;
	const snakeClass* snakeonMap;
	std::vector<int>wallLocation;
	int getpx(int x);
	int getpy(int y);
	void addWall(int x, int y);
	void addWall(int index);
	void addWall(int* indexArr,int size);
};

