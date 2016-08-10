#pragma once
#include "Objects.h"
#include "Sprite.h"

class Tube:public Objects
{
	Sprite*tube;
	LPDIRECT3DDEVICE9 d3ddv;
	int x;
	int y;
public:
	Tube(LPDIRECT3DDEVICE9 d3ddv,int x, int y);
	~Tube();
public :
	void render(float vpx, float vpy);
	

	
	

};

