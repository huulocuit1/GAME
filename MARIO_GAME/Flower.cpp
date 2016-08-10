#include "Flower.h"



Flower::Flower()
{
	
}
Flower::Flower(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	type = FLOWER;
	maxy = y - height/2+7;
	miny = maxy - height-4;
	starty = y;
	
}
void Flower::initFlower(LPDIRECT3DDEVICE9 d3ddv)
{
	
	this->flower = new Sprite(d3ddv, L"Images\\FLowers\\flower_enermy.png", 18, 32, 4, 4);
	this->flower_left= new Sprite(d3ddv, L"Images\\FLowers\\f.png", 18, 32, 2, 2);
	this->flower_right = new Sprite(d3ddv, L"Images\\FLowers\\h.png", 18, 32, 2, 2);
	this->flower_index_2 = new Sprite(d3ddv, L"Images\\Flowers\\flower2.png", 18, 25, 2, 2);
	this->flower_index_3=new Sprite(d3ddv, L"Images\\Flowers\\flower3.png", 18, 25, 4,4);
	this->flower_left_green= new Sprite(d3ddv, L"Images\\FLowers\\a.png", 18, 32, 2, 2);
	this->flower_right_green= new Sprite(d3ddv, L"Images\\FLowers\\b.png", 18, 32, 2, 2);


	this->box = Box(x - 9, y - 16, 16, 32);
	visible = false;
	type = FLOWER;
	_time = 0;
	y = miny;
	index_flower = 1;
}
void Flower::updateFlower(Player*player, float time, Butlet*butlet)
{

	//Xac dinh huong cua Mario 
	if (player->getX() > this->x)
	{
		isleft = false;
	}
	else
	{
		isleft = true;
	}


	if (player->getX() > x - 30 && player->getX() < x + 30)
	{
		
		if (y<=miny)
		{
			visible = false;
		}
		
	}
	else
	{


		//Khung nhin thay 
		if (isleft == true)
		{
			if (player->getX() + BUFFER_WIDTH/2 > x)
			{
				visible = true;

			}
			else
			{
				visible = false;
				y = starty;


			}
		}


		if (isleft == false)
		{
			if (player->getX() - BUFFER_WIDTH/2 < x)
			{
				visible = true;
			}
			else
			{
				visible = false;
				y = starty;
			}
		}
	}



	if (this->y >= maxy)
	{

		if (_time > 2000)
		{
			state = WAIT;
			_time = 0;
		}
		else
		{
			y = maxy;
			state = STOP;
			_time += time;
		}


	}

	if (this->y < miny)
	{
		state = UP;
		
	}
	if (isleft == true)
	{
		if (player->getY() >= this->y)
		{
			direction = ISTOP;
			if (index_flower == 0)
			{

				flower->setIndex(1);
			}
			else if (index_flower == 1)
			{

				flower_index_2->setIndex(1);
			}
			else
			{
				flower_index_3->setIndex(1);
			}

		}
		else
		{

			direction = ISBOTTOM;
			if (index_flower == 0)
			{
				flower->setIndex(0);
			}
			else if (index_flower == 1)
			{
				flower_index_2->setIndex(0);
			}
			else
			{
				flower_index_3->setIndex(0);
			}


		}



	}
	else if (isleft == false)
	{


		if (player->getY() >= this->y)
		{
			direction = ISTOP;
			if (index_flower == 0)
			{
				flower->setIndex(2);
			}
			else if (index_flower == 1)
			{
				flower_index_2->setIndex(1);
			}
			else
			{
				flower_index_3->setIndex(2);
			}



		}
		else
		{
			direction = ISBOTTOM;
			if (index_flower == 0)
			{
				flower->setIndex(3);
			}
			else if (index_flower == 1)
			{
				flower_index_2->setIndex(0);
			}
			else
			{
				flower_index_3->setIndex(3);
			}

		}
	}

	// xu li ban dan
	if (visible == true)
	{
		if (index_flower == 0 || index_flower == 2)
		{
			if (state == WAIT)
			{
				butlet->setVisible(true);
				butlet->setX(x);
				butlet->setY(y + 6);
				if (isleft == true)
				{

					if (direction == ISTOP)
					{


						butlet->setVx(-1.0f);
						butlet->setVy(0.5);

					}
					else
					{
						butlet->setVx(-1.0f);
						butlet->setVy(-0.6f);
					}
				}
				else
				{
					if (direction == ISTOP)
					{

						butlet->setVx(1.0);
						butlet->setVy(0.5);
					}
					else
					{
						butlet->setVx(1.0);
						butlet->setVy(-0.6);
					}
				}


				state = DOWN;


			}
		}
		else
		{
			if (state == WAIT)
			{
				state = DOWN;
			}
		}

	}
	DWORD now = GetTickCount();
	if (state == DOWN)
	{

		vy = -0.3;

		if (isleft == true)
		{

			if (now - start > 1000 / 5)
			{
				if (index_flower == 0)
				{
					flower_left->nextSprite();
				}
				else if (index_flower == 1)
				{
					flower_index_2->nextSprite();
				}
				else
				{
					flower_left_green->nextSprite();
				}


				start = now;
			}
		}
		else if (isleft == false)
		{
			if (now - start > 1000 / 5)
			{
				if (index_flower == 0)
				{
					flower_right->nextSprite();
				}
				else if (index_flower == 1)
				{
					flower_index_2->nextSprite();
				}
				else
				{
					flower_right_green->nextSprite();
				}


				start = now;
			}
		}



	}
	if (state == UP)
	{

		if (state != STOP)
		{
			vy = 1.0f;
		}
		if (isleft == true)
		{
			if (now - start > 1000 / 10)
			{
				if (index_flower == 0)
				{
					flower_left->nextSprite();
				}
				else if (index_flower == 1)
				{
					flower_index_2->nextSprite();
				}
				else
				{
					flower_left_green->nextSprite();
				}

				start = now;
			}
		}
		else if (isleft == false)
		{
			if (now - start > 1000 / 10)
			{
				if (index_flower == 0)
				{
					flower_right->nextSprite();
				}
				else if (index_flower == 1)
				{
					flower_index_2->nextSprite();
				}
				else
				{ 
					flower_right_green->nextSprite();
				}
				
				start = now;
			}
		}
	}
	else if (state == STOP)
	{
		if (visible == true)
		{
			vy = 0;
		}
		else
		{
			this->y = miny;
			state = UP;
		}
	}
	
	
	
	
	this->y += vy;
	this->box = Box(x - 9, y - 16, 16, 32);

}
void Flower::drawFlower(float vpx, float vpy)
{
	if (visible == true)
	{
		
			if (state == DOWN || state == UP)
			{
				if (index_flower == 0)
				{
					if (isleft == true)
					{
						flower_left->renderSprite(x, y, vpx, vpy);

					}
					else
					{
						flower_right->renderSprite(x, y, vpx, vpy);

					}
				}
				else if (index_flower == 1)
				{
					flower_index_2->renderSprite(x, y, vpx, vpy);
				}
				else if (index_flower == 2)
				{
					if (isleft == true)
					{
						flower_left_green->renderSprite(x, y, vpx, vpy);

					}
					else
					{
						flower_right_green->renderSprite(x, y, vpx, vpy);

					}
				}

				
			}
			else if (direction == ISTOP || direction == ISBOTTOM)
			{
				if (index_flower == 0)
				{
					this->flower->renderSprite(x, y, vpx, vpy);
				}
				else if(index_flower==1)
				{
					this->flower_index_2->renderSprite(x, y, vpx, vpy);
				}
				else
				{
					this->flower_index_3->renderSprite(x, y, vpx, vpy);
				}
				
			}

		}
		
		
	
}
Flower::~Flower()
{
}
STATE Flower::getState()
{
	return this->state;
}
