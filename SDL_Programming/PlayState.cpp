#include "PlayState.h"
#include "MenuState.h"

bool PlayState::OnEnter()
{
	m_player.IsVisible(true);
	m_player.SetPosition(100, 200);
	m_player.SetAngle(0.0);
	m_player.SetSize(60, 100);
	m_player.SetVelocity(5);
	//Load assets for player and enemy
	//Load all music for game 
	Game::GetMusic().Load("Assets/Music/background_music.mp3");
	Game::GetMusic().Play(Music::PlayLoop::PLAY_ENDLESS);
	//Load images and fonts
	return true;
}

GameState* PlayState::Update(Uint64 deltaTime)
{
	//auto screen = Game::GetScreen();
	auto input = Input::Instance();
	//Check keypress and mouse clicks
	m_background.Update();
	m_player.Update( deltaTime);
	//check if buttons are clicked on
	//All main game mechanics are updated here
	/*
	if (userWishesToExitGame)
	{
		return new MenuState;
	}

	if (userWishesToPause)
	{
		return new PauseState;
	}
	*/
	
	//If user press ESC > EXIT GAME
	if (input->IsKeyPressed(HM_KEY_ESCAPE))
	{
		return new MenuState;
	}

	return this;
}

bool PlayState::Render()
{
	//render background
	m_background.Render();
	
	//Render player
	if (m_player.IsVisible())
	{
		m_player.Render();
	}
	//render enemy
	//render ...

	return true;
}

void PlayState::OnExit()
{
	//unload all music, text, sprites for this state
	Game::GetMusic().Unload();
	m_player.~Player();
	m_background.~Background();
}