#include "MushRunner.h"



MushRunner::MushRunner()
{
}


MushRunner::~MushRunner()
{
}
MushRunner::MushRunner(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	box = Box(x - 8, y - 8,16 , 16);
	type = MUSHRUNNER;
	
	
}
void MushRunner::initMushRunner(LPDIRECT3DDEVICE9 d3ddv)
{
this->mushrunner = new Sprite(d3ddv, L"Images\\Mushroom\\24.png", 16, 16, 1, 1);
	this->leaf = new Sprite(d3ddv, L"Images\\Leaf\\left.png", 16, 16, 1, 1);
	_time = 0;
	starty = y;
	startx = x;
	number_col_ismush = 0;
	number_col_isleaf = 0;
	

}
void MushRunner::updateMushRunner(Player*player, float time)
{
	if (ismush == true)
	{
		if (number_col_ismush == 1)
		{
			if (_time > 100)
			{
				isvisible = true;
				if (y <= starty + height-1)
				{
					vy = 0.13f;
				}
				else
				{
					vy = 0;
					vx = 0.4f;
				}
				if (x > startx + 16)
				{
					vy = -3.0f;

				}
				else if (x <= startx&&y < starty)
				{
					vy = -0.2f;
				}
				_time = 0;
			}
			else
			{
				_time +=time;
			}
			
			
		}
		if (number_col_ismush == 2)
		{
			x = 0;y = 0;
			width = 0;
			height = 0;
			isvisible = false;
			
			
		}
	}
	if(ismush == false)
	{
		if (number_col_isleaf == 1)
		{
			isvisible = true;
			if (y < starty + 48 && x == startx)
			{
				vy = 0.4f;
				vx = 0.3f;
			}
			
			if (x > startx + 32&&y<=starty+48)
			{
				vx = -0.4f;
				vy = -0.3f;
			}
			else if(x < startx&&y <= starty+48)
			{
				vx = 0.4f;
				vy = -0.3f;
			}
			
		}
		else if (number_col_isleaf == 2)
		{
			
			x = 0;y = 0;
			width = 0;
			height = 0;
			isvisible = false;
			
		}
	}
	

	x += vx;
	y += vy;
	box = Box(x - 8, y - 6, 16, 16);
	
	

}
void MushRunner::drawMushRunner(float vpx, float vpy)
{
	if (isvisible == true)
	{
		if (ismush == true)
		{
			this->mushrunner->renderSprite(x, y+2, vpx, vpy);
		}
		if(ismush==false)
		{
			this->leaf->renderSprite(x, y, vpx, vpy);
		}
		
	}
}
