#include <iostream>
#include "Sound.h"

Sound::Sound()
{
	m_sound = nullptr;
}

bool Sound::Load(const std::string& filename)
{
	m_sound = Mix_LoadWAV(filename.c_str());

	if (!m_sound)
	{
		std::cout << Mix_GetError() << std::endl;
		std::cout << "Error loading audio file." << std::endl;
		return false;
	}
	return false;
}

void Sound::Unload()
{
	Mix_FreeChunk(m_sound);
}

void Sound::SetVolume(int volume)
{
	Mix_VolumeChunk(m_sound, volume); //0 - 128
}

void Sound::Play(int loop)
{
	if (!Mix_PlayChannel(-1, m_sound, loop)) 
	{
		std::cout << Mix_GetError() << std::endl;
		std::cout << "Error playing audio file." << std::endl;
	}
}
