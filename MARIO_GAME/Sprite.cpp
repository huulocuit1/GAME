#include "Sprite.h"



Sprite::Sprite(LPDIRECT3DDEVICE9 D3ddv, LPWSTR FilePath, int Width, int Height, int Count, int SpritePerRow)
{
	d3ddv = D3ddv;
	D3DXCreateSprite(d3ddv, &spritehandler);

	D3DXIMAGE_INFO info;
	HRESULT result;

	image = NULL;
	backLoop = false;

	width = Width;
	height = Height;
	count = Count;
	spritePerRow = SpritePerRow;
	index = 0;

	D3DXGetImageInfoFromFile(FilePath, &info);

	LPDIRECT3DDEVICE9 d3ddv;
	spritehandler->GetDevice(&d3ddv);

	result = D3DXCreateTextureFromFileEx(
		d3ddv,
		FilePath,
		info.Width,
		info.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(0, 63, 63),
		&info,
		NULL,
		&image);
}

Sprite::~Sprite()
{
	image->Release();
}

void Sprite::renderSprite(float X, float Y, float vpx, float vpy)

{
	RECT srect;

	srect.left = (index % spritePerRow)*(width);
	srect.top = (index / spritePerRow)*(height);
	srect.right = srect.left + width;
	srect.bottom = srect.top + height;

	D3DXVECTOR3 position((float)X, (float)Y, 0);

	D3DXMATRIX mt;
	D3DXMatrixIdentity(&mt);
	mt._22 = -1.0f;
	mt._41 = -vpx;
	mt._42 = vpy;
	D3DXVECTOR4 vp_pos;
	D3DXVec3Transform(&vp_pos, &position, &mt);

	D3DXVECTOR3 p((int)vp_pos.x, (int)vp_pos.y, 0);
	D3DXVECTOR3 center((float)width/2 , (float)height/2, 0);

	spritehandler->Begin(D3DXSPRITE_ALPHABLEND);
	spritehandler->Draw(
		image,
		&srect,
		&center,
		&p,
		D3DCOLOR_XRGB(255, 255, 255)
		);
	spritehandler->End();
}

void Sprite::nextSprite()
{
	index = (index + count - 1) % count;
}

void Sprite::nextEnd()
{
	if (index < count)index++;
}



void Sprite::nextRepeat()
{
	index++;
	if (index == count)
	{
		index = 0;
	}
}

void Sprite::resetSprite()
{
	index = 0;
}

void Sprite::setIndex(int n)
{
	index = n;
}

int Sprite::getIndex()
{
	return index;
}

