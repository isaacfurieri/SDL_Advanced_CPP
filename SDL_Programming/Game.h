#pragma once

#include <memory>
#include <iostream>
#include <string>
#include "GameState.h"
#include "Background.h"
#include "Coin.h"
#include "Enemy.h"
#include "Input.h"
#include "Music.h"
#include "Player.h"
#include "Score.h"
#include "Screen.h"
#include "Text.h"

class Game
{

public:

	//Game();
	bool Initialize();
	bool Run(GameState* initialState);
	void Shutdown();

	static Screen& GetScreen()
	{
		return m_screen;
	}

private:

	std::unique_ptr<GameState> m_gameState;
	std::unique_ptr<Background> m_background;

	static Screen m_screen;
	static Input m_input;
};