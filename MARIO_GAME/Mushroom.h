#pragma once
#include "Objects.h"
#include "Sprite.h"
#include "Player.h"
#include <list>
using namespace std;
enum KIND_Mush
{
	NORMAL,
	_JUMP,
	NOT_JUMP,
};
enum State
{
	ALIVE,
	_DIE,
	_STOP,
};
class Mushroom:public Objects
{
private:

	Sprite*mushroom;
	Sprite*mushroom_die;
	Sprite*mushroom_mark;
	Sprite*mushroom_jump;
	Sprite*notjump;
	
private:
	float width;
	float height;
private:
	boolean visible;
	boolean isleft;
	boolean col;
	DWORD start;
	float startx;
	float statty;
	KIND_Mush kind;
	State state;
	float _time;
	float before_x;
private:
	byte number_col;
	bool not_jump;
	bool col_v_left;
	bool col_v_right;
	bool col_bottom;
	bool col_top;
	bool left_decoration;

public:
	float getWidth()
	{
		return this->width;
	}
	float getHeight()
	{
		return this->height;
	}
	void setWidth()
	{
		this->width = 0;
	}
	void setHeight()
	{
		this->height = 0;
	}
	
	boolean getVisible()
	{
		return visible;
	}
	State getState()
	{
		return this->state;
	}
	KIND_Mush getKind()
	{
		return this->kind;
	}
	void setState( State _state)
	{
		this->state = _state;
	}
	void setKind(KIND_Mush _kind)
	{
		this->kind = _kind;
	}
	void setCol(boolean col)
	{
		this->col = col;
	}
	boolean getCol()
	{
		return col;
	}
	void setVisible(boolean s)
	{
		this->visible = s;
	}
	bool getNotJump()
	{
		return not_jump;
	}
	void setNotJump(bool)
	{
		not_jump = true;
	}
	void setNumCol()
	{
		number_col = 2;
	}
	void setColVLeft(bool col_v)
	{
		this->col_v_left = col_v;
	}
	void setColVRight(bool col_v)
	{
		this->col_v_right = col_v;
	}
	void setBottom(bool col_bottom)
	{
		this->col_bottom = col_bottom;
	}
	void setColTop(bool col_top)
	{
		this->col_top = col_top;
	}

public :
	void initMushroom(LPDIRECT3DDEVICE9 d3ddv);
	void updateMushroom(Player*,float time);
	void drawMushroom(float vpx, float vpy);
	void killMushroom();
	Mushroom(KIND_Mush ,float x, float y, float width, float height);
	Mushroom();
	~Mushroom();
};
typedef std::vector<Mushroom*> Mushroomlist;

