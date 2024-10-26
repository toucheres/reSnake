#pragma once
#define LONG_LENGTH 7
#define NORMAL_LENGTH 5
#define SHORT_LENGTH 3

//枚举类型
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
};//方向枚举

enum { green, red };//颜色枚举
enum { alive, dead };//状态枚举

