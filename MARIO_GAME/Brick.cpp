#include "Brick.h"



Brick::Brick()
{
}


Brick::~Brick()
{
}
Brick::Brick(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	box = Box(x-8, y-height/2, height, width);
	type = BRICK;
	col = false;
	p =0;
	q = 0;

}
void Brick::initBrick(LPDIRECT3DDEVICE9 d3ddv)
{
	time_start = 0;
	brick = new Sprite(d3ddv, L"Images\\Brick\\Brick.png", 16, 16, 4, 4);
	a= new Sprite(d3ddv, L"Images\\Brick\\a.png", 8,8, 1, 1);
		b= new Sprite(d3ddv, L"Images\\Brick\\b.png", 8, 8, 1, 1);
		c= new Sprite(d3ddv, L"Images\\Brick\\c.png", 8, 8, 1, 1);
		d= new Sprite(d3ddv, L"Images\\Brick\\d.png", 8, 8, 1, 1);
	visible = true;
	

}
void Brick::updateBrick(LPDIRECT3DDEVICE9 d3ddv, Player*player, float time)
{
	DWORD now = GetTickCount();
	if (now - animation_time > 1000 / 5)
	{
		brick->nextSprite();
		a->nextSprite();
		b->nextSprite();
		c->nextSprite();
		d->nextSprite();
		
		animation_time = now;
	}
	if (col == true)
	{
		visible = false;
		width = 0;
		height = 0;
		/*box = Box(x, y, width, height);*/
		box = Box(0,0,0,0);
		if (time_start > 500)
		{

			q -=2;
		}
		else
		{
			time_start += time;

			p += (float)1;
			q += (float)1;
		}

	}
	if (player->getButtonP() == true)
	{
		col = true;
	}
	
	
	

}
void Brick::drawBrick(float vpx, float vpy)
{
	if (visible == true)
	{
		brick->renderSprite(x, y, vpx, vpy);
	}
	if (col == true)
	{
		float k = x;
		a->renderSprite(x-p, y+p+q, vpx, vpy);
		b->renderSprite(x + 16 + p, y + p+q, vpx, vpy);
		c->renderSprite(x - p, y - 16 - p+q, vpx, vpy);
		d->renderSprite(x + 16 + p, y - 16 - p+q, vpx, vpy);
	}
}



