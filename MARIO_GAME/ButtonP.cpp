#include "ButtonP.h"



ButtonP::ButtonP()
{
}


ButtonP::~ButtonP()
{
}
ButtonP::ButtonP(float x, float y)
{
	this->x = x;
	this->y = y;
	
	
	type = BUTTONP;
	number_col = 0;
	box = Box(x - 8, y - 8, 16, 16);
	
}
void ButtonP::Init(LPDIRECT3DDEVICE9 d3ddv)
{
	this->buttonP = new Sprite(d3ddv, L"Images\\ButtonP\\p.png", 16, 32, 4, 4);
	this->brick = new Sprite(d3ddv, L"Images\\ButtonP\\Brick.png", 16, 16, 4, 4);
	this->down_P=new Sprite(d3ddv, L"Images\\ButtonP\\123.png", 16, 32, 4, 4);
	

}
void ButtonP::Update(Player*player, float time)
{
	
	DWORD now = GetTickCount();
	if (now - start > 1000 / 20)
	{
		if (number_col == 1)
		{
			buttonP->nextSprite();
		}
		else if (number_col >=2)
		{
			down_P->nextSprite();
		}
		else if (number_col == 0)
		{
			brick->nextSprite();
		}
		start = now;
	}
	
	if (number_col==0)
	{
		box = Box(x - 8, y - 8, 16, 16);
	}
	else if(number_col==1)
	{
		box = Box(x - 8, y-16, 16, 32);
	}
	else if (number_col >= 2)
	{
		box = Box(x - 8, y - 13, 16, 26);
	}
	else 
	{
		box = Box(0, 0, 0, 0);
	}

}
void ButtonP::Draw(float vpx, float vpy)
{
	if (number_col==0)
	{
		brick->renderSprite(x, y, vpx, vpy);
	}
	else  if (number_col==1)
	{
		buttonP->renderSprite(x, y+8, vpx, vpy);
	}
	else if(number_col>=2)
	{
		down_P->renderSprite(x, y+8, vpx, vpy);
	}
}
