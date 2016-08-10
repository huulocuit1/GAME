#pragma once
#include "Mark.h"
#include "ObjectsList.h"
#include "Player.h"
#include "Coin.h"
#include "Brick.h"
#include "World.h"
#include "MushRunner.h"
#include "ButtonP.h"

class MarkManager
{
	Marklist marklist;
	Coinlist coinlist;
	Bricklist bricklist;
	Worldlist worldlist;
	MushRunnerlist mushrunnerlist;
	Buttonlist buttonlist;
	
private: static MarkManager* instance;
	
public:
	
	void Update(LPDIRECT3DDEVICE9 d3ddv, Player*player,float time);
	void Render(float vpx, float vpy);
	Marklist getmarklist();
	Coinlist getcoinlist();
	Bricklist getbricklist();
	MushRunnerlist getmushrunnerlist();
	Buttonlist getbuttonList();
public:

	static MarkManager*getinstance();

	MarkManager();
	MarkManager(LPDIRECT3DDEVICE9 d3ddv);
	~MarkManager();
};

