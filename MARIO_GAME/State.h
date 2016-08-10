#ifndef _STATE_H_
#define _STATE_H_


#include "Background.h"
#include "Objects.h"
#include "Player.h"
#include "FKeyboard.h"

#include "Butlet.h"

#include "ObjectsManager.h"
#include "Colision.h"


class StateMap
{
protected:
	LPDIRECT3DDEVICE9 d3ddv;
	FKeyboard* keyboad;

	Player*player;
	ObjectsList*objectlist;

	
public :
	virtual void initState(LPDIRECT3DDEVICE9 d3ddv, FKeyboard* keyboad,Player*player) {

	}
	virtual void updateState(float&vpx, float&vpy, float time)
	{

	}
	virtual void renderState(float&vpx, float &vpy) {

	}
	virtual void exitState() {

	}


	
};
#endif
