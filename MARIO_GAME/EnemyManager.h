#pragma once
#include "Objects.h"
#include "Flower.h"
#include "Mushroom.h"
#include "Butlet.h"
#include "ObjectsList.h"
#include "TurtleNormal.h"

class EnemyManager
{
	Mushroomlist mushroomlist;

	Butlet*butlet;
	Flowerlist flowerlist;
	TurtleNormallist turtle_normal_list;

public:
	
	void updateEnemyManager(Player*,float time);
	void renderEnemyManager(float vpx, float vpy);
	Mushroomlist getMushList()
	{
		return mushroomlist;
	}
	TurtleNormallist 
		getTurtleNormalList()
	{
		return turtle_normal_list;
	}
	Flowerlist getFlowerList()
	{
		return flowerlist;
	}
	Butlet*getButlet()
	{
		return butlet;
	}

	EnemyManager(LPDIRECT3DDEVICE9 d3ddv);
	~EnemyManager();
};

