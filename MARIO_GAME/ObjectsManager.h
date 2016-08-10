#pragma once





#include "Player.h"
#include "Colision.h"
#include "ObjectsList.h"
#include "EnemyManager.h"
#include "MarkManager.h"

extern int currentstate;
extern int playerlife;
extern int score;

class ObjectsManager
{
private :
	ObjectsManager();
	static ObjectsManager*instance;
	//Mark
	DWORD start;
	//Mushroom
	
	Colision*colision;
	EnemyManager*enemymananger;
	MarkManager*markmanager;
	Sprite*tube;
	Sprite*tube2;
	

public:
	void initObjectsManager(LPDIRECT3DDEVICE9 d3ddv,Player*);
	void updateObjectsManager(LPDIRECT3DDEVICE9 d3ddv, Player *player,float time);
	void drawObjectsManager(float vpx, float vpy);
	static ObjectsManager*getInstance()
	{
		if (instance == NULL)
		{
			instance = new ObjectsManager();
		}
		return instance;
	}
	void colPlayer(Player*player);
	~ObjectsManager();
	void colPlayer(float vpx, float vpy,Player*player);
	};

