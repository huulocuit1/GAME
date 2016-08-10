#include "FKeyboard.h"



FKeyboard::FKeyboard()
{

}


FKeyboard::~FKeyboard()
{
	if (ddevinput8)
	{
		ddevinput8->Unacquire();
		ddevinput8->Release();
	}

	if (dinput8) dinput8->Release();
}
FKeyboard::FKeyboard(HINSTANCE hInstance, HWND hWnd)
{
	this->hWnd = hWnd;
	this->hInstance = hInstance;
	DirectInput8Create
		(
			hInstance,
			DIRECTINPUT_VERSION,
			IID_IDirectInput8, (VOID**)&dinput8, NULL
			);
	dinput8->CreateDevice(GUID_SysKeyboard, &ddevinput8, NULL);
	ddevinput8->SetDataFormat(&c_dfDIKeyboard);
	ddevinput8->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

	DIPROPDWORD dipdw;

	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = 1024;

	ddevinput8->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
	ddevinput8->Acquire();

	for (int i = 0; i < 256; i++)
	{
		keystates[i] = 0x00;
	}
}
bool FKeyboard::isKeyDown(BYTE keyCode)
{
	return (keystates[keyCode] & 0x80) > 0;
}

bool FKeyboard::isKeyUp(BYTE keyCode)
{
	return !((keystates[keyCode] & 0x80) > 0);
}
void FKeyboard::updateKeyboard()
{
	BYTE keys[256];
	ddevinput8->GetDeviceState(256, keys);
	for (int i = 0; i < 256; i++)
	{
		keystates[i] = keys[i];
	}
	if (isKeyDown(DIK_ESCAPE))
	{
		PostMessage(hWnd, WM_QUIT, 0, 0);
	}
}