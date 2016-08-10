#pragma once
#include "Player.h"
#include "Objects.h"

enum TYPE_DOWMN_H
{
	DOWN1,
	UP1,

};
class DownH:public Objects
{
	float width;
	float height;
	TYPE_DOWMN_H _type;
public:
	
	DownH();
	~DownH();
	DownH(TYPE_DOWMN_H type,float x, float, float width, float height);
	TYPE_DOWMN_H getType()
	{
		return _type;
	}
};
typedef vector<DownH*>Down_H_list;

