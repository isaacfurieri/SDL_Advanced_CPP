#pragma once

#include <memory>
#include <iostream>
#include <string>

#include "Background.h"
#include "GameState.h"
#include "Input.h"
#include "Music.h"
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

private:

	static Music m_music;
	std::unique_ptr<GameState> m_gameState;
};