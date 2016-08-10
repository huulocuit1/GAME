#pragma once
#include "Objects.h"
#include "Sprite.h"
#include "Player.h"
class Coin:public Objects
{
	Sprite*coin;
	bool visible;
	float width;
	float height;
	float start;
	bool col;
public:

	Coin(float x, float y,float width,float height);
	void initCoin(LPDIRECT3DDEVICE9 d3ddv);
	void updateCoin(LPDIRECT3DDEVICE9 d3ddv, Player*player, float time);
	void drawCoin(float vpx, float vpy);
public:
	bool getCol();
	void setCol(bool col);

	~Coin();
};
typedef vector<Coin*>Coinlist;


