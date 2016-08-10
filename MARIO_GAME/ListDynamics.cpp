#include "ListDynamics.h"
ListDynamics::ListDynamics()
{
}


ListDynamics::~ListDynamics()
{
}
list<Mushroom> ListDynamics::readMushroom()
{
	list<Mushroom>listmush;
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
			if (atribute == "MUSHROOM")
			{
				for (TiXmlElement* e = elem->FirstChildElement("object"); e != NULL; e = e->NextSiblingElement("object"))
				{
					double _width = atof(e->Attribute("width"));
					double width = _width;
					double _height = atof(e->Attribute("height"));
					double height = _height;
					double x = atof(e->Attribute("x")) - NOMAL_SIZE / 2;
					double y = 448.0f - atof(e->Attribute("y")) - NOMAL_SIZE / 2;
					Mushroom mush = Mushroom(x, y, width, height);
					listmush.push_back(mush);
				}
			}
		}
	}
	return listmush;
	
}
