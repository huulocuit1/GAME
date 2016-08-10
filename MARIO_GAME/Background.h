#pragma once


#include "Utils.h"
#include "Config.h"
#include "RSManager.h"
#include <fstream>
#include <iostream>
#include "Sprite.h"
#include "Box.h"
#include "SpecRect.h"
#include<string>
#include "ObjectsList.h"
#include "Player.h"
#include "DownH.h"
using namespace std;
extern int currentstate;
extern int playerlife;
extern int score;
class Background
{
protected:
	Sprite*background;
	Sprite*test;
	Boxlist boxlist_col_V, boxlist_col_H;
	Spectlist listspec;
	Down_H_list down_list;
	int **arrnode;
	int **map_rect;
	int n;
	int _width;
	int _height;
	LPDIRECT3DDEVICE9 d3ddv;
private :
	static Background*instance;

public:
	int** loadBackground(LPWSTR filemap);
	void renderBackground( float vpx, float vpy);
	void updateBackground(Player*player);	
	void initBackground(LPDIRECT3DDEVICE9 d3ddv, LPWSTR filemap,LPWSTR filename,char*map_xml);
	Background(LPDIRECT3DDEVICE9 d3ddv, LPWSTR filemap, LPWSTR filename);
	Background();
	~Background();	
public :
	Boxlist getBoxListColV();
	Boxlist getBoxListColH();
	Spectlist getSpectList();
	Down_H_list getDownList();
public :
	static
	Background*getInstane();

};

