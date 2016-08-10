#include "ObjectsManager.h"
ObjectsManager* ObjectsManager::instance;


ObjectsManager::ObjectsManager()
{

}


ObjectsManager::~ObjectsManager()
{
	delete enemymananger;
	delete markmanager;
	delete colision;
}
void ObjectsManager::initObjectsManager(LPDIRECT3DDEVICE9 d3ddv, Player*player)
{
	
	
		tube = new Sprite(d3ddv, L"Images\\Tube\\tube.png", 32, 48, 1, 1);
		tube2 = new Sprite(d3ddv, L"Images\\Tube\\tube2.png", 32, 32, 1, 1);

		this->enemymananger = new EnemyManager(d3ddv);
		this->markmanager = new MarkManager(d3ddv);


		colision = new Colision(enemymananger, markmanager, player);
	


}

void ObjectsManager::updateObjectsManager(LPDIRECT3DDEVICE9 d3ddv, Player* player, float time)
{

	this->enemymananger->updateEnemyManager(player, time);
	this->markmanager->Update(d3ddv, player, time);




}
void ObjectsManager::drawObjectsManager(float vpx, float vpy)
{
	
	this->enemymananger->renderEnemyManager(vpx, vpy);
	if (currentstate == 1)
	{
		tube->renderSprite(376, 264, vpx, vpy);
		tube->renderSprite(1912, 264, vpx, vpy);
		tube2->renderSprite(1848, 256, vpx, vpy);
	}
	
	this->markmanager->Render(vpx, vpy);


}

void ObjectsManager::colPlayer(float vpx, float vpy, Player*player)
{
	colision->checkCollison(vpx, vpy, player);


}


