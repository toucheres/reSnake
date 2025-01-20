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
	double xlengthnum;
	double ylengthnum;
	double snakewidth=1;
	const snakeClass* snakeonMap;
	std::vector<int>wallLocation;
	double getpx(double x);
	double getpy(double y);
	void addWall(int x, int y);
	void addWall(int index);
	void addWall(int* indexArr,int size);
};

