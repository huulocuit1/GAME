#include "Coin.h"



Coin::Coin(float x, float y,float width,float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->type = COIN;
	box = Box(x - 8, y - 8, width, height);
	col = false;
	
	
}


Coin::~Coin()
{
}
void Coin::initCoin(LPDIRECT3DDEVICE9 d3ddv)
{
	this->coin = new Sprite(d3ddv, L"Images\\Mark\\coin.png", 16, 16, 4, 4);
	visible = true;

}
void Coin::updateCoin(LPDIRECT3DDEVICE9 d3ddv, Player*player, float time)
{
	DWORD now = GetTickCount();
	if (now - start > 1000 / 10)
	{
		coin->nextSprite();
		start = now;
	}
	if (col == true)
	{
		visible = false;
		width = 0;
		height = 0;
	}
	box = Box(x - 8, y - 8, width, height);
}
void Coin::drawCoin(float vpx, float vpy)
{
	if (visible == true)
	{
		this->coin->renderSprite(x,y,vpx, vpy);
	}
}
bool Coin::getCol()
{
	return col;
}
void Coin::setCol(bool col)
{
	this->col = col;
}
