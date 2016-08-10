#include "Butlet.h"



Butlet::Butlet()
{
	
}
Butlet::Butlet(float x, float y)
{
	this->x = x;
	this->y = y;
	
}


Butlet::~Butlet()
{
	
}

void Butlet::initButlet(LPDIRECT3DDEVICE9 d3ddv)
{
	this->butlet = new Sprite(d3ddv, L"Images\\FLowers\\butlet.png", 8, 9, 4, 4);
	isvible = true;
	this->box = Box(x - 4, y - 4, 8, 9);
	type = BUTTLET;
	
}
void Butlet::updatePositionButlet()
{
}
void Butlet::updateButlet(Player*player,float time)
{
	
	DWORD now = GetTickCount();
	if (now - start > 1000 / 10)
	{
		this->butlet->nextSprite();
		start = now;
	}
	y += vy;
	x += vx;
	this->box = Box(x - 4, y - 4, 8, 9);
	
	

}
void Butlet::drawButlet(float vpx, float vpy)
{
	if (isvible == true)
	{
		this->butlet->renderSprite(x, y, vpx, vpy);

	}
	
}