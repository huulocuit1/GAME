#pragma once
#include "Objects.h"
#include "Sprite.h"
#include "Player.h"



class Butlet:public Objects
{
private :
	
	
	Sprite* butlet;
	boolean isvible;
	DWORD start;

public:
	void initButlet(LPDIRECT3DDEVICE9 d3ddv);
	void updateButlet(Player*player,float time);
	void drawButlet(float vpx, float vpy);
	void updatePositionButlet();
public:
	void setVisible(boolean visible)
	{
		this->isvible = visible;
	}
	Butlet();
	~Butlet();
	Butlet(float x, float y);
	
};

