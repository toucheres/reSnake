#include "snakeClass.h"


snakeClass::snakeClass()
{
	this->color = green;
	this->lenght = 3;
	this->direction = up;
	this->state = alive;
	this->speed = 1000;//speed将在game.init中初始化
	this->flag_direction_changed = false;
	this->direactionBefore = up;
	this->is_moving = false;
	this->live=alive;
}

snakeClass::~snakeClass()
{
}

void snakeClass::move()
{
	if (this->is_moving == false)//保证同一时间只允许一个的运动
	{
		this->is_moving = true;
		this->body.pop_back();
		this->body.push_front(this->getNextHead());
		this->updataState();
		this->is_moving = false;
	}
}

void snakeClass::changeDirection(int tdirection)
{
	if (this->flag_direction_changed != true)
	{
		if (tdirection == up && this->direction != down && this->direction != up)
		{
			this->direactionBefore = this->direction;
			this->direction = up;
			this->flag_direction_changed = true;

		}
		else if (tdirection == down && this->direction != up && this->direction != down)
		{
			this->direactionBefore = this->direction;
			this->direction = down;
			this->flag_direction_changed = true;
		}
		else if (tdirection == left && this->direction != right && this->direction != left)
		{
			this->direactionBefore = this->direction;
			this->direction = left;
			this->flag_direction_changed = true;
		}
		else if (tdirection == right && this->direction != left && this->direction != right)
		{
			this->direactionBefore = this->direction;
			this->direction = right;
			this->flag_direction_changed = true;
		}
	}
}

void snakeClass::setlength(int lenght)
{

}

void snakeClass::skill()
{
}

snakeNodeClass snakeClass::getNextHead()
{
	snakeNodeClass tp = this->body.front();
	switch (this->direction)
	{

	case up:
	{
		tp.y--;
		break;
	}
	case down:
	{
		tp.y++;
		break;
	}
	case left:
	{
		tp.x--;
		break;
	}
	case right:
	{
		tp.x++;
		break;
	}

	}
	return tp;
}

snakeNodeClass snakeClass::getNextTail()
{
	snakeNodeClass tp = this->body.back();
	switch(tp.direction)
	{
	case up:
	{
		tp.y++;
		break;
	}
	case down:
	{
		tp.y--;
		break;
	}
	case left:
	{
		tp.x++;
		break;
	}
	case right:
	{
		tp.x--;
		break;
	}
	}
	tp.type=shewei;
	return tp;
}
	
	


void snakeClass::updataState()
{
	this->body.front().direction = this->direction;

	std::deque<snakeNodeClass>::iterator it = this->body.begin();
	it++;
	if (this->flag_direction_changed == false)
	{
		(*it).type = shesheng;
	}
	else
	{
		(*it).type = shewan;
		switch (this->direactionBefore)
		{
		case up:
		{
			switch (this->direction)
			{
			case left:
			{
				(*it).shewanDirection = leftdown;
				break;
			}
			case right:
			{
				(*it).shewanDirection = rightdown;
				break;
			}
			default:
				break;
			}
			break;
		}
		case down:
		{
			switch (this->direction)
			{
			case left:
			{
				(*it).shewanDirection = leftup;
				break;
			}
			case right:
			{
				(*it).shewanDirection = rightup;
				break;
			}
			default:
				break;
			}
			break;
		}
		case left:
		{
			switch (this->direction)
			{
			case up:
			{
				(*it).shewanDirection = rightup;
				break;
			}
			case down:
			{
				(*it).shewanDirection = rightdown;
				break;
			}
			default:
				break;
			}
			break;
		}
		case right:
		{
			switch (this->direction)
			{
			case up:
			{
				(*it).shewanDirection = leftup;
				break;
			}
			case down:
			{
				(*it).shewanDirection = leftdown;
				break;
			}
			default:
				break;
			}
			break;
		}
		default:
			break;
		}
	}




	it = this->body.end();
	it--;
	it--;
	this->body.back().direction = (*it).direction;
	this->body.back().type = shewei;
}

void snakeClass::checkState()
{
	for (std::deque<snakeNodeClass>::iterator it = this->body.begin(); it != this->body.end(); it++)
	{
		if (it != this->body.begin() && it->x != this->body.back().x && it->y != this->body.back().y)//排除首尾
		{
			it--;
			std::deque<snakeNodeClass>::iterator itpre = it;
			it++;

			it++;
			std::deque<snakeNodeClass>::iterator itnext = it;
			it--;

			if ((itpre->x == it->x && it->x == itnext->x) || (itpre->y == it->y && it->y == itnext->y))
			{
				if (it->type != shesheng)
				{
					std::cout << "已纠正错误" << std::endl;
					it->type = shesheng;
				}
			}
		} 
	}
}


void snakeClass::printSnake()
{
	for (std::deque<snakeNodeClass>::iterator it = this->body.begin(); it != this->body.end(); it++)
	{
		//std::deque<snakeNodeClass>::iterator it2 = it++;
		//it--;
		std::cout << (*it).x << " " << (*it).y << " " << (*it).type << " " << (*it).direction << " " << (*it).shewanDirection << std::endl;
		//if (it2 != this->body.end())
			//std::cout << (*it2).x << " " << (*it2).y << " " << (*it2).type << " " << (*it2).direction << " " << (*it2).shewanDirection << std::endl;	
	}
	std::cout <<"长度为"<<this->lenght << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

void snakeClass::getLonger()
{
	this->body.back().type = shesheng;
	this->body.push_back(getNextTail());
	this->lenght++;
}

void snakeClass::getShorter()
{
	if (this->lenght > 2)
	{
		this->body.pop_back();
		this->body.back().type = shewei;
		this->lenght--;
	}
}
