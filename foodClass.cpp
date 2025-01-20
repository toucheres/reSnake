#include "foodClass.h"
#include "snakeEnum.h"
#include <QtGlobal>
#include <QTime>

foodClass::foodClass(snakeClass* tpsnake)
{
	avoidTheSnake = true;
	avoidTheWall = true;
	numOfFood = 0;
	this->snakeonMap = tpsnake;
	this->xlengthnum = 0;
	this->ylengthnum = 0;

	//this->foodLocation.resize(1);
	

}

foodClass::~foodClass()
{
}




void foodClass::setFood()
{
	if (this->foodLocation.empty())
	{
		
	start:
		int tp = rand();
		srand(rand());
		tp = 1 + rand() % ((int)(this->xlengthnum * this->ylengthnum+1) );
		for (std::deque<snakeNodeClass>::const_iterator it = this->snakeonMap->body.begin(); it != this->snakeonMap->body.end(); it++)
		{
			int tplocation = it->x + ((it->y) - 1) * (this->xlengthnum);
			if (tplocation == tp)
			{
				srand(rand()+tp);
				std::cout << "纠正错误点" << tp;
				goto start;
			}
			if (tp % (int)this->xlengthnum == 0)
			{
				srand(rand() + tp);
				std::cout << "纠正错误点" << tp;
				goto start;
			}
			if (tp % (int)this->xlengthnum == 1)
			{
				srand(rand() + tp);
				std::cout << "纠正错误点" << tp;
				goto start;
			}

		}
		setFood(tp);
	}
	//if (this->foodLocation.empty())
	//{
	//	int tp = 1;
	//	setFood(tp);
	//}
}

void foodClass::setFood(int num)
{
	this->foodLocation.push_back(num);
}

void foodClass::setFood(int x, int y)
{
	int tplocation = (y-1) * this->xlengthnum + x;
	this->foodLocation.push_back(tplocation);
}

void foodClass::setFood(int* arr, int tsize)
{
	for (int i = 0; i < tsize; i++)
	{
		setFood(arr[i]);
	}
}

bool foodClass::isFoodEaten(int x, int y)
{
	if (snakeonMap->live == alive)
	{
		int tplocation = x + (y - 1) * this->xlengthnum;
		for (std::vector<int>::iterator it = foodLocation.begin(); it != foodLocation.end(); it++)
		{
			if (tplocation == *it)
			{
				std::cout << "Food Eaten:" << x << " " << y << std::endl;
				//foodLocation.erase(it);
				it = foodLocation.erase(it);
				numOfFood--;
				return 1;
			}
		}
	}
	return 0;
}

void foodClass::deleteFood()
{
	this->foodLocation.clear();
}

void foodClass::foodmove()
{
}
