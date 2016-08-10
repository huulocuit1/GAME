#pragma once
#include "Objects.h"
#include "Player.h"
#include "Butlet.h"
class Enemy:public Objects
{
protected:
	Enemy();
	~Enemy();
	 virtual void init(LPDIRECT3DDEVICE9 d3ddv, Player*player,Butlet*) = 0;
	virtual	void update(float time) = 0;
	virtual	void Render(float vpx, float vpy) = 0;
};
