#include "ObjectsList.h"



ObjectsList::ObjectsList()
{
}


ObjectsList::~ObjectsList()
{
}
void ObjectsList::readMap(char*file_xml,Boxlist& boxlist_col_V,Boxlist&boxlist_col_H)
{
	TiXmlDocument doc;
	if (!doc.LoadFile(file_xml))
	{
		return;
	}
	TiXmlElement*root = doc.FirstChildElement();

	if (root == NULL)
	{

		doc.Clear();
		return;
	}
	for (TiXmlElement*elem = root->FirstChildElement();elem != NULL;elem = elem->NextSiblingElement())
	{
		string elemName = elem->Value();
		if (elemName == "objectgroup")
		{
			string atribute;
			atribute = elem->Attribute("name");
			if (atribute.compare("COL_V") == 0 || atribute.compare("BRICK") == 0 )
			{
				for (TiXmlElement* e = elem->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
				{
					double _width = atof(e->Attribute("width"));
					double width = _width;
					double _height = atof(e->Attribute("height"));


					double x = atof(e->Attribute("x"))-8;
					double y = 672.0f - atof(e->Attribute("y"))-_height/2-1;
					Box box(x, y, width, _height);
					boxlist_col_V.push_back(box);
				}
			}
			else if (atribute.compare("COL_H")==0||atribute.compare("ROAD") == 0 || atribute.compare("TUBE") == 0)
			{
				for (TiXmlElement* e = elem->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
				{
					double _width = atof(e->Attribute("width"));
					double width = _width;
					double _height = atof(e->Attribute("height"));

					double x = atof(e->Attribute("x"))-8;
					double y = 672.0f - atof(e->Attribute("y"))-_height - 1;
					Box box(x, y, width, _height);
					boxlist_col_H.push_back(box);
				}
			}
		}
	}

}

void ObjectsList::readMushRoom(char*file_xml,Mushroomlist&listmushroom)
{

	TiXmlDocument doc;
	doc.LoadFile(file_xml);
	TiXmlElement*root = doc.FirstChildElement();


	for (TiXmlElement*elem = root->FirstChildElement();elem != NULL;elem = elem->NextSiblingElement())
	{
		string elemName = elem->Value();
		if (elemName == "objectgroup")
		{
			string atribute;
			atribute = elem->Attribute("name");
			if (atribute == "MUSHROOM")
			{
				KIND_Mush kind_mush;
				for (TiXmlElement* e = elem->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
				{
					
					string name = e->Attribute("name");
					if (name.compare("Normal") == 0)
					{
						kind_mush = NORMAL;
					}
					else if (name.compare("Flight") == 0)
					{
						kind_mush = _JUMP;
					}
					double _width = atof(e->Attribute("width"));
					double width = _width;
					double _height = atof(e->Attribute("height"));
					double height = _height;
					double x = atof(e->Attribute("x")) - NOMAL_SIZE / 2;
					double y = 672.0f - atof(e->Attribute("y")) - NOMAL_SIZE / 2;
					Mushroom* mush = new Mushroom(kind_mush,x, y, width, height);
					listmushroom.push_back(mush);
				}
			}
		}
	}



}
ObjectsList* ObjectsList::instance = NULL;
void ObjectsList::readListMark(char*file_xml,Marklist&martlist)
{
	TiXmlDocument doc;
	if (!doc.LoadFile(file_xml))
	{
		return;
	}
	TiXmlElement*root = doc.FirstChildElement();

	if (root == NULL)
	{

		doc.Clear();
		return;
	}
	for (TiXmlElement*elem = root->FirstChildElement();elem != NULL;elem = elem->NextSiblingElement())
	{
		string elemName = elem->Value();
		if (elemName == "objectgroup")
		{
			string atribute;
			atribute = elem->Attribute("name");
			if (atribute.compare("MARK") == 0)
			{
				TYPE_COIN type_coin;
				for (TiXmlElement* e = elem->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
				{
					string name = e->Attribute("name");
					if (name.compare("MUSH") == 0)
					{
						type_coin = MUSH;
					}
					else if(name.compare("LEAF")==0)
					{
						type_coin = _LEAF;
					}
					else
					{
						type_coin = _COIN;
					}
					
					double _width = atof(e->Attribute("width"));
					double width = _width;
					double _height = atof(e->Attribute("height"));
					double height = _height;
					double x = atof(e->Attribute("x"));
					double y = 672.0f - atof(e->Attribute("y"))-height/2;
					Mark*mark = new Mark(type_coin,x, y, width, height);
					
					martlist.push_back(mark);
				}
			}

		}
	}

}
void ObjectsList::readListCoin(char*file_xml,Coinlist&coinlist)
{
	TiXmlDocument doc;
	if (!doc.LoadFile(file_xml))
	{
		return;
	}
	TiXmlElement*root = doc.FirstChildElement();

	if (root == NULL)
	{

		doc.Clear();
		return;
	}
	for (TiXmlElement*elem = root->FirstChildElement();elem != NULL;elem = elem->NextSiblingElement())
	{
		string elemName = elem->Value();
		if (elemName == "objectgroup")
		{
			string atribute;
			atribute = elem->Attribute("name");
			if (atribute.compare("COIN") == 0)
			{
				for (TiXmlElement* e = elem->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
				{
					double _width = atof(e->Attribute("width"));
					double width = _width;
					double _height = atof(e->Attribute("height"));
					double height = _height;
					double x = atof(e->Attribute("x"));
					double y = 672.0f - atof(e->Attribute("y")) - NOMAL_SIZE / 2;
					Coin*coin = new Coin(x, y, width, height);
					coinlist.push_back(coin);
				}
			}
		}
	}
}
void ObjectsList::readlistFlower(char*file_xml,Flowerlist&flowerlist)
{

	TiXmlDocument doc;
	if (!doc.LoadFile(file_xml))
	{
		return;
	}
	TiXmlElement*root = doc.FirstChildElement();

	if (root == NULL)
	{

		doc.Clear();
		return;
	}
	for (TiXmlElement*elem = root->FirstChildElement();elem != NULL;elem = elem->NextSiblingElement())
	{
		string elemName = elem->Value();
		if (elemName == "objectgroup")
		{
			string atribute;
			atribute = elem->Attribute("name");
			if (atribute.compare("FLOWER") == 0)
			{
				for (TiXmlElement* e = elem->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
				{
					double _width = atof(e->Attribute("width"));
					double width = _width;
					double _height = atof(e->Attribute("height"));
					double height = _height;
					double x = atof(e->Attribute("x"));
					double y = 672.0f - atof(e->Attribute("y")) - NOMAL_SIZE / 2;
					Flower*flower = new Flower(x, y, width, height);
					flowerlist.push_back(flower);
				}
			}
		}
	}

}
void ObjectsList::readlistTurtle(char*file_xml,TurtleNormallist&turtlelist)
{
	TiXmlDocument doc;
	if (!doc.LoadFile(file_xml))
	{
		return;
	}
	TiXmlElement*root = doc.FirstChildElement();

	if (root == NULL)
	{

		doc.Clear();
		return;
	}
	for (TiXmlElement*elem = root->FirstChildElement();elem != NULL;elem = elem->NextSiblingElement())
	{
		string elemName = elem->Value();
		if (elemName == "objectgroup")
		{
			string atribute;
			atribute = elem->Attribute("name");
			if (atribute.compare("TURTLE") == 0)
			{
				COLOR_TURTLE color;
				for (TiXmlElement* e = elem->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
				{
					string name = e->Attribute("name");
					if (name.compare("RED") == 0)
					{
						color = RED;
					}
					else if (name.compare("RED2") == 0)
					{
						color = RED2;
					}
					else
					{
						color = GREEN;
					}
					double _width = atof(e->Attribute("width"));
					double width = _width;
					double _height = atof(e->Attribute("height"));
					double height = _height;
					double x = atof(e->Attribute("x"));
					double y = 672.0f - atof(e->Attribute("y"));
					TurtleNormal*turtle = new TurtleNormal(color, x, y, width, height);
					turtlelist.push_back(turtle);
				}
			}
		}
	}
}
void ObjectsList::readlistBrick(char*file_xml,Bricklist&bricklist)
{
	TiXmlDocument doc;
	if (!doc.LoadFile(file_xml))
	{
		return;
	}
	TiXmlElement*root = doc.FirstChildElement();

	if (root == NULL)
	{

		doc.Clear();
		return;
	}
	for (TiXmlElement*elem = root->FirstChildElement();elem != NULL;elem = elem->NextSiblingElement())
	{
		string elemName = elem->Value();
		if (elemName == "objectgroup")
		{
			string atribute;
			atribute = elem->Attribute("name");
			if (atribute.compare("BRICK2") == 0)
			{
				for (TiXmlElement* e = elem->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
				{
					double _width = atof(e->Attribute("width"));
					double width = _width;
					double _height = atof(e->Attribute("height"));
					double height = _height;
					double x = atof(e->Attribute("x"));
					double y = 672.0f - atof(e->Attribute("y")) - 8;
					Brick*brick = new Brick(x, y, _width, _height);
					bricklist.push_back(brick);

				}
			}
		}
	}
}
void ObjectsList::readListWorld(char*file_xml,Worldlist&worldist)
{
	TiXmlDocument doc;
	if (!doc.LoadFile(file_xml))
	{
		return;
	}
	TiXmlElement*root = doc.FirstChildElement();

	if (root == NULL)
	{

		doc.Clear();
		return;
	}
	for (TiXmlElement*elem = root->FirstChildElement();elem != NULL;elem = elem->NextSiblingElement())
	{
		string elemName = elem->Value();
		if (elemName == "objectgroup")
		{
			string atribute;
			atribute = elem->Attribute("name");
			if (atribute.compare("WORLD") == 0)
			{
				
				for (TiXmlElement* e = elem->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
				{
					
					double _width = atof(e->Attribute("width"));
					double width = _width;
					double _height = atof(e->Attribute("height"));
					double height = _height;
					double x = atof(e->Attribute("x"))+width/2;
					double y = 672.0f - atof(e->Attribute("y"))-NOMAL_SIZE;
					World*world = new World(x, y, width, height);
					worldist.push_back(world);


				}
			}
		}
	}

}
void ObjectsList::readMushrunnerList(char*file_xml,MushRunnerlist&mushrunnerlist)
{
	TiXmlDocument doc;
	if (!doc.LoadFile(file_xml))
	{
		return;
	}
	TiXmlElement*root = doc.FirstChildElement();

	if (root == NULL)
	{

		doc.Clear();
		return;
	}
	for (TiXmlElement*elem = root->FirstChildElement();elem != NULL;elem = elem->NextSiblingElement())
	{
		string elemName = elem->Value();
		if (elemName == "objectgroup")
		{
			string atribute;
			atribute = elem->Attribute("name");
			if (atribute.compare("MUSHRUNNER") == 0)
			{
				
				for (TiXmlElement* e = elem->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
				{
					double _width = atof(e->Attribute("width"));
					double width = _width;
					double _height = atof(e->Attribute("height"));
					double height = _height;
					double x = atof(e->Attribute("x"));
					double y = 672.0f - atof(e->Attribute("y"))-10;
					MushRunner*mushruner = new MushRunner(x, y, width, height);
					mushrunnerlist.push_back(mushruner);
				}
			}
		}
	}
}
void ObjectsList::readButtonPList(char*file_xml,Buttonlist&buttonplist)
{
	TiXmlDocument doc;
	if (!doc.LoadFile(file_xml))
	{
		return;
	}
	TiXmlElement*root = doc.FirstChildElement();

	if (root == NULL)
	{

		doc.Clear();
		return;
	}
	for (TiXmlElement*elem = root->FirstChildElement();elem != NULL;elem = elem->NextSiblingElement())
	{
		string elemName = elem->Value();
		if (elemName == "objectgroup")
		{
			string atribute;
			atribute = elem->Attribute("name");
			if (atribute.compare("P") == 0)
			{
				for (TiXmlElement* e = elem->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
				{
					double x = atof(e->Attribute("x"));
					double y = 672.0f - atof(e->Attribute("y"))-8;
					ButtonP* button = new ButtonP(x, y);
					buttonplist.push_back(button);
				}
			}
		}
	}
}
void ObjectsList::readSpecList(char*file_xml,Spectlist&listspec)
{
	TiXmlDocument doc;
	if (!doc.LoadFile(file_xml))
	{
		return;
	}
	TiXmlElement*root = doc.FirstChildElement();

	if (root == NULL)
	{

		doc.Clear();
		return;
	}
	for (TiXmlElement*elem = root->FirstChildElement();elem != NULL;elem = elem->NextSiblingElement())
	{
		string elemName = elem->Value();
		if (elemName == "objectgroup")
		{
			string atribute;
			atribute = elem->Attribute("name");
			if (atribute.compare("SPEC") == 0)
			{
				for (TiXmlElement* e = elem->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
				{
					
					double _width = atof(e->Attribute("width"));
					double width = _width;
					double _height = atof(e->Attribute("height"));
					double height = _height;
					double x = atof(e->Attribute("x"))-8;
					double y = 672.0f - atof(e->Attribute("y"))-_height-1;
					SpecRect* spec = new SpecRect(x, y,_width,_height);
					listspec.push_back(spec);
				}
			}
		}
	}
}
void ObjectsList::readDownHList(char*file_xml,Down_H_list&downlist)
{
	TiXmlDocument doc;
	if (!doc.LoadFile(file_xml))
	{
		return;
	}
	TiXmlElement*root = doc.FirstChildElement();

	if (root == NULL)
	{

		doc.Clear();
		return;
	}
	for (TiXmlElement*elem = root->FirstChildElement();elem != NULL;elem = elem->NextSiblingElement())
	{
		string elemName = elem->Value();
		if (elemName == "objectgroup")
		{
			string atribute;
			atribute = elem->Attribute("name");
			if (atribute.compare("GO_DOWN") == 0)
			{
				TYPE_DOWMN_H type_down;
				for (TiXmlElement* e = elem->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
				{

					string name = e->Attribute("name");
					if (name.compare("DOWN") == 0)
					{
						type_down = DOWN1;
					}
					else
					{
						type_down = UP1;
					}

					double _width = atof(e->Attribute("width"));
					double width = _width;
					double _height = atof(e->Attribute("height"));
					double height = _height;
					double x = atof(e->Attribute("x")) - 8;
					double y = 672.0f - atof(e->Attribute("y")) - _height - 1;
					DownH*down_h = new DownH(type_down, x, y, _width, _height);
					downlist.push_back(down_h);
				}
			}
		}
	}
}

ObjectsList* ObjectsList::getIntance()
{
	if(instance == NULL)
		instance = new ObjectsList();
	return instance;

}

