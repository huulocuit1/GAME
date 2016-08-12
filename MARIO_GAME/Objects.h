#pragma once
#include <d3dx9.h>
#include "FKeyboard.h"
#include "Utils.h"
#include "Box.h"
extern int currentstate;
extern int playerlife;
extern int score;
extern int changelevel;

enum Type
{
	NONEV,
	NONEH,
	MARK,
	MUSHROOM,
	FLOWER,
	TURTLENORMAL,
	TURTLEJUMP,
	_RECT,
	TUBE,
	BRICK,
	BUTTLET,
	LEAF,
	COIN,
	MUSHRUNNER,
	BUTTONP,
	PLAYER,
	_SPEC,
	DOWN_H,

};


enum eSoundId
{
	// Nhạc nền Map 1
	BACKGROUND_STAGE1,

	// Nhạc nền map 2
	BACKGROUND_STAGE2,

	//Nhạc nền map 3
	BACKGROUND_STAGE3,

	//Tiếng của boss 1
	BOSS_SOUNG1,

	// Mario chết
	DEAD,

	POWER_UP,

	LOST_LIFE,

	EAT_COIN,

	// Thua
	GAME_OVER,

	INTRO,

	JUMP_SOUND,

	WINGAME
};
class Objects
{
protected:
	Type type;
	float x, y;
	float vx, vy;
public:
	Box box;
	Objects();
	~Objects();
public:
	void setX(float x)
	{
		this->x = x;
	}
	void setY(float _y)
	{
		this->y = _y;
	}
	float getX()
	{
		return x;

	}
	float getY()
	{
		return y;
	}
	void setVx(float _vx)
	{
		vx = _vx;

	}
	void setVy(float _vy)
	{

		vy = _vy;

	}
	float getVx()
	{
		return vx;
	}
	void changeVy(float change_val)
	{
		vy -= change_val;
	}
	float getVy()
	{
		return vy;
	}
	Type getType()	{
		return type;
	}
	Box getBox()
	{
		return box;
	}
	void Objects::setType(Type type)
	{
		this->type = type;
	}

};



