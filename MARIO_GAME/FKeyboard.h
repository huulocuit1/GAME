#pragma once
#ifndef _FKeyboard_H_
#define _FKeyboard_H_
#include <dinput.h>
#include "Config.h"

class FKeyboard
{
private:
	HWND hWnd;
	HINSTANCE hInstance;
	LPDIRECTINPUT8 dinput8;
	LPDIRECTINPUTDEVICE8 ddevinput8;
	DIDEVICEOBJECTDATA keyevents[1024];
	BYTE keystates[256];
	
public:
	FKeyboard();
	FKeyboard(HINSTANCE, HWND);
	void updateKeyboard();
	bool isKeyDown(BYTE keycode);
	bool isKeyUp(BYTE keycode);
	~FKeyboard();
};
#endif

