#include "EnemyManager.h"



EnemyManager::EnemyManager(LPDIRECT3DDEVICE9 d3ddv)
{
	
	if (currentstate == 1)
	{

		this->mushroomlist = Mushroomlist();

		butlet = new Butlet();
		butlet->initButlet(d3ddv);
		

		ObjectsList::getIntance()->readMushRoom(MAP1_XML, mushroomlist);
		ObjectsList::getIntance()->readlistFlower(MAP1_XML, flowerlist);
		ObjectsList::getIntance()->readlistTurtle(MAP1_XML, turtle_normal_list);
		for (int i = 0;i < mushroomlist.size();i++)
		{
			mushroomlist[i]->initMushroom(d3ddv);
		}
		for (int i = 0;i < flowerlist.size();i++)
		{
			flowerlist[i]->initFlower(d3ddv);
			if (i == 0)
			{
				flowerlist[i]->setIndexFlower(0);

			}
			else if (i == 1)
			{
				flowerlist[i]->setIndexFlower(1);
			}
			else if (i == 2)
			{
				flowerlist[i]->setIndexFlower(2);
			}


		}
		for (int i = 0;i < turtle_normal_list.size();i++)
		{
			turtle_normal_list[i]->initTurtleNormal(d3ddv);
		}
	}
	else if (currentstate == 2)
	{

		for (int i = 0;i < mushroomlist.size();i++)
		{
			delete mushroomlist[i];
			
		}
		for (int i = 0;i < flowerlist.size();i++)
		{
			delete flowerlist[i];
			

		}
		
		this->mushroomlist = Mushroomlist();
		butlet = new Butlet();
		butlet->initButlet(d3ddv);
		ObjectsList::getIntance()->readMushRoom(MAP2_XML, mushroomlist);
		ObjectsList::getIntance()->readlistFlower(MAP2_XML, flowerlist);
		for (int i = 0;i < mushroomlist.size();i++)
		{
			mushroomlist[i]->initMushroom(d3ddv);
		}
		for (int i = 0;i < flowerlist.size();i++)
		{
			flowerlist[i]->initFlower(d3ddv);
			if (i == 0)
			{
				flowerlist[i]->setIndexFlower(0);

			}
			else if (i == 1)
			{
				flowerlist[i]->setIndexFlower(1);
			}
			else if (i == 2)
			{
				flowerlist[i]->setIndexFlower(2);
			}


		}
	}
	
	
	
}


EnemyManager::~EnemyManager()
{
}
void EnemyManager::updateEnemyManager(Player*player, float time)
{
	if (currentstate == 1)
	{


		for (int i = 0;i < mushroomlist.size();i++)
		{
			mushroomlist[i]->updateMushroom(player, time);
		}
		butlet->updateButlet(player, time);
		for (int i = 0;i < flowerlist.size();i++)
		{
			flowerlist[i]->updateFlower(player, time, butlet);

		}
		for (int i = 0;i < turtle_normal_list.size();i++)
		{
			turtle_normal_list[i]->updateTurtleNormal(player, time);
		}
	}
	else if (currentstate == 2)
	{
		for (int i = 0;i < mushroomlist.size();i++)
		{
			mushroomlist[i]->updateMushroom(player, time);
		}
		butlet->updateButlet(player, time);
		for (int i = 0;i < flowerlist.size();i++)
		{
			flowerlist[i]->updateFlower(player, time, butlet);

		}
	}
	
	
	
	
}
void EnemyManager::renderEnemyManager(float vpx, float vpy)
{
	if (currentstate == 1)
	{


		for (int i = 0;i < mushroomlist.size();i++)
		{
			mushroomlist[i]->drawMushroom(vpx, vpy);


		}
		butlet->drawButlet(vpx, vpy);
		for (int i = 0;i < flowerlist.size();i++)
		{
			flowerlist[i]->drawFlower(vpx, vpy);


		}
		for (int i = 0;i < turtle_normal_list.size();i++)
		{
			turtle_normal_list[i]->drawTurtleNormal(vpx, vpy);

		}
	}
	else if(currentstate==2)
	{
		for (int i = 0;i < mushroomlist.size();i++)
		{
			mushroomlist[i]->drawMushroom(vpx, vpy);
		}
		butlet->drawButlet(vpx, vpy);
		for (int i = 0;i < flowerlist.size();i++)
		{
			flowerlist[i]->drawFlower(vpx, vpy);


		}
	}

	
	
	
	
}
