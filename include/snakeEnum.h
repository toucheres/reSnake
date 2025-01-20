#pragma once

#define YOUR_HEADER_FILE_H
//#define SIZE_OF_SNAKE 2
#define LONG_LENGTH 7
#define NORMAL_LENGTH 5
#define SHORT_LENGTH 3
#define NUM_OF_LENGTH_X 11
#define NUM_OF_LENGTH_Y 21

#define PX_OF_LENGTH_OF_MAP 1198.0
#define PX_OF_WIDTH_OF_MAP 700.0

#define PX_OF_LATTICE  ((57.0)/snakewidth)

//ö������
enum {
	empty,
	shetou,
	shesheng,
	shewei,
	shewan,
	other
};

enum {
	up,
	down,
	left,
	right,
	leftup,
	rightup,
	leftdown,
	rightdown,
	uptoleft,
	uptoright,
	downtoleft,
	downtoright,
	righttoup,
	righttodown,
	lefttoup,
	lefttodown,
	undefined
};//����ö��

enum { green, red };//��ɫö��
enum { alive, dead };//״̬ö��

