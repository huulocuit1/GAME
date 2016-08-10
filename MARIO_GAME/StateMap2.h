#pragma once
#include "State.h"
extern int currentstate;
extern int playerlife;
extern int score;
extern int changelevel;

class StateMap2:public StateMap
{
public:
	StateMap2();
	~StateMap2();
	void initState(LPDIRECT3DDEVICE9 d3ddv, FKeyboard* keyboad,Player*player);
	void updateState(float&vpx, float&vpy, float time);
	void renderState(float&vpx, float &vpy);
	void exitState();
};

