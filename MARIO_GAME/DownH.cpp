#include "DownH.h"



DownH::DownH()
{
}


DownH::~DownH()
{
}
DownH::DownH(TYPE_DOWMN_H _type,float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	box = Box(x, y, width, height);
	type = DOWN_H;
	this->_type = _type;
}
