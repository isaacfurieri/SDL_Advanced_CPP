#include "PlayState.h"
#include "MenuState.h"

bool PlayState::OnEnter()
{
	//Load assets for player and enemy
	//Load all music for game
	//Load images and fonts
	return true;
}

GameState* PlayState::Update()
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
	//auto screen = Game::GetScreen();

	return this;
}

bool PlayState::Render()
{
	//Render player
	//render enemy
	//render background
	m_background.Render(Game::GetScreen());
	//render ...

	return true;
}

void PlayState::OnExit()
{
	//unload all music, text, sprites for this state

}