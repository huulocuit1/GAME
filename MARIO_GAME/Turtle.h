#pragma once
#include "Objects.h"
#include "Player.h"
#include "Box.h"

class Turtle:public Objects
{
protected:
	float width;
	float height;
	bool visible;
	float startx;
	float starty;
public:
	virtual void initTurtleNormal(LPDIRECT3DDEVICE9 d3ddv) = 0;
	virtual void updateTurtleNormal(Player*player, float time) = 0;
	virtual void drawTurtleNormal(float vpx, float vpy) = 0;
	Turtle();
	~Turtle();
};

