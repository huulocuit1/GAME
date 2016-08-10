#include "MarioGame.h"
#include <windows.h>




int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, INT)
{
	MarioGame::getInstance()->initGame(hInstance, TITLE_WINDOW, FRAME_RATE);
	MarioGame::getInstance()->runGame();
	MarioGame::getInstance()->isxit();

	return 0;
}