#pragma once
#include <vector>

#include<ctime>
#include"snakeClass.h"
class foodClass
{
public:
	foodClass(snakeClass* tsnake);
	~foodClass();
	std::vector<int> foodLocation;
	bool avoidTheWall;
	bool avoidTheSnake;
	int numOfFood;
	const snakeClass* snakeonMap;
	void setFood();
	void setFood(int num);
	void setFood(int x,int y);
	void setFood(int *arr, int size);
	void isFoodEaten(int x,int y);
	void foodmove();
};

