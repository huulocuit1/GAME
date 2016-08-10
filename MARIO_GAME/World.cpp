#include "World.h"



World::World()
{
}


World::~World()
{
}
World::World( float x, float y, float width, float height)
{
	
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	starty = y;
		
}
void World::initWorld(LPDIRECT3DDEVICE9 d3ddv)
{
	this->background = new Sprite(d3ddv, L"Images\\Map\\Background\\World\\Background11.png", 272, 32, 1, 1);

}
void World::updateWorld(LPDIRECT3DDEVICE9 d3ddv, Player*player, float time)
{
	
	
	
}
void World::drawWorld(float vpx, float vpy)
{
	background->renderSprite(x, y,0,432);
}
