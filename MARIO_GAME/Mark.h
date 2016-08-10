#pragma once
#include "Objects.h"
#include "Sprite.h"
#include "Player.h"
enum TYPE_COIN
{
	_COIN,MUSH,_LEAF,
};
class Mark:public Objects
{
private :
	//Mark
	float x;
	float y;
	float width;
	float height;
	float vy;

	//Coin
	float _xcoin;
	float _ycoin;
	float _vycoin;
	

	Sprite*mark;
	Sprite*notmark;
	Sprite*coin;

	boolean col;
	int hit;
	float starty;
	float startx;
	DWORD start;
	
	boolean visible;
	boolean isleft;
	TYPE_COIN type_coin;
	
	Sprite*Star;
	bool star;
	Sprite*star_coin;
	
	
public:
	void initMark(LPDIRECT3DDEVICE9 d3ddv);
	void updateMark(LPDIRECT3DDEVICE9 d3ddv, Player*player);
	void drawMark(float vpx, float vpy);
	void setColision(boolean col)
	{
		this->col = col;
	}
	boolean getCol()
	{
		return this->col;
	}
	void setHit()
	{
		this->hit = 1;
	}
	int getHit()
	{
		return hit;
	}
	boolean getVisible()
	{
		return visible;
	}
	Mark();
	~Mark();
	float getWidth()
	{
		return width;
	}
	float getHeight()
	{
		return this->height;
	}
	TYPE_COIN getTypeCoin()
	{
		return type_coin;
	}
	void setTypeCoin(TYPE_COIN type_coin)
	{
		this->type_coin = type_coin;
	}
	float getX()
	{
		return x;
	}
	float getY()
	{
		return y;
	}
	void setStar(bool star)
	{
		this->star = star;
	}
	bool getStar()
	{
		return this->star;
	}
	Mark(TYPE_COIN,float x, float y, float width, float height);
	
};
typedef std::vector<Mark*>Marklist;

