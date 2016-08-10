#pragma once
#include "Mushroom.h"
#include <list>
#include <string>
#include "Xml libs\tinystr.h"
#include "Xml libs\tinyxml.h"

using namespace std;
class ListDynamics
{
	list<Mushroom> listmushroom;
public:
	ListDynamics();
	~ListDynamics();
	list<Mushroom> readMushroom();
};

