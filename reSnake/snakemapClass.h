#pragma once
#include <vector>
class snakemapClass
{
public:
	snakemapClass();
	~snakemapClass();
	int xlengthp;
	int ylengthp;
	int xlengthnum;
	int ylengthnum;
	std::vector<int>wallLocation;
	int getpx(int x);
	int getpy(int y);
	void addWall(int x, int y);
	void addWall(int index);
	void addWall(int* indexArr,int size);
};

