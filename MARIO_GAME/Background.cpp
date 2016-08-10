#include "Background.h"



Background::Background()
{
	d3ddv = NULL;
}


Background::~Background()
{
	delete(d3ddv);
}
Background::Background(LPDIRECT3DDEVICE9 d3ddv, LPWSTR filemap, LPWSTR filename)
{
	arrnode = loadBackground(filemap);
	this->background = new Sprite(d3ddv, filename, 16, 16, 117, 39);
	ObjectsList::getIntance()->readMap(MAP1_XML,boxlist_col_V,boxlist_col_H);
	
	

}
void Background::initBackground(LPDIRECT3DDEVICE9 d3ddv, LPWSTR filemap,LPWSTR filename,char*map_xml)
{
	arrnode = loadBackground(filemap);
	if (currentstate == 1)
	{
		this->background = new Sprite(d3ddv, filename, 16, 16, 117, 39);
		ObjectsList::getIntance()->readDownHList(map_xml, down_list);
	}
	else if (currentstate == 2)
	{
		boxlist_col_V.clear();
		boxlist_col_H.clear();
		this->background = new Sprite(d3ddv, filename, 16, 16, 72, 24);

		
	}
	ObjectsList::getIntance()->readMap(map_xml, boxlist_col_V, boxlist_col_H);

	
	
	
	
}
int**Background::loadBackground(LPWSTR filename)
{
	string temp;
	int **_map;
	fstream _mapStream;
	_mapStream.open(filename, ios::in);
	if (!_mapStream.bad())
	{
		_mapStream >> _width;
		_mapStream >> _height;
		this->n = _height;
		_map = new int*[_height];
		for (int i = 0; i < _height; i++)
		{
			_map[i] = new int[_width];
		}
		for (int j = 0; j < _height; j++)
		{
			for (int i = 0; i < _width; i++)
			{

				_mapStream >> _map[j][i];


			}

		}
		return _map;
	}
	return NULL;
}
void Background::renderBackground( float vpx, float vpy)
{
	for (int i = 0;i < _height;i++)
	{
		for (int j = 0;j < _width;j++)
		{

			float posx = j*16.0f;
			float posy = (_height - i)*16.0f-8;
			if ((posx < vpx +BUFFER_WIDTH+NOMAL_SIZE/2) && (posx >= vpx - 32))
			{
				background->setIndex(arrnode[i][j] - 1);
				background->renderSprite(posx, posy, vpx, vpy);
			}

		}
	}
}
void Background::updateBackground(Player*player)
{
	
}
Background* Background::instance = NULL;

Boxlist Background::getBoxListColV()
{
	return boxlist_col_V;
}
Boxlist Background::getBoxListColH()
{
	return this->boxlist_col_H;
}
Spectlist  Background::getSpectList()
{
	return listspec;
}
Down_H_list Background::getDownList()
{
	return down_list;
}
Background* Background::getInstane()
{
	if (instance == NULL)
	{
		instance = new Background();
	}
	return instance;
}