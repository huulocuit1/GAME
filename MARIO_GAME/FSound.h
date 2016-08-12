

#ifndef __SOUND_MANAGER__
#define __SOUND_MANAGER__

#include "dxaudio.h"
#include"Objects.h"
#include <map>
using namespace std;
class FSound
{
public:
	~FSound();
	static FSound* getInstance();
	void loadSound(HWND hWnd);
	void Play(eSoundId);
	void Stop(eSoundId);
	void PlayLoop(eSoundId);
	bool IsPlaying(eSoundId);
private:
	FSound();
	static FSound* _instance;
	map<eSoundId, CSound*> _listSound;
	CSound* currentSound;
	float volume;
};

#endif // !__SOUND_MANAGER__
