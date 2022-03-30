#include "MenuState.h"
#include "PlayState.h"

bool MenuState::OnEnter()
{

	//buttons.push_back(Button("Menu"));
	buttons.push_back(Button("Play"));
	//buttons.push_back(Button("Load"));
	buttons.push_back(Button("Options"));
	buttons.push_back(Button("Exit"));
	//buttons.push_back(Button("Resume"));
	
	/*for (auto button : buttons.size())
	{
		buttons[0].SetPosition(buttonPos);
		buttonPos.y = buttonPos.y + 100;
	}*/

	for (int i = 0; i < buttons.size(); i++)
	{
		buttons[i].SetPosition(buttonPos);
		buttonPos.y = buttonPos.y + 100;
	}
	//Load assets for menu buttons
	//All Button Sprites
	//m_buttonSprites.Load("Assets/Menu/MenuButtons2.png");
	//m_buttonSprites.SetImageDimension(2, 13, 1200, 2600);
	//m_buttonSprites.SetImageCel(2, 4);
	//m_buttonSprites.SetSpriteDimension(150, 75);

	//Load menu background music
	//Game::GetMusic().Initialize();

	Game::GetMusic().Load("Assets/Music/TheDevilTower.mp3");
	Game::GetMusic().SetVolume(15);
	Game::GetMusic().Play(Music::PlayLoop::PLAY_ENDLESS);
	//Load backdrop image
	//Load Music
	//m_isClickedMusic.Initialize();
	//m_isOverMusic.Initialize();

	return true;
}

GameState* MenuState::Update()
{

	for (int i = 0; i < buttons.size(); i++)
	{
		auto tag = buttons[i].GetTag();
		
		buttons[i].Update();
		buttons[i].Render();

		if (buttons[i].GetState() == Button::ButtonState::Hover)
		{
		}

		if (buttons[i].GetState() == Button::ButtonState::Clicked)
		{

			if (tag == "Play")
			{
				return new PlayState;
			}
			if (tag == "Exit")
			{
				return nullptr;
			}
		}
	}





	//if (SDL_HasIntersection(&mousePos, &exitButtonPos) && isOver == false)
	//{
	//	m_isOverMusic.Play(Music::PlayLoop::PLAY_ONCE);
	//	m_isOverMusic.Play(1);
	//	isOver = true;
	//	m_buttonSprites.SetImageCel(1, 4);
	//	std::cout << "Mouse is Colliding" << std::endl;
	//}
	//else if (!SDL_HasIntersection(&mousePos, &exitButtonPos))
	//{
	//	isOver = false;
	//	m_buttonSprites.SetImageCel(2, 4);
	//}

	//if (isOver && Input::Instance()->IsMouseClicked())
	//{
	//	//m_isClickedMusic.Play(Music::PlayLoop::PLAY_ONCE);
	//	m_isClickedMusic.Play(1);
	//	Sleep(2500);
	//	return nullptr;
	//}
	
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
	//m_buttonSprites.Render(565, 400, 0.0f);
	//render menu text

	return false;
}

void MenuState::OnExit()
{
	//unload all music, text, sprites for this state
	Game::GetMusic().Shutdown();
	//m_isClickedMusic.Unload();
	//m_isOverMusic.Unload();
}