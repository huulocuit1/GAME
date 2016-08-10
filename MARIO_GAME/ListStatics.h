#pragma once
#ifndef LIST_STATIC_H_
#define LIST_STATIC_H_

#include "Box.h"
#include "Utils.h"
#include <list>
#include <string>
#include "Xml libs\tinystr.h"
#include "Xml libs\tinyxml.h"
#include "Mark.h"
using namespace std;
class ListStatics
{
	list<Box>listRoad;
	Box Road2;
	Box Road2_y;
	list<Box>listRect;
	list<Box>listTube;
	list<Box>listTube_x;
	list<Box>listMarkBrick;

public:
	void readStaticObjects();
	list<Mark> readlistMark();
	
	
	

	list<Box> getlistRoads();
	list<Box>getlistRects();
	list<Box>getlistTubes();
	list<Box>getlistTube_xs();
	
	
	
	Box getRoad2()
	{
		return Road2;
	}
	Box getRoad2_y()
	{
		return Road2_y;
	}

	ListStatics();
	~ListStatics();
};
#endif
