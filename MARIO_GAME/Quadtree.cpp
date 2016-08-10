#include "Quadtree.h"



Quadtree::Quadtree()
{
}


Quadtree::Quadtree(int pLevel, Box* region)
{
	level = pLevel;
	this->region = region;
	objList = new _ObjectList();
	nodes = NULL;
}


Quadtree::~Quadtree()
{}

void Quadtree::clear()
{
	//Clear all nodes
	if (nodes)
	{
		for (int i = 0; i < 4; i++)
		{
			nodes[i]->clear();
			delete nodes[i];
		}
		delete[] nodes;
	}

	//Clear current quadtree
	objList->clear();

	delete objList;
	delete region;
}

bool Quadtree::isContain(Objects* object)
{
	Box bound = object->box;

	return !(bound.x + bound.width < region->x ||
		bound.y + bound.height < region->y ||
		bound.x > region->x + region->width ||
		bound.y> region->y + region->height);
}

void Quadtree::split()
{
	int subWidth = (int)(region->width / 2);
	int subHeight = (int)(region->height / 2);
	int x = (int)region->x;
	int y = (int)region->y;

	nodes = new Quadtree*[4];
	nodes[0] = new Quadtree(level + 1, new Box(x, y, subWidth, subHeight));
	nodes[1] = new Quadtree(level + 1, new Box(x + subWidth, y, subWidth, subHeight));
	nodes[2] = new Quadtree(level + 1, new Box(x, y + subHeight, subWidth, subHeight));
	nodes[3] = new Quadtree(level + 1, new Box(x + subWidth, y + subHeight, subWidth, subHeight));
}

void Quadtree::insert(Objects* obj)
{
	//Insert entity into corresponding nodes
	if (nodes)
	{
		if (nodes[0]->isContain(obj))
			nodes[0]->insert(obj);
		if (nodes[1]->isContain(obj))
			nodes[1]->insert(obj);
		if (nodes[2]->isContain(obj))
			nodes[2]->insert(obj);
		if (nodes[3]->isContain(obj))
			nodes[3]->insert(obj);
	}

	//Insert entity into current quadtree
	if (this->isContain(obj))
		objList->push_back(obj);

	//Split and move all objects in list into it’s corresponding nodes
	if (objList->size() > MAX_OBJECT && level < MAX_LEVEL)
	{
		split();

		while (!objList->empty())
		{
			if (nodes[0]->isContain(objList->back()))
				nodes[0]->insert(objList->back());
			if (nodes[1]->isContain(objList->back()))
				nodes[1]->insert(objList->back());
			if (nodes[2]->isContain(objList->back()))
				nodes[2]->insert(objList->back());
			if (nodes[3]->isContain(objList->back()))
				nodes[3]->insert(objList->back());

			objList->pop_back();
		}
	}
}

void Quadtree::insertV(Box*box)
{
	Objects* g = new Objects();
	g->box = *box;
	g->setType(NONEV);
	insert(g);
}
void Quadtree::insertH(Box* box)
{
	Objects* g = new Objects();
	g->box = *box;
	g->setType(NONEH);
	insert(g);
}

_ObjectList* Quadtree::retrieve(_ObjectList* returnObjects, Objects* object)
{
	if (nodes != NULL)
	{
		if (nodes[0]->isContain(object))
			nodes[0]->retrieve(returnObjects, object);
		if (nodes[1]->isContain(object))
			nodes[1]->retrieve(returnObjects, object);
		if (nodes[2]->isContain(object))
			nodes[2]->retrieve(returnObjects, object);
		if (nodes[3]->isContain(object))
			nodes[3]->retrieve(returnObjects, object);
	}
	//Add all entities in current region into returnObjects
	if (this->isContain(object))
	{
		for (auto i = objList->begin(); i != objList->end(); i++)
		{
			//if (object != i._Ptr->_Myval)
			returnObjects->push_back(i._Ptr->_Myval);
		}
	}
	return returnObjects;
}

_ObjectList* Quadtree::retrieve(_ObjectList* returnObject, Box* CollisionRec)
{
	Objects* g = new Objects();
	g->box = *CollisionRec;
	return retrieve(returnObject, g);
}