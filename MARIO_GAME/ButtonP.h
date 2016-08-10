#pragma once
#include "Sprite.h"
#include "Objects.h"
#include "Player.h"
#include "Player.h"
class ButtonP:public Objects
{
	int number_col;
	Sprite*brick;
	Sprite*buttonP;
	Sprite*down_P;
	DWORD start;

	
	bool isvisible;


public:
	void Init(LPDIRECT3DDEVICE9 d3ddv);
	void Update(Player*player, float time);
	void Draw(float vpx, float vpy);
	int getnumber_col()
	{
		return number_col;
	}
	void addnumber_col()
	{
		this->number_col++;
	}
	void setcol(int x)
	{
		this->number_col=x;
	}
	ButtonP();
	~ButtonP();
	ButtonP(float x, float y);
};
typedef vector<ButtonP*>Buttonlist;

