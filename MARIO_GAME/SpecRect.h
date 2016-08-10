#pragma once
#include "Player.h"
#include "Objects.h"
class SpecRect:public Objects
{
private :
	float width;
	float height;
public:
	
	SpecRect(float x,float y, float width, float height);
 void updateSpectRect(Player*player);
	~SpecRect();
};
typedef vector<SpecRect*>Spectlist;

