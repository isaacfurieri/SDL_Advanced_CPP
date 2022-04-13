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

class Game
{

public:

	bool Initialize();
	bool Run(GameState* initialState);
	void Shutdown();

	static Music& GetMusic()
	{
		return m_music;
	}
	static Sound& GetSound()
	{
		return m_sound;
	}

private:

	static Music m_music;
	static Sound m_sound;
	std::unique_ptr<GameState> m_gameState;
};