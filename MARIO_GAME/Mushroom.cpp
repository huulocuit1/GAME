#include "Mushroom.h"



Mushroom::Mushroom()
{
}


Mushroom::~Mushroom()
{
}
Mushroom::Mushroom(KIND_Mush kind_mush, float x, float y, float width, float height)
{
	this->width = width;
	this->x = x;
	this->y = y;
	this->height = height;
	startx = x;
	statty = y;
	type = MUSHROOM;
	kind = kind_mush;
	state = ALIVE;
	this->box = Box(x - width/2, y - height/2, width, height);
	_time = 0;

	number_col = 0;
	left_decoration = true;

	


}
void Mushroom::initMushroom(LPDIRECT3DDEVICE9 d3ddv)
{

	this->mushroom = new  Sprite(d3ddv, L"Images\\Mushroom\\Mushroom.png", 16, 16, 2, 2);
	this->mushroom_die = new Sprite(d3ddv, L"Images\\Mushroom\\die.png", 16, 9, 1, 1);
	this->mushroom_jump = new Sprite(d3ddv, L"Images\\Mushroom\\mush_jump.png", 20, 27, 4, 4);
	this->notjump = new Sprite(d3ddv, L"Images\\Mushroom\\notjump.png",20, 25, 2,2);
	visible = true;
	if (kind == _JUMP)
	{
		vy = -1;
	}
	else
	{
		vy = 0;
	}


}
void Mushroom::updateMushroom(Player*player, float time)
{

	DWORD now = GetTickCount();
	if (player->getX() > this->x)
	{
		isleft = false;
	}
	else if(player->getX()<this->x)
	{
		isleft = true;
	}
	if (state == ALIVE)
	{


		if (!isleft)
		{
			if (player->getX() - BUFFER_WIDTH / 2 < x)
			{
				visible = true;
				if (kind == _JUMP)
				{
					vy = -1;
				}


			}
			else
			{
				visible = false;
				vx = 0;
				vy = 0;
			}
		}
		else
		{
			if (player->getX() + BUFFER_WIDTH / 2 > x)
			{
				visible = true;
				if (kind == _JUMP)
				{
					vy = -1;
				}

			}
			else
			{
				visible = false;
				vx = 0;
				vy = 0;
			}
		}
	}
	

	
	
	if (visible == true)
	{
		vx = -0.8f;
		/*isleft = true;*/
		if (kind == NORMAL)
		{
			if (col)
			{
				if (_time > 400)
				{
					visible = false;
					
					_time = 0;
					player->setVy(-1);

				}
				else if (_time > 100 && _time < 200)
				{
					player->setVy(3);
					if (player->getVx() > 0)
					{
						player->setVx(0.4);
					}
					else
					{
						player->setVx(-0.4);
					}

					_time += time;
				}
				else
				{
					player->setVy(2);
					if (player->getVx() > 0)
					{
						player->setVx(0.4);
					}
					else
					{
						player->setVx(-0.4);
					}
					
					vx = 0;
					vy = 0;
					
					state = _DIE;
					_time += time;
				}
				
				
			}
			if (col_v_left)
			{
				
				if (col_v_right&&x>before_x)
				{
					col_v_left = false;
				
					
				}
				else
				{
					vx = 1;
				}
				
				
			}
			 if(col_v_right)
			{
				
				if (col_v_left)
				{
					col_v_right = false;
					
				}
				else
				{
					vx = -1;
				}
			
				
			}
			
			 if (!col_v_left&&!col_v_right)
			 {
				 before_x = x;
			 }

			
		}
	  if (kind == _JUMP)
		{
			if (col_bottom)
			{
				vy = 0.5f;
			}
			if (col_top)
			{
				vy = -0.5;
			}
			if (col_v_left)
			{

				if (col_v_right&&x > before_x)
				{
					col_v_left = false;


				}
				else
				{
					vx = 1;
				}


			}
			if (col_v_right)
			{

				if (col_v_left)
				{
					col_v_right = false;

				}
				else
				{
					vx = -1;
				}


			}

			if (!col_v_left&&!col_v_right)
			{
				before_x = x;
			}



			if (number_col < 2)
			{
				if (isleft == true)
				{
					vx = -0.5f;					

				}
				else
				{

					vx = 0.5f;
				}
				if (y > statty)
				{
					vy = -vy;
					col_bottom = false;
				}
				
			}

			
			

		}
	if(kind==NOT_JUMP)
		{
			
			not_jump = false;
			if (col)
			{
				if (_time > 400)
				{
					visible = false;

					_time = 0;
					player->setVy(-1);

				}
				else if (_time > 100 && _time < 200)
				{
					player->setVy(3);
					if (player->getVx() > 0)
					{
						player->setVx(0.4);
					}
					else
					{
						player->setVx(-0.4);
					}

					_time += time;
				}
				else
				{
					player->setVy(2);
					if (player->getVx() > 0)
					{
						player->setVx(0.4);
					}
					else
					{
						player->setVx(-0.4);
					}

					vx = 0;
					vy = 0;

					state = _DIE;
					_time += time;
				}


			}
			if (col_v_left)
			{

				if (col_v_right&&x > before_x)
				{
					col_v_left = false;


				}
				else
				{
					vx = 1;
				}


			}
			if (col_v_right)
			{

				if (col_v_left)
				{
					col_v_right = false;

				}
				else
				{
					vx = -1;
				}


			}

			if (!col_v_left&&!col_v_right)
			{
				before_x = x;
			}
		}


		if (state == ALIVE)
		{
			if (player->getY() < 224 || player->getY() > 400)
			{
				visible = false;
				x = startx;
				y = statty;
			}
			else
			{
				visible = true;
			}

		}



	}
	
	else
	{
		if (x < 0)
		{
			x < 0;
			visible = false;
		}
		else
		{
			
		}
		
	}
	
	if (not_jump)
	{
		if (_time > 300)
		{
			
			
			
			player->setVy(-1);
		}
		else if (_time > 100 && _time < 300)
		{
			player->setVy(3);
			if (player->getVx() > 0)
			{
				player->setVx(0.6);
			}
			else
			{
				player->setVx(-0.6);
			}

			_time += time;
		}
		else
		{
			player->setVy(2);
			if (player->getVx() > 0)
			{
				player->setVx(0.6);
			}
			else
			{
				player->setVx(-0.6);
			}
			kind = NOT_JUMP;
			vx = 0;
			vy = -1;

			
			_time += time;
		}
		
	}

	
	

	
	if (now - start > 1000 / 10)
	{

		mushroom->nextSprite();
		mushroom_jump->nextSprite();
		notjump->nextSprite();
		this->start = now;
	}
	
	
	
	
	if (player->getAlive() == false)
	{

		vx = 0;
	}
	
	if (col)
	{
		box = Box(0, 0, 0, 0);
	}
	else
	{
		this->box = Box(x - width / 2, y - height / 2, width, height);
	}
	
	
	x += vx;
	y += vy;


}
void Mushroom::drawMushroom(float vpx, float vpy)
{
	if (visible == true)
	{
		if (this->state == ALIVE)
		{
			if (this->kind == NORMAL)
			{
				mushroom->renderSprite(x, y, vpx, vpy);
			}
			else if (this->kind == _JUMP)
			{

				mushroom_jump->renderSprite(x, y, vpx, vpy);
			}
			else if (kind == NOT_JUMP)
			{
				notjump->renderSprite(x, y, vpx, vpy);
			}
		}
		else if (state == _DIE)
		{
			if (kind == NORMAL)
			{
				mushroom_die->renderSprite(x, y - 4, vpx, vpy);
			}
			else 
			{
				mushroom_die->renderSprite(x, y - 8, vpx, vpy);
			}
		
			
		}


	}


}
void Mushroom::killMushroom()
{
	this->visible = false;
}
