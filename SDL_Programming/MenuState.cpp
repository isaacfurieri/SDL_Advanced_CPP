#include "MenuState.h"
#include "PlayState.h"

bool MenuState::OnEnter()
{
	//Load assets for menu buttons
	//Load menu background music
	//Load backdrop image
	return true;
}

GameState* MenuState::Update()
{
	//Check keypress and mouse clicks
	//check if buttons are clicked on
	//check if user scrolls up or down a menu
	/*
	if (userClicksPlayGameButton)
	{
		return new PlayState;
	}

	if (userClicksExitGameButton)
	{
		return nullptr;
	}
	*/
	return this;
}

bool MenuState::Render()
{
	//render all buttons
	//render menu text

	return false;
}

void MenuState::OnExit()
{
	//unload all music, text, sprites for this state

}