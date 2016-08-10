#include "StateMap1.h"



StateMap1::StateMap1()
{

}


StateMap1::~StateMap1()
{

}
void StateMap1::initState(LPDIRECT3DDEVICE9 d3ddv, FKeyboard* keyboad,Player*player)
{

	this->d3ddv = d3ddv;
	this->keyboad = keyboad;
	if (currentstate == 1)
	{
		test = new Sprite(d3ddv, L"Images\\Map\\Background\\down.png", 32, 32, 1, 1);
		test2 = new Sprite(d3ddv, L"Images\\Map\\Background\\test2.png", 32, 32, 1, 1);
		Background::getInstane()->initBackground(d3ddv, FILE_MAP_TXT, TILE_MAP_PNG, MAP1_XML);
		this->player = player;

		ObjectsManager::getInstance()->initObjectsManager(d3ddv, player);
		change_level = 0;
	}
	
	
	
	 

}
void StateMap1::updateState(float&vpx, float&vpy, float time)
{
	
	player->updatePlayer(keyboad, vpx, vpy, time);
	player->updateViewPort(&vpx, &vpy, time);
	Background::getInstane()->updateBackground(player);
	ObjectsManager::getInstance()->updateObjectsManager(d3ddv, player, time);
	ObjectsManager::getInstance()->colPlayer(vpx, vpy, player);
}
void StateMap1::renderState(float&vpx, float &vpy)
{
	Background::getInstane()->renderBackground(vpx, vpy);

	player->drawPlayer(vpx, vpy);
	test->renderSprite(2376, 178, vpx, vpy);
	test2->renderSprite(2376, 208, vpx, vpy);
	ObjectsManager::getInstance()->drawObjectsManager(vpx, vpy);
	
	
	
	
	
}
StateMap1* StateMap1::instance = NULL;
 StateMap1* StateMap1::getInstance()
{
	if (instance == NULL)
	{
		instance = new StateMap1();
	}
	return instance;
}
 void StateMap1::exitState()
 {

 }