#pragma once
#include "Box.h"
#include "Player.h"
#include "Objects.h"
#include "ObjectsList.h"
#include "Quadtree.h"
#include "EnemyManager.h"
#include "Background.h"
#include "MarkManager.h"
#include "Coin.h"
#include "TurtleNormal.h"
#include "MushRunner.h"
#include "ButtonP.h"
#include "DownH.h"
#include "Flower.h"
class Colision
{
	Player*player;
	EnemyManager*enemy;
	MarkManager*mark;
	
	Mushroomlist mushroomlist;
	Boxlist boxlist_col_V;
	Boxlist boxlist_col_H;
	Marklist marklist;
	Coinlist coinlist;
	TurtleNormallist turtlenomallist;
	Bricklist bricklist;
	MushRunnerlist mushrunnerlist;
	Buttonlist buttonlist;
	Spectlist speclis;
	Down_H_list down_list;
	Flowerlist flowerlist;
	Butlet*butlet;		
public:
	Colision(EnemyManager*enemy,MarkManager*,Player*player);
	~Colision();
	void colwithButlet(Player*player, Butlet*butlet);
	Quadtree* createQuadTree(float  vpx, float vpy);
	void controlCollision(float vpx, float vpy);
	void checkCollison(float vpx, float vpy,Player*);
	
	
};

