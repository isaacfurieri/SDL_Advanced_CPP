#include "GameState.h"

bool GameState::OnEnter()
{
	//Load Screen Asset
	//===========================================

	//Init music Asset
	//===========================================
	//Music::Initialize();

	//Music music;

	//music.Load("Assets/Music/background_music.mp3");
	//music.Play(Music::PlayLoop::PLAY_ENDLESS);
	//music.Load("Assets/Music/background_music.mp3");

	//===========================================
	//Init music system
	//===========================================


	return 1;
}

//GameState::GameState(Screen& screen) : m_screen(screen)
//{
//}

GameState* GameState::Update(Uint64 deltaTime)
{
	//Check keypress and mouse clicks
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
	return this;
}

bool GameState::Render()
{
	//Render player
	//render enemy
	//render ...
	//m_background.Render(Game::GetScreen());

	return true;
}

void GameState::OnExit()
{
	//unload all music, text, sprites for this state
}
