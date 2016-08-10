#pragma once
#include "Objects.h"
#include "Player.h"
#include "Sprite.h"

class MushRunner:public Objects
{
	Sprite*mushrunner;
	Sprite*leaf;
	bool iscol;
	bool isvisible;
	float width;
	float height;
	bool ismush;
	float _time;
	float starty;
	float startx;
	float number_col_ismush;
	float number_col_isleaf;
public:
	void initMushRunner(LPDIRECT3DDEVICE9 d3ddv);
	void updateMushRunner(Player*player, float time);
	void drawMushRunner(float vpx, float vpy);
public:
	void setCol(bool col)
	{
		this->iscol = col;
	}
	void increaseNumberColIsLeaf()
	{
		number_col_isleaf = 1;
	}
	void setNumberColLeaf()
	{
		number_col_isleaf = 2;
	}
	bool getIsMush()
	{
		return ismush;
	}
	void setIsMush(bool ismush)
	{
		this->ismush = ismush;
	}
	float getNumberColIsMush()
	{
		return number_col_ismush;
	}
	float getNumberColIsLeaf()
	{
		return number_col_isleaf;
	}
	void setNumberColIsMush( float x)
	{
		number_col_ismush = x;
	}
	bool getIsVisible()

	{
		return isvisible;
	}
	void setIsVisible(bool isvisible)
	{
		this->isvisible = isvisible;
	}


	MushRunner();
	MushRunner(float x, float y, float width, float height);
	~MushRunner();
};
typedef vector<MushRunner*>MushRunnerlist;

