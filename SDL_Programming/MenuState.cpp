#include "MenuState.h"
#include "PlayState.h"

bool MenuState::OnEnter()
{
	//Load assets for menu buttons
		//Play Button
	m_image.Load("Assets/Menu/LargeButtons/LargeButtons/PlayButton.png", Screen::Instance());
	m_image.SetImageDimension(1, 1, 600, 200);
	m_image.SetSpriteDimension(150, 75);
		//Settings Button
	m_image.Load("Assets/Menu/LargeButtons/LargeButtons/SettingsButton.png", Screen::Instance());
	m_image.SetImageDimension(1, 1, 600, 200);
	m_image.SetSpriteDimension(150, 75);
		//New Game Button
	m_image.Load("Assets/Menu/LargeButtons/LargeButtons/NewgameButton.png", Screen::Instance());
	m_image.SetImageDimension(1, 1, 600, 200);
	m_image.SetSpriteDimension(150, 75);
		//Exit Button
	m_image.Load("Assets/Menu/LargeButtons/LargeButtons/ExitButton.png", Screen::Instance());
	m_image.SetImageDimension(1, 1, 600, 200);
	m_image.SetSpriteDimension(150, 75);

	//Load menu background music
	Game::GetMusic().Load("Assets/Music/TheDevilTower.mp3");
	Game::GetMusic().Play(Music::PlayLoop::PLAY_ONCE);
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
	m_image.Render(565, 200, 0.0f, Screen::Instance());
	//render menu text

	return false;
}

void MenuState::OnExit()
{
	//unload all music, text, sprites for this state
	Game::GetMusic().Shutdown();
}