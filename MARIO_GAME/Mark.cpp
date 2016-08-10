#include "Mark.h"



Mark::Mark()
{
	this->col = false;
	x = 100;
	y = 24;
	_xcoin = 100;
	_ycoin = 64;
	_vycoin = 0;
	vy = 0;
	starty = y;
	hit = 0;
	this->box = Box(x -width/2, y - height/2, 16, 16);

	
	
}
Mark::Mark(TYPE_COIN type_coin,float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->vx = 0;
	this->vy = 0;
	this->_xcoin = x;
	this->_ycoin = y;
	this->width = width;
	this->height = height;
	this->box = Box(x - width/2, y - height/2, width, height);
	starty = y;
	startx = x;
	this->type = MARK;
	this->visible = true;
	this->type_coin = type_coin;
}


Mark::~Mark()
{
	
}
void Mark::initMark(LPDIRECT3DDEVICE9 d3ddv)
{
	this->mark = new Sprite(d3ddv, L"Images\\Mark\\MarkBrick.png", 16, 16, 4, 4);
	this->notmark = new Sprite(d3ddv, L"Images\\Mark\\notMark.png", 16, 16, 1, 1);
	this->coin = new Sprite(d3ddv, L"Images\\Mark\\coin.png", 16, 16, 4, 4);
	this->Star = new Sprite(d3ddv, L"Images\\Mark\\star.png", 16, 16, 6, 6);
	this->star_coin= new Sprite(d3ddv, L"Images\\Mark\\star_coin.png", 16, 16, 1, 1);

	


	
}
void Mark::updateMark(LPDIRECT3DDEVICE9 d3ddv, Player*player)
{

	DWORD now = GetTickCount();
	if (player->getX() > this->x)
	{
		isleft = false;
	}
	else
	{
		isleft = true;
	}




	if (isleft == true)
	{

		if (player->getX() + BUFFER_WIDTH/2+100>x)
		{
			visible = true;
		}

		else
		{
			visible = false;
			
			y = starty;


		}


	}
	else if (isleft == false)
	{


		if (player->getX() - BUFFER_WIDTH/2-100 < x)
		{
			visible = true;
		}
		else
		{
			visible = false;
	
			y = starty;
		}


	}

	if (now - start > 1000 /10)
	{
		
		if (star == true)
		{
			Star->nextSprite();
			star_coin->nextSprite();
		}
		else
		{
			coin->nextSprite();
			mark->nextSprite();
		}
		start = now;
	}
	
	if (col == true)
	{
		vy = 5;
		_vycoin+=2;
		hit = 1;
	}
	
	if (this->y > starty)
	{
		vy = -0.5;
		
	}
	if (this->_ycoin >(starty+60))
	{
		_vycoin-=1;
	}
	
	if (this->y < starty)
	{
		this->y = starty;

	}
	if (player->getReset() == true)
	{
		hit = 0;
		col = false;
		_ycoin = y;
		_xcoin = x;
		_vycoin = 0;

	}
	y += vy;
	_ycoin += _vycoin;
	this->box = Box(x-width/2, y - height / 2, width, height);
	
}
void Mark::drawMark(float vpx, float vpy)
{
	if (visible == true)
	{
		
			if (col == true && hit == 1)
			{
				if (star)
				{
					visible = false;
				}
				else
				{
					notmark->renderSprite(x, y, vpx, vpy);
				}
				

			}
			else if (col == false && hit == 0)
			{

				if (star == true)
				{
					Star->renderSprite(x, y , vpx, vpy);
				}
				else
				{
					mark->renderSprite(x, y, vpx, vpy);
				}
				
			}
			else
			{
				if (type_coin == _COIN)
				{
					if (_vycoin > 0 || _vycoin <0 && _ycoin>y + 20)
					{
						if (star)
						{
							star_coin->renderSprite(_xcoin, _ycoin, vpx, vpy);
						}
						else
						{
							coin->renderSprite(_xcoin, _ycoin, vpx, vpy);
						}
					

					}
					
				}

				if (star)
				{
					visible = false;
				}
				else
				{
					notmark->renderSprite(x, y, vpx, vpy);
				}
				

			}

		
	}
	
	
}
