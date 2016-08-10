#pragma once
#include <d3d9.h>
#include <d3dx9.h>
class Sprite
{
protected:
	LPDIRECT3DTEXTURE9 image;				// The container of all the sprites
	LPDIRECT3DDEVICE9 d3ddv;
	LPD3DXSPRITE spritehandler;

	int index;								// Current sprite index
	int width;								// Sprite width
	int height;							// Sprite height
	int count;								// Number of sprites
	int spritePerRow;						// Number of sprites per row

	bool backLoop;
public:
	Sprite();
	Sprite::Sprite(LPDIRECT3DDEVICE9 d3ddv, LPWSTR filepath, int spritewidth, int spriteheight, int count, int spriteperrow);
	void nextSprite();
	void nextRepeat();
	void nextEnd();
	void resetSprite();
	void setIndex(int n);
	int getIndex();
	void renderSprite(float X, float Y, float vpx, float vpy);	~Sprite();
};

