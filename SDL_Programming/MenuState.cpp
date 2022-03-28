#include "MenuState.h"
#include "PlayState.h"

bool MenuState::OnEnter()
{
	//Load assets for menu buttons
	//All Button Sprites
	m_buttonSprites.Load("Assets/Menu/MenuButtons2.png");
	m_buttonSprites.SetImageDimension(2, 13, 1200, 2600);
	m_buttonSprites.SetImageCel(2, 4);
	m_buttonSprites.SetSpriteDimension(150, 75);

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

	exitButtonPos.x = m_buttonSprites.GetSpritePositions().x;
	exitButtonPos.y = m_buttonSprites.GetSpritePositions().y;
	exitButtonPos.w = m_buttonSprites.GetSpritePositions().w;
	exitButtonPos.h = m_buttonSprites.GetSpritePositions().h;

	if (SDL_HasIntersection(&mousePos, &exitButtonPos))
	{
		isOver = true;
		m_buttonSprites.SetImageCel(1, 4);
		std::cout << "Mouse is Colliding" << std::endl;
	}
	else
	{
		isOver = false;
		m_buttonSprites.SetImageCel(2, 4);
	}

	if (isOver && Input::Instance()->IsMouseClicked())
	{
		return nullptr;
	}

	std::cout << mousePos.x << std::endl;
	std::cout << mousePos.y << std::endl;
	std::cout << isOver << std::endl;
	
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
	//if(isOver)
	//{ 
	//	m_buttonSprites.Render(565, 200, 0.0f);
	//}
	//else
	//{
	//	m_buttonSprites.Render(565, 200, 0.0f);
	//}
	m_buttonSprites.Render(565, 400, 0.0f);
	//render menu text

	return false;
}

void MenuState::OnExit()
{
	//unload all music, text, sprites for this state
	Game::GetMusic().Shutdown();
}