#include "SpecRect.h"



SpecRect::SpecRect(float x,float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	box = Box(x, y, width, height);
	type = _SPEC;
}


SpecRect::~SpecRect()
{
}
void SpecRect::updateSpectRect(Player*player)
{
	if (player->getButtonP() == true)
	{
		box = Box(0, 0, 0, 0);
	}
	else
	{
		box = Box(x, y, width, height);
	}
}
