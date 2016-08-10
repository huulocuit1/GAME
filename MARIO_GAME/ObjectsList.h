#pragma once
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
#include "SpecRect.h"
#include "DownH.h"
class ObjectsList
{
private : 
	static ObjectsList*instance;
	
	char*filemap1;
	char*filemap2;
public:	
	static ObjectsList*getIntance();
	void readMushRoom(char* file_xml,Mushroomlist&listmushroom);
	void readListMark(char* file_xml,Marklist&martlist);
	void readListCoin(char* file_xml,Coinlist&coinlist);
	void readMap(char* file_xml,Boxlist& boxlist_col_V,Boxlist&boxlist_col_H);
	void readlistFlower(char* file_xml,Flowerlist&flowerlist);
	void readlistTurtle(char* file_xml,TurtleNormallist&turtlelist);
	void readlistBrick(char* file_xml,Bricklist&brciklist);
	void readListWorld(char* file_xml,Worldlist&worldist);
	void readMushrunnerList(char* file_xml,MushRunnerlist&mushrunnerlist);
	void readButtonPList(char* file_xml,Buttonlist&buttonplist);
	void readSpecList(char* file_xml,Spectlist&listspec);
	void readDownHList(char* file_xml,Down_H_list&downlist);
	ObjectsList();
	~ObjectsList();
};

