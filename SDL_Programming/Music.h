#pragma once
#include <string>
#include <SDL_mixer.h>

class Music
{

public:

	enum class PlayLoop { PLAY_ONCE = 1, PLAY_ENDLESS = -1 };
	static bool Initialize();
	static void Shutdown();

	Music();
	bool Load(const std::string& filename);
	void Unload();

	void SetVolume(int volume);
	void Play(PlayLoop);
	void Pause();
	void Resume();
	void Stop();

private:

	Mix_Music* m_music;

};

