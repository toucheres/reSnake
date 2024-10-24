#pragma once
#include <vector>
class foodClass
{
public:
	foodClass();
	~foodClass();
	std::vector<int> foodLocation;
	bool avoidTheWall();
	bool avoidTheSnake();
	int numOfFood();
	void setFoodnum(int num);
	void setFoodnum(int x,int y);
	void setFoodnum(int *arr, int size);
	void foodmove();
};

