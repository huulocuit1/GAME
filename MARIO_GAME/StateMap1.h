#pragma once
#include "State.h"

extern int currentstate;
extern int playerlife;
extern int score;
extern int changelevel;

class StateMap1:public StateMap
{
private :
	static StateMap1*instance;
	Sprite*test;
	Sprite*test2;
	int change_level;
public:
	StateMap1();
	~StateMap1();
	void initState(LPDIRECT3DDEVICE9 d3ddv, FKeyboard* keyboad,Player*player);
	void updateState(float&vpx, float&vpy, float time);
	void renderState(float&vpx, float &vpy);
	void exitState();
	static StateMap1* getInstance();
};

