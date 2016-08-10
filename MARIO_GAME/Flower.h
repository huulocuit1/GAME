#pragma once
#include "Objects.h"
#include "Sprite.h"
#include "Player.h"
#include "Butlet.h"

enum DIRECTION
{
	ISTOP,
	ISBOTTOM,
	ISNONE

};
enum STATE
{
	UP,
	WAIT,
	DOWN,
	STOP
};
class Flower:public Objects
{
private:
	float vy;
	Sprite*flower;
	Sprite*flower_left;
	Sprite*flower_right;
	Sprite*flower_right_green;
	Sprite*flower_left_green;


	Sprite*flower_index_2;
	Sprite*flower_index_3;
	float _time;
	boolean visible;
	boolean isleft;
	DIRECTION direction;
	STATE state;

	DWORD start;

	float maxy;
	float miny;
	float width;
	float height;
	float starty;
private:
	int index_flower;
	

public:
	void initFlower(LPDIRECT3DDEVICE9 d3ddv);
	void updateFlower(Player*player,float time,Butlet*butlet);
	void drawFlower(float vpx, float vpy);
	boolean getVisible()
	{
		return visible;
	}
	STATE getState();
	boolean getIsLeft()
	{
		return isleft;
	}
	DIRECTION getDirection()
	{
		return direction;
	}
	void setIndexFlower(int index)
	{
		this->index_flower = index;
	}
public:
	float getX()
	{
		return x;
	}

	Flower();
	Flower(float x, float y, float width, float height);
	~Flower();
};
typedef vector<Flower*>Flowerlist;

