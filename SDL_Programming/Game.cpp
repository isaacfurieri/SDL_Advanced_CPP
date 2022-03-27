#include "Game.h"

//Screen Game::m_screen;
//Input Game::m_input;
Music Game::m_music;

bool Game::Initialize()
{
	//===========================================
	//Init screen 
	//===========================================
	Screen::Instance();
	Input::Instance();

	if (!Screen::Instance()->Initialize("Isaac", 1280, 720))
	{
		return 0;
	}

	//Music::Initialize(); //call once before any music object is loaded
	

	//===========================================
	//Init music system
	//===========================================
	
	m_music.Initialize();
	
	//===========================================
	//Init Font system
	//===========================================
	//Text::Initialize();

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
		//clearing the screen
		Screen::Instance()->Clear();

		//updating the input
		Input::Instance()->Update();
		//checking delta time

		//updating the current game state

		//current game state will return a pointer to a different state if a switch is required 
		//If no switch is required then the current states pointer is returned
		GameState* nextState = m_gameState->Update();

		m_gameState->Render();

		//This will only run if a switch is required
		if (nextState != m_gameState.get())
		{
			m_gameState->OnExit();
			m_gameState.reset(nextState);

			if (m_gameState)
			{
				m_gameState->OnEnter();
			}
		}

		//rendering the screen
		Screen::Instance()->Present();
	}

	return true;
}

void Game::Shutdown()
{
	//Close down everything you initialized in init()


	//delete score;

	//Only call this once after the game has ended
	Music::Shutdown();
	//Text::Shutdown();
	//m_background.Shutdown();

	Screen::Instance()->Shutdown();
}