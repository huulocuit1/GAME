#pragma once
#ifndef _FMARIO_GAME_
#define _FMARIO_GAME_

#include <d3d9.h>
#include <d3dx9.h>
#include <Windows.h>
#include "FKeyboard.h"
#include "Utils.h"
#include "Config.h"
#include "StateMap1.h"
#include "StateMap2.h"
#include "State.h"
#include "Player.h"


class MarioGame
{
private :
	static MarioGame*instances;
protected:
	LPDIRECT3D9 d3d;
	LPDIRECT3DDEVICE9 d3ddv;
	LPDIRECT3DSURFACE9 backBuffer;
	HWND hWnd;
	HINSTANCE hInstance;
	int frame_rate;
	float  DeltaTime;
	LPWSTR name;
	FKeyboard*keyboard;
	float vpx, vpy;
	StateMap*state;
	StateMap1 state_map1;
	StateMap2 state_map2;
	Player*player;

public:
	static LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	MarioGame();
	~MarioGame();
	static MarioGame*getInstance();
	void initWindow();
	void initDirectX();
	void initVariables();
	void viewportUpdate();	
	void initGame(HINSTANCE hinstance, LPWSTR name, int frame_rate );
	void runGame();

public :
	void updateGame(float time);
	void renderGame();
	void isxit();

};
#endif
