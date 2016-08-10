#pragma once
#include "Objects.h"
#include <list>
#include "Box.h"

#define MAX_OBJECT 40
#define MAX_LEVEL 4

// 0  |  1
// -------
// 2  |  3
typedef std::list<Objects*> _ObjectList;

class Quadtree
{
private:
	int level;
	_ObjectList* objList;
	Box* region;
	Quadtree** nodes;

	bool isContain(Objects* object);
	void split();
public:
	Quadtree();
	Quadtree(int pLevel, Box* region);
	~Quadtree();

	void clear();
	void insert(Objects* obj);
	void insertV(Box* box);
	void insertH(Box*box);
	_ObjectList* retrieve(_ObjectList* returnObject, Objects* object);
	_ObjectList* retrieve(_ObjectList* returnObject, Box* CollisionRec);
};

