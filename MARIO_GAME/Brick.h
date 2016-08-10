#pragma once
#include "Box.h"
#include "Player.h"
#include "Objects.h"
#include "Sprite.h"

class Brick:public Objects
{
	Sprite*brick;
	DWORD animation_time;
	DWORD time_start;
	Sprite*a;
	Sprite*b;
	Sprite*c;
	Sprite*d;
	bool col;
	bool visible;
public :
	float width;
	float height;
	float p;
	float q;

public:
	void initBrick(LPDIRECT3DDEVICE9 d3ddv);
	void updateBrick(LPDIRECT3DDEVICE9 d3ddv, Player*player, float time);
	void drawBrick(float vpx, float vpy);
	Brick(float x, float y, float width, float height);
	Brick();
	~Brick();
	void setCol(bool col)
	{
		this->col = col;
	}

};
typedef vector<Brick*>Bricklist;

