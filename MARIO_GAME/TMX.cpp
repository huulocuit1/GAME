#include "TMX.h"



TMX::TMX()
{
}


TMX::~TMX()
{
}
TMX* TMX::instance = NULL;
TMX* TMX::getInstance()
{
	if (instance == NULL)
	{
		instance = new TMX;
	}
	return instance;
}

#pragma region GetListObject
Mushroomlist TMX::getListMushRoom()
{
	return mushroomlist;
}
Bricklist TMX::getListBrick()
{
	return bricklist;
}
Marklist TMX ::getListMark()
{
	return martlist;
}
Coinlist TMX::getListCoin()
{
	return coinlist;
}
Boxlist TMX::getListBox_ColH()
{
	return boxlist_col_H;
}
Boxlist TMX::getListBox_ColV()
{
	return boxlist_col_V;
}
Flowerlist TMX::getListFlower()
{
	return flowerlist;
}
TurtleNormallist TMX::getListTurtleNormal()
{
	return turtlelist;
}
Worldlist TMX::getListWorld()
{
	return worldist;
}
MushRunnerlist TMX::getListRunner()
{
	return mushrunnerlist;
}
Buttonlist TMX::getListBotton()
{
	return buttonplist;
}
Spectlist TMX::getListSpec()
{
	return listspec;
}
Down_H_list TMX::getListDown_H()
{
	return downlist;
}

#pragma endregion
#pragma region ReadObjects

void TMX::readAllObjects(LPWSTR filename,Mushroomlist&listmushroom, Bricklist&bricklist, Marklist&martlist, Coinlist&coinlist, Boxlist& boxlist_col_V, Boxlist&boxlist_col_H, Flowerlist&flowerlist, TurtleNormallist&turtlelist, Worldlist&worldist, MushRunnerlist&mushrunnerlist, Buttonlist&buttonplist, Spectlist&listspec, Down_H_list&downlist)
{

	 
	this->mushroomlist = listmushroom;
	this->bricklist = bricklist;
	this->martlist = martlist;
	this->coinlist = coinlist;
	this->boxlist_col_H = boxlist_col_H;
	this->boxlist_col_V = boxlist_col_V;
	this->flowerlist = flowerlist;
	this->turtlelist = turtlelist;
	this->worldist = worldist;
	this->mushrunnerlist = mushrunnerlist;
	this->buttonplist = buttonplist;
	this->listspec = listspec;
	this->downlist = downlist;
}

#pragma endregion
