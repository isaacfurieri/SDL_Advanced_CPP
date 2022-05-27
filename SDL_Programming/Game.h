#pragma once

#include <memory>
#include <iostream>
#include <string>

#include "Background.h"
#include "GameState.h"
#include "Input.h"
#include "Music.h"
#include "Sound.h"
#include "Screen.h"
#include "Text.h"

class Game
{

public:

	bool Initialize();
	bool Run(GameState* initialState);
	void Shutdown();

	static Sound& GetSound()
	{
		return m_sound;
	}
	static Text& GetText()
	{
		return m_text;
	}
	//TODO SAVE MUSIC AND SOUND VOLUME IN TEXT;
	int m_soundVolume, m_musicVolume;

private:

	Music m_music;
	std::unique_ptr<GameState> m_gameState;
	static Sound m_sound;
	static Text m_text;
};