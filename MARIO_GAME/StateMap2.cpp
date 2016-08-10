#include "StateMap2.h"



StateMap2::StateMap2()
{
}


StateMap2::~StateMap2()
{
}
void StateMap2::initState(LPDIRECT3DDEVICE9 d3ddv, FKeyboard* keyboad,Player*player)
{
	this->d3ddv = d3ddv;
	this->keyboad = keyboad;
	Background::getInstane()->initBackground(d3ddv, FILE_MAP2_TXT, TILE_MAP2_PNG, MAP2_XML);
	this->player = player;
	ObjectsManager::getInstance()->initObjectsManager(d3ddv, player);
	



}
void StateMap2::updateState(float&vpx, float&vpy, float time)
{
	if (player->getNumberLive() <=3)
	{


		player->updatePlayer(keyboad, vpx, vpy, time);
		player->updateViewPort(&vpx, &vpy, time);
		ObjectsManager::getInstance()->updateObjectsManager(d3ddv, player, time);
		ObjectsManager::getInstance()->colPlayer(vpx, vpy, player);
	}
	else
	{
		initState(d3ddv, keyboad,player);
	}


}
void StateMap2::renderState(float&vpx, float &vpy)
{
	if (player->getNumberLive() <= 3)
	{
		Background::getInstane()->renderBackground(vpx, vpy);
		player->drawPlayer(vpx, vpy);
		ObjectsManager::getInstance()->drawObjectsManager(vpx, vpy);
	}
}
void StateMap2::exitState()
{

}