#include "TurtleNormal.h"



TurtleNormal::TurtleNormal()
{
}


TurtleNormal::~TurtleNormal()
{
}
TurtleNormal::TurtleNormal(COLOR_TURTLE color,float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	box = Box(x - width / 2, y-height/2 , width, height);
	this->color = color;
	

	
}
void TurtleNormal::initTurtleNormal(LPDIRECT3DDEVICE9 d3ddv)
{
	if (color == RED||color==RED2)
	{
		this->red_run_left= new Sprite(d3ddv, L"Images\\Turtle\\left.png", 16, 27, 2, 2);
		this->red_run_right = new Sprite(d3ddv, L"Images\\Turtle\\right.png", 16, 27, 2, 2);
		this->red_die = new Sprite(d3ddv, L"Images\\Turtle\\die.png", 16, 16, 1, 1);
		this->hit = new Sprite(d3ddv, L"Images\\Turtle\\hit.png", 16, 16, 4, 4);
		this->red_realive = new Sprite(d3ddv, L"Images\\Turtle\\realive.png", 18, 16, 1, 1);
	}
	else
	{
		this->green_run_left = new Sprite(d3ddv, L"Images\\Turtle\\left_green.png", 16, 27, 4, 4);
		this->green_run_right = new Sprite(d3ddv, L"Images\\Turtle\\right_green.png", 16, 27, 4, 4);
		this->green_die = new Sprite(d3ddv, L"Images\\Turtle\\green_die.png", 16, 16, 1, 1);
		this->green_hit= new Sprite(d3ddv, L"Images\\Turtle\\green_hit.png", 16, 16, 4, 4);
		this->green_realive= new Sprite(d3ddv, L"Images\\Turtle\\realive_green.png", 18, 16, 1, 1);
	}
	state_turtle =RUNNING;
	vx = 0.3f;
	vy = 0;
	left_direction = true;
	startx = x;
	starty = y;
	type = TURTLENORMAL;
	_time = 0;

	_hit = false;

	
}
void TurtleNormal::updateTurtleNormal(Player*player, float time)
{
	if (y > 24)
	{
		vy= -0.5f;
	}
	else
	{
		y = GROUND;
	}
	if (player->getX() > this->x)
	{
		is_left = false;
	}
	else if (player->getX() < this->x)
	{
		is_left = true;
	}
		//

	//set visible 
	if (!is_left)
	{
		if (player->getX() - BUFFER_WIDTH / 2-60< x)
		{
			visible = true;


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
		if (player->getX() + BUFFER_WIDTH / 2+80> x)
		{
			visible = true;

		}
		else
		{

			visible = false;
			vx = 0;
			vy = 0;




		}
	}



	
	if (state_turtle == DIE_)
	{
		//player p ben trai rua
		if (player->getX() < x)
		{
			player_isleft = true;
		}
		//player o ben phai rua
		else if (player->getX() > x)
		{
			player_isleft = false;
		}
	}
	if (state_turtle != HIT)
	{
		if (player->getY() < 224 || player->getY() > 400)
		{
			
			x = startx;
			y = starty;
			vx = 0;
			vy = 0;
		}
		
	}
	
	if (visible)
	{
		if (color == RED || color == RED2)
		{

			updateRedTurtleNormal(player, time);
		}
		else if (color == GREEN)
		{
			updateGreenTurtleNormal(player, time);
		}
	}
	if (player->getAlive() == false)
	{

		vx = 0;
		
	}
	
	x += vx;
	y += vy;
	

	

}
	
	

void TurtleNormal::updateRedTurtleNormal(Player*player, float time)
{
	//huong dung cua player : trai hoac la phai
	
	if (state_turtle == RUNNING)
	{
		if (left_direction == true)
		{
			if (startx - x > 75)
			{
				vx = -vx;
				left_direction = false;
			}
		}
		else if (x > startx)
		{

			left_direction = true;
		}
		if (left_direction)
		{
			vx = -0.5f;
		}
		else
		{
			vx = 0.5f;
		}
		red_hoisinh = 0;
		if (player->getOmRua() == true)
		{
			player->setOmRua(false);
		}

	}
	 if (state_turtle == DIE_)
	{
		if (_hit == false)
		{

			if (player->getOmRua() == false)
			{
				if (red_hoisinh > 6000)
				{

					state_turtle = REALIVE;
					red_hoisinh = 0;
				}

				else
				{
					vx = 0;
					red_hoisinh += time;
				}
			}
			else if (player->getOmRua() == true)
			{
				
				visible = false;
				player->setOmRedTurtle(true);
				player->setOmGreenTurtle(false);
				if (!player_isleft)
				{
					if (player->getStandRight() == true)
					{
						x = player->getX() + 16;
					}
					else
					{
						x = player->getX() - 12;
					}

				}
				else if (player_isleft)
				{
					if (player->getStandRight() == true)
					{
						x = player->getX() + 16;
					}
					else
					{
						x = player->getX() - 12;
					}

				}

				y = player->getY() + 4;


			}


		}
		else
		{
			state_turtle = HIT;
		}


	}
 if (state_turtle == HIT)
	{

		if (player->getOmRua() == true)
		{
			player->setOmRua(false);
		}

		if (player_isleft == true)
		{

			if (player->getStandRight() == true)
			{

				vx = 1.0f;

			}
			
			




		}
		else if (player_isleft == false)
		{
			if (player->getStandRight() == false)
			{
				vx = -1.0f;

			}
			vy = -3;
			


		}
		if (!col_left&&!col_right)
		{
			before_x = x;
			col_mark = false;
		}

		if (col_left)
		{

			if (col_right&&x > before_x)
			{
				col_left = false;


			}
			else
			{
				vx = 2;

			}
			col_mark = false;


		}
		if (col_right)
		{

			if (col_left&&x<before_x)
			{
				col_right = false;

			}
			else
			{
				vx = -2;

			}
			


		}
		if (col_mark)
		{

			vy = -4;
		}


	}
	else if (state_turtle == REALIVE)
	{
		if (red_hoisinh > 1000)
		{
			state_turtle = RUNNING;

		}
		else
		{
			red_hoisinh += time;
		}
	}

	DWORD now = GetTickCount();
	if (now - red_start > 1000 / 10)
	{

		if (left_direction)
		{
			red_run_left->nextSprite();

		}
		else
		{
			red_run_right->nextSprite();

		}
		red_die->nextSprite();
		hit->nextSprite();
		red_realive->nextSprite();
		red_start = now;

	}

	if (state_turtle != DIE_)
	{
		box = Box(x - width / 2, y - height / 2, width, height);

	}
	else
	{
		box = Box(x - 16 / 2, y - 28 / 2, 16, 16);
	}

	if (col)
	{
		if (_time > 300)
		{

			player->setVy(-0.3);
			col = false;
			_time = 0;
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
				player->setVx(1);
			}
			else
			{
				player->setVx(-1);
			}
			state_turtle = DIE_;
			_time += time;
		}


	}
	
	
	
	
}
void TurtleNormal::updateGreenTurtleNormal( Player*player, float time)
{
	
	DWORD now = GetTickCount();
	
	
	if (state_turtle == RUNNING)
	{
		if (left_direction)
		{
			vx = -0.5f;
		}
		else
		{
			vx = 0.5f;
		}
		green_hoisinh = 0;
		if (green_col_botoom)
		{

			
			if (_time > 400)
			{
				vy = -0.6;
				_time=0;
				green_col_botoom = false;
			}
			else
			{
				vy = -vy;
				_time += time;
			}

		}
		
		

	}
	else if (state_turtle == DIE_)
	{
		if (_hit == false)
		{

			if (player->getOmRua() == false)
			{

				if (green_hoisinh > 5000)
				{
					state_turtle = REALIVE;
					green_hoisinh = 0;
				}
				else
				{
					vx = 0;
					green_hoisinh += time;
				}
			}
			else if (player->getOmRua() == true)
			{
				visible = false;
				player->setOmRedTurtle(false);
				player->setOmGreenTurtle(true);

				if (player->getVx() >= 0)
				{
					x = player->getX() + 16;
				}
				else if (player->getVx() <= 0)
				{
					x = player->getX() - 12;
				}

				y = player->getY() + 4;


			}

		}
		else
		{
			state_turtle = HIT;
		}

	}
	else if (state_turtle == HIT)
	{
		if (!col_brick)
		{
			if (player_isleft == true)
			{

				if (player->getStandRight() == true)
				{

					vx = 1.6f;

				}

				vy = -2;


			}
			else if (player_isleft == false)
			{
				if (player->getStandRight() == false)
				{
					vx = -1.6f;

				}

				vy = -2;

			}
		}
		if (!col_left&&!col_right)
		{
			before_x = x;
		}
		if (col_left)
		{

			if (col_right&&x > before_x)
			{
				col_left = false;


			}
			else
			{
				vx = 1;
			}


		}
		if (col_right)
		{

			if (col_left)
			{
				col_right = false;

			}
			else
			{
				vx = -1;
			}


		}

	}
	else if (state_turtle == REALIVE)
	{
		if (green_hoisinh > 1000)
		{
			state_turtle = RUNNING;

		}
		else
		{
			green_hoisinh += time;
		}
	}
	

	
	if (now - green_start > 1000 / 10)
	{

		if (left_direction)
		{
			green_run_left->nextSprite();
			
		}
		else
		{
			green_run_right->nextSprite();
			
		}
		green_die->nextSprite();
		green_hit->nextSprite();
		green_realive->nextSprite();
		green_start = now;

	}	
	
	if (state_turtle != DIE_)
	{
		box = Box(x - width / 2, y - height / 2, width, height);

	}
	else
	{
		box = Box(x - 16 / 2, y - 28 / 2, 16, 16);
	}
	



}
void TurtleNormal::drawTurtleNormal(float vpx, float vpy)
{
	
	
	if (visible == true)
	{
		
		if (color == RED||color==RED2)
		{
			if (left_direction)
			{
				switch (state_turtle)
				{
				case RUNNING:
					red_run_left->renderSprite(x, y, vpx, vpy);
					break;
				case DIE_:
					red_die->renderSprite(x, y, vpx, vpy);
					break;
				case HIT:
					hit->renderSprite(x, y, vpx, vpy);
					break;
				case REALIVE:
					red_realive->renderSprite(x, y-4, vpx, vpy);
					break;
				default:
					break;
				}
			}
			else
			{
				switch (state_turtle)
				{
				case RUNNING:
					red_run_right->renderSprite(x, y, vpx, vpy);
					break;
				case DIE_:
					red_die->renderSprite(x, y, vpx, vpy);
					break;
				case HIT:
					hit->renderSprite(x, y, vpx, vpy);
					break;
				case REALIVE:
					red_realive->renderSprite(x, y-4, vpx, vpy);
					break;
				default:
					break;
				}
			}

		}
		else if (color == GREEN)
		{
			if (left_direction)
			{
				switch (state_turtle)
				{
				case RUNNING:
					green_run_left->renderSprite(x, y, vpx, vpy);
					break;
				case DIE_:
					green_die->renderSprite(x, y, vpx, vpy);
					break;
				case HIT:
					green_hit->renderSprite(x, y, vpx, vpy);
					break;
				case REALIVE:
					green_realive->renderSprite(x, y-4, vpx, vpy);
					break;
				default:
					break;
				}
			}
			else
			{
				switch (state_turtle)
				{
				case RUNNING:
					green_run_right->renderSprite(x, y, vpx, vpy);
					break;
				case DIE_:
					green_die->renderSprite(x, y, vpx, vpy);
					break;
				case HIT:
					
					green_hit->renderSprite(x, y, vpx, vpy);
					break;
				case REALIVE:
					green_realive->renderSprite(x, y - 4, vpx, vpy);
					break;
				default:
					break;
				}
			}
		}
	}
}


