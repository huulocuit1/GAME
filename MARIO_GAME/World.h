#pragma once
#include "Sprite.h"
#include "Player.h"
enum type_khung
{
	X, Y, Z, WORLD,
};
class World
{
	float x;
	float y;
	float width;
	float height;
	type_khung khung;
	float starty;
public:

	Sprite*background;
	void initWorld(LPDIRECT3DDEVICE9 d3ddv);
	void updateWorld(LPDIRECT3DDEVICE9 d3ddv, Player*, float time);
	void drawWorld(float vpx, float vpy);
	World();
	~World();
	World(float x, float y,float width, float height);

};
typedef vector<World*> Worldlist;

