#pragma once
#include "crtdbg.h"
#include "Box.h"
#include "Utils.h"
#include <list>
#include "Xml libs\tinystr.h"
#include "Xml libs\tinyxml.h"
#include "Mark.h"
#include "Mushroom.h"
#include "Coin.h"
#include "Flower.h"
#include "TurtleNormal.h"
#include <string>
#include <xstring>
#include "Brick.h"
#include "World.h"
#include "MushRunner.h"
#include "ButtonP.h"
#include "SPEC.h"
#include "Down_H.h"
class TMX
{
private:
	static TMX*instance;


	Mushroomlist mushroomlist;
	Flowerlist flowerlist;
	TurtleNormallist turtlelist;


	Bricklist bricklist;
	Marklist martlist;
	Coinlist coinlist;
	Boxlist  boxlist_col_V;
	Boxlist boxlist_col_H;
	Worldlist worldist;
	MushRunnerlist mushrunnerlist;
	Buttonlist buttonplist;
	Spectlist listspec;
	Down_H_list downlist;
public:
	TMX();
	~TMX();
	
public:
	static TMX* getInstance();
public:
	Mushroomlist getListMushRoom();
	Bricklist getListBrick();
	Marklist getListMark();
	Coinlist getListCoin();
	Boxlist getListBox_ColH();
	Boxlist getListBox_ColV();
	Flowerlist getListFlower();
	TurtleNormallist getListTurtleNormal();
	Worldlist getListWorld();
	MushRunnerlist getListRunner();
	Buttonlist getListBotton();
	Spectlist getListSpec();
	Down_H_list getListDown_H();
public:
	void readAllObjects(LPWSTR filename,Mushroomlist&listmushroom, Bricklist&bricklist, Marklist&martlist, Coinlist&coinlist, Boxlist& boxlist_col_V, Boxlist&boxlist_col_H, Flowerlist&flowerlist, TurtleNormallist&turtlelist, Worldlist&worldist, MushRunnerlist&mushrunnerlist, Buttonlist&buttonplist, Spectlist&listspec, Down_H_list&downlist);






	

};

