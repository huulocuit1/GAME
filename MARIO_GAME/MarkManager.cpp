#include "MarkManager.h"



MarkManager::MarkManager(LPDIRECT3DDEVICE9 d3ddv)
{
	if (currentstate == 1)
	{


		ObjectsList::getIntance()->readListMark(MAP1_XML, marklist);
		ObjectsList::getIntance()->readListCoin(MAP1_XML, coinlist);
		ObjectsList::getIntance()->readlistBrick(MAP1_XML, bricklist);
		ObjectsList::getIntance()->readListWorld(MAP1_XML, worldlist);
		ObjectsList::getIntance()->readMushrunnerList(MAP1_XML, mushrunnerlist);
		ObjectsList::getIntance()->readButtonPList(MAP1_XML, buttonlist);
		for (int i = 0;i < mushrunnerlist.size();i++)
		{
			mushrunnerlist[i]->initMushRunner(d3ddv);
			if (i == 0)
			{
				mushrunnerlist[i]->setIsMush(true);
			}
			else
			{
				mushrunnerlist[i]->setIsMush(false);

			}

		}
		for (int i = 0;i < marklist.size();i++)
		{
			marklist[i]->initMark(d3ddv);
			if (i == 8)
			{
				marklist[i]->setStar(true);
			}


		}
		for (int i = 0;i < coinlist.size();i++)
		{
			coinlist[i]->initCoin(d3ddv);
		}
		for (int i = 0;i < bricklist.size();i++)
		{
			bricklist[i]->initBrick(d3ddv);
		}
		for (int i = 0;i < worldlist.size();i++)
		{
			worldlist[i]->initWorld(d3ddv);
		}
		for (int i = 0;i < buttonlist.size();i++)
		{
			buttonlist[i]->Init(d3ddv);
		}
	}
	else if (currentstate == 2)
	{
		

		ObjectsList::getIntance()->readListCoin(MAP2_XML, coinlist);
		ObjectsList::getIntance()->readListWorld(MAP1_XML, worldlist);
		ObjectsList::getIntance()->readListMark(MAP2_XML, marklist);
		ObjectsList::getIntance()->readlistBrick(MAP2_XML, bricklist);
		for (int i = 0;i < coinlist.size();i++)
		{
			coinlist[i]->initCoin(d3ddv);
		}
		for (int i = 0;i < worldlist.size();i++)
		{
			worldlist[i]->initWorld(d3ddv);
		}
		for (int i = 0;i < marklist.size();i++)
		{
			marklist[i]->initMark(d3ddv);
			if (i == 1)
			{
				marklist[i]->setStar(true);
			}


		}
		for (int i = 0;i < bricklist.size();i++)
		{
			bricklist[i]->initBrick(d3ddv);
		}
	}

	
}
MarkManager::MarkManager()
{

}

MarkManager::~MarkManager()
{
	
}
MarkManager* MarkManager::instance = NULL;
MarkManager*MarkManager::getinstance()
{
	if (instance == NULL)
	{
		instance = new MarkManager();
	}
	
	return instance;
}

void MarkManager::Update(LPDIRECT3DDEVICE9 d3ddv, Player*player,float time)
{
	if (currentstate == 1)
	{


		for (int i = 0;i < marklist.size();i++)
		{
			marklist[i]->updateMark(d3ddv, player);

		}

		for (int i = 0;i < coinlist.size();i++)
		{
			coinlist[i]->updateCoin(d3ddv, player, time);
		}
		for (int i = 0;i < bricklist.size();i++)
		{
			bricklist[i]->updateBrick(d3ddv, player, time);
		}
		for (int i = 0;i < worldlist.size();i++)
		{
			worldlist[i]->updateWorld(d3ddv, player, time);
		}
		for (int i = 0;i < mushrunnerlist.size();i++)
		{
			mushrunnerlist[i]->updateMushRunner(player, time);
		}
		for (int i = 0;i < buttonlist.size();i++)
		{
			buttonlist[i]->Update(player, time);
		}
	}
	else if (currentstate == 2)
	{
		for (int i = 0;i < coinlist.size();i++)
		{
			coinlist[i]->updateCoin(d3ddv, player, time);
		}
		for (int i = 0;i < worldlist.size();i++)
		{
			worldlist[i]->updateWorld(d3ddv, player, time);
		}
		for (int i = 0;i < marklist.size();i++)
		{
			marklist[i]->updateMark(d3ddv, player);

		}
		for (int i = 0;i < bricklist.size();i++)
		{
			bricklist[i]->updateBrick(d3ddv, player, time);
		}
	}

}
void MarkManager::Render(float vpx, float vpy)
{
	if (currentstate == 1)
	{


		for (int i = 0;i < mushrunnerlist.size();i++)
		{
			mushrunnerlist[i]->drawMushRunner(vpx, vpy);
		}
		for (int i = 0;i < marklist.size();i++)
		{

			marklist[i]->drawMark(vpx, vpy);
		}
		for (int i = 0;i < coinlist.size();i++)
		{
			coinlist[i]->drawCoin(vpx, vpy);
		}
		for (int i = 0;i < bricklist.size();i++)
		{
			bricklist[i]->drawBrick(vpx, vpy);
		}
		for (int i = 0;i < worldlist.size();i++)
		{
			worldlist[i]->drawWorld(vpx, vpy);
		}

		for (int i = 0;i < buttonlist.size();i++)
		{
			buttonlist[i]->Draw(vpx, vpy);
		}
	}
	else if (currentstate == 2)
	{
		for (int i = 0;i < coinlist.size();i++)
		{
			coinlist[i]->drawCoin(vpx, vpy);
		}
		for (int i = 0;i < worldlist.size();i++)
		{
			worldlist[i]->drawWorld(vpx, vpy);
		}
		for (int i = 0;i < marklist.size();i++)
		{

			marklist[i]->drawMark(vpx, vpy);
		}
		for (int i = 0;i < bricklist.size();i++)
		{
			bricklist[i]->drawBrick(vpx, vpy);
		}
	}

			
}
Marklist MarkManager::getmarklist()
{
	return marklist;
}
Coinlist MarkManager::getcoinlist()
{
	return this->coinlist;
}
Bricklist MarkManager::getbricklist()
{
	return this->bricklist;
}
MushRunnerlist MarkManager::getmushrunnerlist()
{
	return this->mushrunnerlist;
}
Buttonlist MarkManager::getbuttonList()
{
	return this->buttonlist;
}
