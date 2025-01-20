#pragma once
#include <vector>

#include<ctime>
#include"snakeClass.h"
class foodClass
{
public:
	foodClass(snakeClass* tsnake);
	~foodClass();
	double xlengthnum;
	double ylengthnum;
	std::vector<int> foodLocation;
	bool avoidTheWall;
	bool avoidTheSnake;
	int numOfFood;
	const snakeClass* snakeonMap;
	void setFood();
	void setFood(int num);
	void setFood(int x,int y);
	void setFood(int *arr, int size);
	bool isFoodEaten(int x,int y);
	void deleteFood();
	void foodmove();
};

