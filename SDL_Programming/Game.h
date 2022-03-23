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

	//Game();
	bool Initialize();
	bool Run(GameState* initialState);
	void Shutdown();

	/*
	static Screen& GetScreen()
	{
		return m_screen;
	}

	static Input& GetInput()
	{
		return m_input;
	}*/

	static Music& GetMusic()
	{
		return m_music;
	}

private:

	std::unique_ptr<GameState> m_gameState;
	//std::unique_ptr<Background> m_background;

	static Music m_music;
	//static Screen m_screen;
	//static Input m_input;
};