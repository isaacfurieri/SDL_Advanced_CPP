#include "MenuState.h"
#include "PlayState.h"

bool MenuState::OnEnter()
{
	//Load assets for menu buttons
	//Play Button
	m_image.Load("Assets/Menu/LargeButtons/LargeButtons/PlayButton.png");
	m_image.SetImageDimension(1, 1, 600, 200);
	m_image.SetSpriteDimension(150, 75);
	//Settings Button
	m_image.Load("Assets/Menu/LargeButtons/LargeButtons/SettingsButton.png");
	m_image.SetImageDimension(1, 1, 600, 200);
	m_image.SetSpriteDimension(150, 75);
	//New Game Button
	m_image.Load("Assets/Menu/LargeButtons/LargeButtons/NewgameButton.png");
	m_image.SetImageDimension(1, 1, 600, 200);
	m_image.SetSpriteDimension(150, 75);
	//Exit Button
	m_exitButton.Load("Assets/Menu/LargeButtons/LargeButtons/ExitButton.png");
	m_exitButton.SetImageDimension(1, 1, 600, 200);
	m_exitButton.SetSpriteDimension(150, 75);

	//Red Exit Button
	m_exitButtonRed.Load("Assets/Menu/LargeButtons/ColoredLargeButtons/Exitcol_Button.png");
	m_exitButtonRed.SetImageDimension(1, 1, 600, 200);
	m_exitButtonRed.SetSpriteDimension(150, 75);


	//Load menu background music
	Game::GetMusic().Initialize();

	Game::GetMusic().Load("Assets/Music/TheDevilTower.mp3");
	Game::GetMusic().Play(Music::PlayLoop::PLAY_ONCE);
	//Load backdrop image
	return true;
}

GameState* MenuState::Update()
{
	SDL_Rect mousePos, exitButtonPos;

	mousePos.x = Input::Instance()->GetMousePosition().x;
	mousePos.y = Input::Instance()->GetMousePosition().y;
	mousePos.w = 1;
	mousePos.h = 1;

	exitButtonPos.x = m_exitButton.GetSpritePositions().x;
	exitButtonPos.y = m_exitButton.GetSpritePositions().y;
	exitButtonPos.w = m_exitButton.GetSpritePositions().w;
	exitButtonPos.h = m_exitButton.GetSpritePositions().h;

	if (SDL_HasIntersection(&mousePos, &exitButtonPos))
	{
		isOver = true;
		std::cout << "Mouse is Colliding" << std::endl;
	}
	else
	{
		isOver = false;
	}

	std::cout << mousePos.x << std::endl;
	std::cout << mousePos.y << std::endl;
	
	//Check keypress and mouse clicks
	//check if buttons are clicked on
	//check if user scrolls up or down a menu
	/*
	if (userClicksPlayGameButton)
	{
		return new PlayState;
	}

	if (userClicksExitGameButton)
	Input::Instance()->
	{
		return nullptr;
	}
	*/
	return this;
}

bool MenuState::Render()
{
	//render all buttons
	if(isOver)
	{ 
		m_exitButtonRed.Render(565, 200, 0.0f);
	}
	else
	{
		m_exitButton.Render(565, 200, 0.0f);
	}

	//render menu text

	return false;
}

void MenuState::OnExit()
{
	//unload all music, text, sprites for this state
	Game::GetMusic().Shutdown();
}