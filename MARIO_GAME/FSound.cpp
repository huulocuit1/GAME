
#include"Objects.h"
#include "FSound.h"

FSound* FSound::_instance;

FSound* FSound::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new FSound();
	}
	return _instance;
}

void FSound::loadSound(HWND hWnd)
{
	// Khởi tạo CSoundManager.	
	DirectSound_Init(hWnd);

	CSound* sound = nullptr;

	sound = LoadSound("Sounds//Jump.wav");
	_listSound[eSoundId::JUMP_SOUND] = sound;

	sound = LoadSound("Sounds//Eat_Coin.wav");
	_listSound[eSoundId::EAT_COIN] = sound;

	sound = LoadSound("Sounds//Mario_Die.wav");
	_listSound[eSoundId::DEAD] = sound;

	sound = LoadSound("Sounds//Power-up.wav");
	_listSound[eSoundId::POWER_UP] = sound;

	sound = LoadSound("Sounds//Lost_Life.wav");
	_listSound[eSoundId::LOST_LIFE] = sound;
}

bool FSound::IsPlaying(eSoundId soundid)
{
	auto sound = _listSound[soundid];
	if (sound != nullptr)
	{
		return sound->IsSoundPlaying();
	}
	return false;
}

void FSound::Play(eSoundId soundid)
{
	auto sound = _listSound[soundid];
	if (sound != nullptr)
	{
		PlaySound(sound);
		this->currentSound = sound;
	}
}
void FSound::PlayLoop(eSoundId soundid)
{
	auto sound = _listSound[soundid];
	if (sound != nullptr)
	{
		sound->Play(0, DSBPLAY_LOOPING);
	}
}
void FSound::Stop(eSoundId soundid)
{
	auto sound = _listSound[soundid];
	if (sound != nullptr)
	{
		StopSound(sound);
	}
}

FSound::FSound()
{
	currentSound = nullptr;
}

FSound::~FSound()
{
}