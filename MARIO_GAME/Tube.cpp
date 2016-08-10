#include "Tube.h"

Tube::Tube( LPDIRECT3DDEVICE9 d3ddv,int x, int y)
{
	this->tube = new Sprite(d3ddv, L"\Images\\Tube\\tube.png",32,48,1,1);
	this->x = x;
	this->y = y;
	box = Box(x-16, y-24, 32, 48);
}


Tube::~Tube()
{
}
void Tube::render(float vpx, float vpy)
{
	tube->Render(this->x, this->y, vpx, vpy);
}