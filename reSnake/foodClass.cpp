#include "foodClass.h"
#include "snakeEnum.h"

foodClass::foodClass(snakeClass* tpsnake)
{
	avoidTheSnake = true;
	avoidTheWall = true;
	numOfFood = 0;
	this->snakeonMap = tpsnake;
	

}

foodClass::~foodClass()
{
}




void foodClass::setFood()
{
	if (this->foodLocation.empty())
	{
	start:
		srand(time(NULL));
		int tp = 1 + rand() % (NUM_OF_LENGTH_X * NUM_OF_LENGTH_Y);
		for (std::deque<snakeNodeClass>::const_iterator it = this->snakeonMap->body.begin(); it != this->snakeonMap->body.end(); it++)
		{
			int tplocation = it->x + ((it->y) - 1) * NUM_OF_LENGTH_X;
			if (tplocation == tp)
			{
				goto start;
			}
		}
		setFood(tp);
	}
}

void foodClass::setFood(int num)
{
	this->foodLocation.push_back(num);
}

void foodClass::setFood(int x, int y)
{
	int tplocation = (y-1) * NUM_OF_LENGTH_X + x;
	this->foodLocation.push_back(tplocation);
}

void foodClass::setFood(int* arr, int tsize)
{
	for (int i = 0; i < tsize; i++)
	{
		setFood(arr[i]);
	}
}

void foodClass::isFoodEaten(int x, int y)
{
	int tplocation = x + (y - 1) * NUM_OF_LENGTH_X;
	for (std::vector<int>::iterator it = foodLocation.begin(); it != foodLocation.end(); it++)
	{
		if (tplocation == *it)
		{
			foodLocation.erase(it);
			numOfFood--;
		}
	}
}

void foodClass::foodmove()
{
}
