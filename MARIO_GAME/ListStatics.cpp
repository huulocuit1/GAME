#include "ListStatics.h"

ListStatics::ListStatics()
{

}

ListStatics::~ListStatics()
{
}
void ListStatics::readStaticObjects()
{
	TiXmlDocument doc;
	if (!doc.LoadFile("Images\\Map\\Background\\mapmario.tmx"))
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
			if (atribute.compare("ROAD") == 0)
			{
				for (TiXmlElement* e = elem->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
				{
					double _width = atof(e->Attribute("width"));
					double width = _width;
					double _height = atof(e->Attribute("height"));
					double height = _height;
					double x = atof(e->Attribute("x")) - 7.0f;
					double y = 448.0f - atof(e->Attribute("y")) -_height;
					Box box(x, y, width, height);
					this->listRoad.push_back(box);

				}
			}
			if (atribute.compare("ROAD_X") == 0)
			{
				for (TiXmlElement* e = elem->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
				{
					double _width = atof(e->Attribute("width"));
					double width = _width;
					double _height = atof(e->Attribute("height"));
					double height = _height;
					double x = atof(e->Attribute("x")) - 6.0f;
					double y = 448.0f - atof(e->Attribute("y")) - _height/2;
					
					this->Road2= Box (x, y, width, height);

				}
			}
			if (atribute.compare("ROAD_Y") == 0)
			{
				for (TiXmlElement* e = elem->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
				{
					double _width = atof(e->Attribute("width"));
					double width = _width;
					double _height = atof(e->Attribute("height"));
					double height = _height;
					double x = atof(e->Attribute("x")) - 7.5f;
					double y = 448.0f - atof(e->Attribute("y")) - NOMAL_SIZE / 2;

					this->Road2_y = Box(x, y, width, height);

				}
			}
			if (atribute.compare("RECT") == 0)
			{
				for (TiXmlElement* e = elem->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
				{



					double _width = atof(e->Attribute("width"));
					double width = _width;
					double _height = atof(e->Attribute("height"));
					double height = _height;
					double x = atof(e->Attribute("x")) - NOMAL_SIZE / 2;
					double y = 448.0f - atof(e->Attribute("y")) - NOMAL_SIZE / 2;
					Box box(x, y, width, height);
					this->listRect.push_back(box);


				}
			}
			if (atribute.compare("TUBE") == 0)
			{
				for (TiXmlElement* e = elem->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
				{



					double _width = atof(e->Attribute("width"));
					double width = _width;
					double _height = atof(e->Attribute("height"));
					double height = _height;
					double x = atof(e->Attribute("x")) - 7.5f;
					double y = 448.0f - atof(e->Attribute("y")) - NOMAL_SIZE/2;
					Box box(x, y, width, height);
					this->listTube.push_back(box);


				}


			}
			if (atribute.compare("TUBE_X") == 0)
			{
				for (TiXmlElement* e = elem->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
				{



					double _width = atof(e->Attribute("width"));
					double width = _width;
					double _height = atof(e->Attribute("height"));
					double height = _height;
					double x = atof(e->Attribute("x")) - NOMAL_SIZE / 2;
					double y = 448.0f - atof(e->Attribute("y")) - NOMAL_SIZE / 2;
					Box box(x, y, width, height);
					this->listTube_x.push_back(box);


				}


			}
			
		}



	}

}

list<Mark> ListStatics::readlistMark()
{
	list<Mark>listmarks;
	TiXmlDocument doc;
	doc.LoadFile("Images\\Map\\Background\\mapmario.tmx");
	TiXmlElement*root = doc.FirstChildElement();

	
	for (TiXmlElement*elem = root->FirstChildElement();elem != NULL;elem = elem->NextSiblingElement())
	{
		string elemName = elem->Value();
		if (elemName == "objectgroup")
		{
			string atribute;
			atribute = elem->Attribute("name");
			if (atribute == "MARK")
			{
				for (TiXmlElement* e = elem->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
				{
					double _width = atof(e->Attribute("width"));
					double width = _width;
					double _height = atof(e->Attribute("height"));
					double height = _height;
					double x = atof(e->Attribute("x")) - NOMAL_SIZE / 2;
					double y = 448.0f - atof(e->Attribute("y")) - NOMAL_SIZE / 2;
					Mark  mark = Mark(x,y,_width,_height);
					listmarks.push_back(mark);
				}
			}
		}
	}
	return listmarks;

}
list<Box> ListStatics::getlistRoads()
{
	return this->listRoad;
}
list<Box>ListStatics::getlistRects()
{
	return this->listRect;
}
list<Box>ListStatics::getlistTubes()
{
	return this->listTube;
}
list<Box>ListStatics::getlistTube_xs()
{
	return this->listTube_x;
}