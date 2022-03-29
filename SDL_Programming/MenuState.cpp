#include <windows.h>

#include "MenuState.h"
#include "PlayState.h"

bool MenuState::OnEnter()
{

	buttons.push_back(Button("Play"));
	buttons.push_back(Button("Exit"));
	buttons.push_back(Button("Load"));
	buttons.push_back(Button("Menu"));
	buttons.push_back(Button("Options"));
	buttons.push_back(Button("Resume"));

	for (auto button : buttons)
	{
		button.Update();
		button.Render();

		if (button.GetState() == Button::ButtonState::Clicked)
		{
			auto tag = button.GetTag();

			if (tag == "Play")
			{
				//..play
			}
		}
	}
	//Load assets for menu buttons
	//All Button Sprites
	//m_buttonSprites.Load("Assets/Menu/MenuButtons2.png");
	//m_buttonSprites.SetImageDimension(2, 13, 1200, 2600);
	//m_buttonSprites.SetImageCel(2, 4);
	//m_buttonSprites.SetSpriteDimension(150, 75);

	//Load menu background music
	//Game::GetMusic().Initialize();

	//Game::GetMusic().Load("Assets/Music/TheDevilTower.mp3");
	//Game::GetMusic().Play(Music::PlayLoop::PLAY_ENDLESS);
	//Load backdrop image
	//Load Music
	//m_isClickedMusic.Initialize();
	//m_isOverMusic.Initialize();

	m_isClickedMusic.Load("Assets/Music/GUI_Sounds/GUI_Button_Clicked_Sound_Effects.wav");
	m_isOverMusic.Load("Assets/Music/GUI_Sounds/GUI_Button_Over_Sound_Effects3.wav");

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

	if (SDL_HasIntersection(&mousePos, &exitButtonPos) && isOver == false)
	{
		m_isOverMusic.Play(Music::PlayLoop::PLAY_ONCE);
		isOver = true;
		m_buttonSprites.SetImageCel(1, 4);
		std::cout << "Mouse is Colliding" << std::endl;
	}
	else if (!SDL_HasIntersection(&mousePos, &exitButtonPos))
	{
		isOver = false;
		m_buttonSprites.SetImageCel(2, 4);
	}

	if (isOver && Input::Instance()->IsMouseClicked())
	{
		m_isClickedMusic.Play(Music::PlayLoop::PLAY_ONCE);
		Sleep(2500);
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
	//Game::GetMusic().Shutdown();
	m_isClickedMusic.Shutdown();
	m_isOverMusic.Shutdown();
}