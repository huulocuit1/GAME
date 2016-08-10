#pragma once
#include "Turtle.h"
enum COLOR_TURTLE
{
	RED, 
	GREEN,
	RED2,
};
enum STATE_TURTLE
{
	RUNNING,
	DIE_,
	REALIVE,
	HIT,
};
class TurtleNormal :public Turtle
{
	//RED
	Sprite*red_run_right;
	Sprite*red_run_left;
	Sprite*red_die;
	Sprite*red_realive;
	//GREEN
	Sprite*green_run_right;
	Sprite*green_run_left;
	Sprite*green_die;
	Sprite*green_realive;

	Sprite*hit;
	Sprite*green_hit;
	COLOR_TURTLE color;
	STATE_TURTLE state_turtle;
	DWORD red_start;
	DWORD green_start;
	DWORD red_hoisinh;
	DWORD green_hoisinh;
	bool _hit;
	bool col_mark;
	bool col_brick;
	bool player_isleft;
	float pos_x_die;
	float _time;
	bool col;
	bool left_direction;
	bool green_col_botoom;
	bool visible;
	bool is_left;
	bool col_left;
	bool col_right;
	float before_x;
public:
	void initTurtleNormal(LPDIRECT3DDEVICE9 d3ddv);
	void updateTurtleNormal(Player*player, float time);
	void drawTurtleNormal(float vpx, float vpy);	
	void updateRedTurtleNormal(Player*player, float time);
	void updateGreenTurtleNormal(Player*player, float time);	
	TurtleNormal();
	TurtleNormal(COLOR_TURTLE Color, float x, float y, float width, float height);
	~TurtleNormal();
public:
	bool getVisible()
	{
		return visible;
	}
	STATE_TURTLE getState()
	{
		return state_turtle;
	}
	void setState(STATE_TURTLE state)
	{
		this->state_turtle = state;
	}
	bool getHit()
	{
		return _hit;
	}
	void setHit(bool hit)
	{
		this->_hit = hit;
	}
	bool getColMark()
	{
		return col_mark;
	}
	void setColMark(bool col_mark)
	{
		this->col_mark = col_mark;
	}
	void setColBrick(bool)
	{
		this->col_brick = true;
	}
	void setCol(bool)
	{
		col = true;
	}
	COLOR_TURTLE getCorlorTurtle()
	{
		return color;
	}
	void serColBotoom(bool col_bottom)
	{
		this->green_col_botoom = col_bottom;
	}
	void setVisible(bool visible)
	{
		this->visible = visible;
	}
	void setColVLeft(bool col_left)
	{
		this->col_left = col_left;
	}
	void setColVRight(bool col_right)
	{
		this->col_right = col_right;
	}

}; 
typedef vector<TurtleNormal*>TurtleNormallist;


