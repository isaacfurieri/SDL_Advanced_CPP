#include "Game.h"

Text Game::m_text;
Sound Game::m_sound;

bool Game::Initialize()
{
	//===========================================
	//Init screen & Input
	//===========================================

	Screen::Instance();
	Input::Instance();

	//===========================================
	//Init music system
	//===========================================

	m_music.Initialize();
	m_music.SetVolume(50);

	if (!Screen::Instance()->Initialize("MageWar", 1280, 720))
	{
		return 0;
	}
	
	//===========================================
	//Init Text system
	//===========================================

	m_text.Initialize();

	//===========================================
	//Init third-party libraries
	//===========================================

	return true;
}

bool Game::Run(GameState* initialState)
{

	m_gameState.reset(initialState);
	m_gameState->OnEnter();

	while (m_gameState)  //will break if m_gameState == nullptr
	{
		auto start = SDL_GetPerformanceCounter();
		auto m_start = SDL_GetTicks();
		//clearing the screen
		Screen::Instance()->Clear();

		//updating the input
		Input::Instance()->Update();

		//updating the current game state
		//current game state will return a pointer to a different state if a switch is required 
		//If no switch is required then the current states pointer is returned
		GameState* nextState = m_gameState->Update();

		m_gameState->Render();

		//This will only run if a switch state is required
		if (nextState != m_gameState.get())
		{
			m_gameState->OnExit();
			m_gameState.reset(nextState);

			if (m_gameState)
			{
				m_gameState->OnEnter();
			}
		}
		Screen::Instance()->Present();
		auto end = SDL_GetPerformanceCounter();
		auto elapsed = (end - start) / (float)SDL_GetPerformanceFrequency();
		//std::cout << "Current FPS: " << (1.0f / elapsed) << std::endl;
	}

	return true;
}

void Game::Shutdown()
{
	//Close down everything you initialized in init()
	//Only call this once after the game has ended
	m_music.Shutdown();
	m_text.Unload();
	Screen::Instance()->Shutdown();
}